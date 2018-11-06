#include "Diccionario.h"


Diccionario::Diccionario(){
	terminos=Vector_Dinamico<Termino>(0);
	nterminos=0;
}

Diccionario::Diccionario(Vector_Dinamico<Termino> terminoss){
	terminos=terminoss;
	nterminos=terminoss.size();
}

Diccionario::Diccionario(const Diccionario &D){

	terminos=D.getTerminos();
}


Vector_Dinamico<string> Diccionario::getDefinicionesTermino(const Termino &T){
	int indice=0;
	if(EstaTerminoEnDiccionario(T)){
		indice = IndiceTerminoEnDiccionario(T);
		
	}	
	else{
		cerr<<"El termino no se encuentra en el diccionario";
	}

	return terminos[indice].getDefiniciones();
}

void Diccionario::AniadirTermino(Termino nuevo){
        bool encontrado=false;
        int posicion;
	nterminos++;
	terminos.resize(nterminos);
	
	for(int i=0; i<nterminos && !encontrado; i++){
            if(nuevo.getPalabra() < terminos[i].getPalabra()){
                posicion = i;
                encontrado = true;
            }
	}
        
        if(!encontrado){
            posicion = nterminos-1;
        }
        
        for(int i=nterminos-1; i>posicion; i--){
            terminos[i] = terminos[i-1];
        }
        
    terminos[posicion] = nuevo;
	}


void Diccionario::EliminarTermino(Termino &T){
	int indice;
	if (EstaTerminoEnDiccionario(T)){
		indice=IndiceTerminoEnDiccionario(T);
		for(int i=indice;i<nterminos;i++){
			terminos[i+1]=terminos[i];

		}
		nterminos--;
		terminos.resize(nterminos);

	}else
		cerr<<"El termino no se encuentra en el diccionario";
}



Diccionario Diccionario::filtroIntervalo(char inicial, char final){
	Diccionario diccionario;
	int inicio,fin;

	for (int i=0;i<nterminos;i++){
		if (terminos[i].getPalabra()[0]==inicial)
			inicio=i;
	}

	for (int j=inicio;j<nterminos;j++){
		if(terminos[j].getPalabra()[0]==final)
			fin=j;
	}

	for(int i=inicio;i<fin;i++){
		diccionario.AniadirTermino(terminos[i]);
	}

	return diccionario;

}

Diccionario Diccionario::filtroPalabra(string palabra){
	Diccionario diccionario;

	for(int i=0;i<nterminos;i++)
	{
		Termino aux;
		bool definicion=true;
		for (int j = 0; j < terminos[i].getnDefiniciones(); j++)
		{
			if (terminos[i].getDefinicionesIndice(j).find(palabra)!=string::npos)
			{
				aux.setPalabra(terminos[i].getPalabra());
				definicion = false;
			}
			aux.AniadirDefinicion(terminos[i].getDefinicionesIndice(j));
		}
		if (!definicion)
		{
			diccionario.AniadirTermino(aux);
		}
	}
return diccionario;
}

void Diccionario::Recuento(int &num_total, int &max_defs, float &promedio){
	num_total=max_defs=promedio=0;

	for(int i=0;i<nterminos;i++)
	{
		num_total+=terminos[i].getnDefiniciones();
		if(terminos[i].getnDefiniciones() > max_defs)
			max_defs = terminos[i].getnDefiniciones(); 
	}

	promedio = num_total / nterminos; 
}

Diccionario& Diccionario::operator=(const Diccionario & original)
{
	if(this!=&original)
	{
		this->terminos = original.terminos;
	}
	else
		cerr<<"Los diccionarios son los mismos"<<endl;

return *this;
}



bool Diccionario::EstaTerminoEnDiccionario(const Termino T){
	bool resultado=false;
	for(int i=0;i<nterminos || resultado;i++){
		if(terminos[i].getPalabra() == T.getPalabra())
			resultado = true;

	}
	return resultado;
}

int Diccionario::IndiceTerminoEnDiccionario(const Termino T){
	int indice=0;
	bool esta=false;
	for(int i=0;i<nterminos || esta;i++){
		if(EstaTerminoEnDiccionario(T)){
			esta=true;
			indice=i;
		}
		else
			cerr<<"No se encuentra el termino en el diccionario";
	}
	return indice;
}

Vector_Dinamico<string> Diccionario::getDefinicionesPalabra(string palabra){
    Vector_Dinamico<string> defs;
    bool encontrada=false;
    int indice=0;
    
    for(int i=0;i<terminos.size() || !encontrada;i++)
    {
        if(terminos[i].getPalabra()==palabra)
            encontrada=true;
            indice=i;
    }
    
    if(encontrada)
        defs=terminos[indice].getDefiniciones();

    return defs;
}








ostream& operator << (ostream &os, const Diccionario &p){
	for(int i=0;i <p.getnTerminos(); i++){
		for(int j=0;j<p.terminos[i].getnDefiniciones();j++){
			os << p.terminos[i].getPalabra()<<";";
            os << p.terminos[i].getDefinicionesIndice(j)<<endl;
		}
	}
	return os;
}

istream& operator >> (istream &is, Diccionario &p){
    string aux;
    string anterior = "\0";
    
    
    getline(is, aux, ';');
    do{
        Termino terminoaux;
        do{
            if(anterior == "\0" || aux != anterior){
                terminoaux.setPalabra(aux);
                anterior = aux;
                getline(is, aux, '\n');
                terminoaux.AniadirDefinicion(aux);
            }
            else{
                getline(is, aux, '\n');
                terminoaux.AniadirDefinicion(aux);
            }

            if(!is.eof())
                getline(is, aux, ';');
        }while(aux == anterior);

        p.AniadirTermino(terminoaux);
        
    }while(!is.eof());

return is;
}

