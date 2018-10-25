//Termino.h
//David Gómez Hernández
//2ºB
#include "vector_dinamico.h"

#include <iostream>
#include <cmath>
using namespace std;

#ifndef TERMINO_H
#define TERMINO_H

class Termino{

private:
	string palabra;
	Vector_Dinamico<string*>definiciones;
	int ndefiniciones;

public:
	///@brief Constructor por defecto
	Termino::Termino();
	///@brief Constructor por parametros
	///@param palabra que se le va a asignar
	///@param puntero a las definiciones que se les va a asignar
	///@param numero de definiciones
	Termino::Termino(string pala,string* sign);
	///@brief Constructor de copia
	///@param T es el termino del que se hace copia. No se modifica
	Termino::Termino(const Termino& T);
	///@brief palabra
	///@return devuelve la palabra del Termino
	inline string getPalabra() const{return palabra};
	///@brief definiciones
	///@return devuelve las definiciones
	inline string* getDefiniciones() const{return definiciones};
	///@brief numero de definiciones de la palabra
	///@return devuelve el numero de definiciones
	inline int getnDefiniciones() const{return ndefiniciones};
	///@brief Asigna la palabra al termino
	///@param Palabr la palabra a asignar
	void setPalabra(string Palabr);
	///@brief Asigna una definicion a la palabra
	///@param definicion a asignar
	void AniadirDefinicion(string definicion);
    ///@brief Operador de asignación
  	///@param original es el termino el cual se iguala. No se modifica
  	Termino & operator=(const Termino & original);

}

	friend ostream& operator <<(ostream &os, const Termino &p);
	friend istream& operator <<(istream &os, const Termino &p);


#endif


