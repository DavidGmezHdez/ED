//Diccionario.h
//David Gómez Hernández
//2ºB
#include <iostream>
#include "vector_dinamico.h"
#include "Termino.h"
#include <string>
#include <vector>
#include <Diccionario.h>


#include <iostream>
#include <cmath>
using namespace std;

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

class Diccionario{
private:
	Vector_Dinamico<Termino>terminos;
	int nterminos;
public:
	///@brief Constructor por defecto
	Diccionario::Diccionario();
	///@brief Constructor por parametros
	///@param Vector de terminos a asignar a los terminos del diccionario
	Diccionario::Diccionario(Vector_Dinamico<Termino> terminoss);
	///@brief Constructor por copia
	///@param D es el diccionario al que se le hace copia. No se modifica
	Diccionario::Diccionario(const Diccionario &D);
	///@brief Consultor del numero de terminos del diccionario
	///@return devuelve el numero de terminos
	inline int getnTerminos() const {return nterminos};
	///@brief Consultor de los terminos del diccionario
	///@return Devuelve los terminos del diccionario
	inline Vector_Dinamico<Termino> getTerminos() const{return terminos};
	///@brief Consultor de las definiciones de un termino
	///@return las definiciones del termino
	///@param Termino del cual se va a describir
	Vector_Dinamico<Termino> getDefinicionesTermino(const Termino &T);
	///@brief Añadir un nuevo termino al vector de terminos
	///@param Termino a añadir
	void AniadirTermino(const Termino &T);
	///@brief Eliminar un termino del vector de terminos
	///@param Termino a eliminar
	void EliminarTermino(const Termino &T);
	///@brief Dado un diccionario, el objetivo es obtener un subconjunto de
	///este diccionario que incluya únicamente los términos cuya palabra asociada esté en el
	///intervalo especificado por [carácter_inicio, carácter_fin]
	///@param letra inicial y letra final
	///@return subconjunto del diccionario
	Diccionario filtroIntervalo(char inicial, char final);
	///@brief Dado un diccionario, el objetivo es obtener un subconjunto
	///de este diccionario que incluya únicamente las palabras en cuya definición aparezca
	///la palabra clave. Si una palabra tiene varias definiciones, solo se devolverían como re-
	///sultado del filtrado por palabra clave aquellas definiciones relacionadas con la palabra
	///clave
	///@param Palabra a buscar en el diccionario
	///@return Subconjunto del diccionario
	Diccionario filtroPalabra(string palabra);
	///@brief Dado un diccionario, el objetivo es obtener el número total
	///de definiciones, el máximo de definiciones asociadas a una única palabra y el promedio
	///de definiciones por palabra
	///@param numero total de definiciones, numero maximo de definiciones y promedio de definiciones por palabra
	void Recuento(int &num_total, int &max_defs, float &promedio);
	///@brief Metodo para saber si se encuentra el termino en el diccionario
	///@param Termino a buscar
	///@return true si se encuentra y false si no
	bool EstaTerminoEnDiccionario(const Termino T);
	///@brief Metodo que devuelve la posicion en la que se encuentra el termino
	///@param Termino a buscar en el vector
	///@return Devuelve el indice
	int IndiceTerminoEnDiccionario(const Termino T);
}

	friend ostream& operator <<(ostream &os, const Diccionario &p);
	friend istream& operator >>(istream &is, const Diccionario &p);


