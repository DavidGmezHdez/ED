#ifndef cola_max_vd_h
#define cola_max_vd_h
//David Gómez Hernández
//2ºB
//Cola_max_vd.h
#include <iostream>
#include <vector>
using namespace std;
template<class T>

class Cola_max{
private:
	vector<T>vectorelementos;
	vector<T>vectormax;
	int posicion=0;
public:
	///@brief Constructor por defecto
	Cola_max();
	///@brief Constructor por parametros
	///@param 1 vector 1
	///@param 2 vector 2
	Cola_max(vector<T>pil1,vector<T>pil2,vector<T>pil3);
	///@brief vector 
	///@return vector principal
	inline vector<T>getVectorElementos() const{return vectorelementos;}
	///@brief vector maximos
	///@return vector maximos
	inline vector<T>getVectorMax() const{return vectormax;}
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
	///@brief Comparar si la cola se encuentra vacia
	///@brief Devuelve true si está vacia y false si no
	bool vacia();
	///@brief Ver el numero de elementos que tiene la cola
	///@return el numero de elementos
	int num_elementos();
	///@brief Devuelve el frente de la vector de maximos
	///@return T elemento
	T& maximo();
};
#include "Cola_max_vd.cpp"
#endif