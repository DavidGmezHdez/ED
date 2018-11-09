//David Gómez Hernández
//2ºB
//Cola_max_pila.h


#ifndef COLA_PILA_H
#define COLA_PILA_H
#include <iostream>
#include <stack>
template<typename T>
using namespace std;

class cola{
private:
	stack<T>pila;
	stack<T>pilaux;
	stack<T>pilamax;
public:
	///@brief Constructor por defecto
	cola();
	///@brief Constructor por parametros
	///@param 1 pila 1
	///@param 2 pila 2
	cola(stack<T>pil1,stack<T>pil2,stack<T>pil3);
	///@brief pila 
	///@return pila principal
	inline stack<T>getPila() const{return pila};
	///@brief pila auxiliar
	///@return pila auxiliar
	inline stack<T>getPilaux() const{return pilaux};
	///@brief pila maximos
	///@return pila maximos
	inline stack<T>getPilamax() const{return pilamax};
	///@brief constructor por copia
	///@param cola a copiar
	cola(cola &cola);
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
	///@brief Actualiza la pila de maximos
	///@param Elemento a insertar en toda la pila
	void actualizarMaximos(const T x);



};
#endif