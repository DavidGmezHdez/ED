//David Gómez Hernández
//2ºB
//Cola_max_pila.h
#ifndef cola_max_pila_h
#define cola_max_pila_h
#include <iostream>
#include <stack>
using namespace std;
template<class T>

class Cola_max{
private:
	stack<T>pila;
	stack<T>pilaux;
	stack<T>pilamax;
	int posicion=0;
public:
	///@brief Constructor por defecto
	Cola_max();
	///@brief Constructor por parametros
	///@param 1 pila 1
	///@param 2 pila 2
	Cola_max(stack<T>pil1,stack<T>pil2,stack<T>pil3);
	///@brief pila 
	///@return pila principal
	inline stack<T>getPila() const{return pila;}
	///@brief pila auxiliar
	///@return pila auxiliar
	inline stack<T>getPilaux() const{return pilaux;}
	///@brief pila maximos
	///@return pila maximos
	inline stack<T>getPilamax() const{return pilamax;}
	///@brief constructor por copia
	///@param cola a copiar
	Cola_max(Cola_max &cola);
	///@brief Insertar elemento en la cola
	///@param elemento a instertar
	void poner(const T x);
	///@brief Eliminar elemento de la cola
	void quitar();
	///@brief Devuelve el primer elemento de la cola
	///@return T elemento
	T& frente();
	///@brief Devuelve el ultimo elemento de la cola
	///@return T elemento
	T& detras();
	///@brief Comparar si la cola se encuentra vacia
	///@brief Devuelve true si está vacia y false si no
	bool vacia();
	///@brief Ver el numero de elementos que tiene la cola
	///@return el numero de elementos
	int num_elementos();
	///@brief Devuelve el frente de la pila de maximos
	///@return T elemento
	T& maximo();
};
#include "Cola_max_pila.cpp"
#endif