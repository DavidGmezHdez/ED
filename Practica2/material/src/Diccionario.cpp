#include <iostream>
#include "vector_dinamico.h"
#include "Termino.h"
#include <string.h>
#include <Diccionario.h>


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

		for (int izda=0; izda<nterminos; izda++){
			for (i=nterminos-1 ; i>izda ; i--){
				if (strcmp(terminos[i].getPalabra(),T.getPalabra())<0){
					aux = terminos[i];
					terminos[i] = T;
					terminos[i-1] = aux;
				}
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
	}

	for (int j=0;j<nterminos;j++){
		if(strcmp(terminos[i].getPalabra()[0],final)==0)
			fin=j;
	}

	for(int i=inicio;i<fin;i++){
		diccionario.AniadirTermino[terminos[i]];
	}

	return diccionario;

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
}



bool EstaTerminoEnDiccionario(const Termino T){
	bool resultado=false;
	for(int i=0;i<nterminos || resultado;i++){
		if(terminos[i] == T)
			resultado = true;

	}
	return resultado;
}

friend int IndiceTerminoEnDiccionario(const Termino T){
	int indice=0;
	bool esta=false;
	for(int i=0;i<nterminos || esta;i++){
		if(terminos[i]==T)
			esta=true;
			indice=i;
	}
	return indice;
}