#include "Diccionario.h"


Diccionario::Diccionario(){
	terminos=Vector_Dinamico<Termino>(int 0);
	nterminos=0;
}

Diccionario::Diccionario(Vector_Dinamico<Termino> terminoss){
	terminos=terminoss;
	nterminos=terminoss.size();
}

Diccionario::Diccionario(const Diccionario &D){

	*this=D;
}


Vector_Dinamico<string> Diccionario::getDefinicionesTermino(const Termino &T){
	int indice=0;
	if (EstaTerminoEnDiccionario(T))
		indice = IndiceTerminoEnDiccionario(T);
		return terminos[indice].getDefiniciones();
	else
		cerr<<"El termino no se encuentra en el diccionario";
}

void Diccionario::AniadirTermino(const Termino &T){
	if(!EstaTerminoEnDiccionario(T)){
		nterminos++;
		terminos.resize(nterminos);
		Termino aux;

		for(int i=0; i<nterminos;i++ ){
			if(strcmp(terminos[i].getPalabra().c_str(),T.getPalabra().c_str()) > 0){
				for(int j=terminos[i].getNumDefiniciones()-1;j>i;j--){
					terminos[j]=terminos[j+1];
				}
			terminos[i]=T;
			}
		}
	}
	else
		cerr<<"Ya está aniadido el termino";
}

void Diccionario::EliminarTermino(const Termino &T){
	int indice;
	if (EstaTerminoEnDiccionario(T)){
		indice=IndiceTerminoEnDiccionario(T);
		terminos[i]=null;
		for(int j=indice;j<nterminos;j++){
			terminos[j+1]=terminos[j];

		}
		nterminos--;
		terminos.resize(nterminos)

	}else
		cerr<<"El termino no se encuentra en el diccionario";
}



Diccionario Diccionario::filtroIntervalo(char inicial, char final){
	Diccionario diccionario;
	int inicio,fin;

	for (int i=0;i<nterminos;i++){
		if (strcmp(terminos[i].getPalabra()[0],inicial)==0)
			inicio=i;
		else
			cerr<<"No se encuentra un termino que empiece por dicha letra";
	}

	for (int j=i;j<nterminos;j++){
		if(strcmp(terminos[j].getPalabra()[0],final)==0)
			fin=j;
		else
			cerr<<"No se encuentra un termino que empiece por dicha letra";
	}

	for(int i=inicio;i<fin;i++){
		diccionario.AniadirTermino[terminos[i]];
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
			if (terminos[i].getDefinicionesIndice(j).find(palabra)!=-1)
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
		if(terminos[i].getnDefiniciones > max_defs)
			max_defs = terminos[i].getnDefiniciones; 
	}

	promedio = num_total / nterminos; 
}

Termino & operator=(const Diccionario & original)
{
	if(this!=&original)
	{
		this->terminos = original.terminos;
		this->nterminos = original.nterminos;
	}
	else
		cerr<<"Los diccionarios son los mismos"<<endl;

return *this;
}



bool Diccionario::EstaTerminoEnDiccionario(const Termino T){
	bool resultado=false;
	for(int i=0;i<nterminos || resultado;i++){
		if(terminos[i] == T)
			resultado = true;

	}
	return resultado;
}

int Diccionario::IndiceTerminoEnDiccionario(const Termino T){
	int indice=0;
	bool esta=false;
	for(int i=0;i<nterminos || esta;i++){
		if(terminos[i]==T)
			esta=true;
			indice=i;
	}
	return indice;
}




ostream& operator<<(ostream &os, const Diccionario &p){
	for(int i=0;i<p.getnTerminos();i++){
		os<<p.getTerminos();
	}
	return os;
}

istream& operator>>(istream &is, const Diccionario &p){
	Termino tmp;

	while (is.eof()){
		is>>tmp;
		p.AniadirTermino(tmp);
	}

return is;

}
