//Termino.h
//David Gómez Hernández
//2ºB



#ifndef TERMINO_H
#define TERMINO_H

#include "Vector_Dinamico.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <string.h>
using namespace std;
class Termino{

private:
	string palabra;
	Vector_Dinamico<string> definiciones;
	int ndefiniciones;

public:
	///@brief Constructor por defecto
	Termino();
	///@brief Constructor por parametros
	///@param palabra que se le va a asignar
	///@param puntero a las definiciones que se les va a asignar
	///@param numero de definiciones
	Termino(string pala,Vector_Dinamico<string> def);
	///@brief Constructor de copia
	///@param T es el termino del que se hace copia. No se modifica
	Termino(const Termino& T);
	///@brief palabra
	///@return devuelve la palabra del Termino
	inline string getPalabra() const{return palabra;};
	///@brief definiciones
	///@return devuelve las definiciones
	inline Vector_Dinamico<string> getDefiniciones() const{return definiciones;};
	///@brief definiciones con indice
	///@return definicion del en la posicion n
	inline string getDefinicionesIndice(int n) const{return definiciones[n];};
	///@brief numero de definiciones de la palabra
	///@return devuelve el numero de definiciones
	inline int getnDefiniciones() const{return ndefiniciones;};
	///@brief Asigna la palabra al termino
	///@param Palabr la palabra a asignar
	void setPalabra(string Palabr);
	///@brief Asigna el numero de definiciones al termino
	///@param Numero de definiciones a asignar
	void setnDefiniciones(int n);
	///@brief Asigna una definicion a la palabra
	///@param definicion a asignar
	void AniadirDefinicion(string definicion);
    ///@brief Operador de asignación
  	///@param original es el termino el cual se iguala. No se modifica
  	Termino& operator=(const Termino & original);

};
#endif


