
#ifndef COLA_MAX_PILA_H
#define COLA_MAX_PILA_H
#include "Cola_max_pila.h"
using namespace std;

template <class T> 
Cola_max<T>::Cola_max(){
			pila=stack<T>();
			pilaux=stack<T>();
			pilamax=stack<T>();
		}

template <class T> 
Cola_max<T>::Cola_max(stack<T>pil1,stack<T>pil2,stack<T>pil3){
			pila=pil1;
			pilaux=pil2;
			pilamax=pil3;
		}
template <class T> 
Cola_max<T>::Cola_max(Cola_max &cola){
			pila=cola.getPila();
			pilaux=cola.getPilaux();
			pilamax=cola.getPilamax();
		}
template <class T> 
void Cola_max<T>::poner(const T x){
    T max;
    pila.push(x);
    
    if(pilamax.empty()){
        max = (int) 0;
    }
    
    else{
        max = (T) maximo();
    }
    
    if(x < (T) max){
        pilamax.push(x);
        posicion = pilamax.size() - 1;
    }
    
    else{
        while(pilamax.size() != posicion){
            pilamax.pop();
        }
        
        for(int i=pilamax.size(); i<pila.size(); i++){
            pilamax.push(x);
        }
}
}

 template <class T>
 void Cola_max<T>::quitar(){
     int contador=0;
        while(!pila.empty()){
            pilaux.push(pila.top());
            pila.pop();
	}

	pilaux.pop();

	while(!pilaux.empty()){
            pila.push(pilaux.top());
            pilaux.pop();
        }            
        pilamax.pop();
}

 template <class T> 
 T& Cola_max<T>::frente(){
	while(!pila.empty()){
            pilaux.push(pila.top());
            pila.pop();
	}

	T& elemento=pilaux.top();

	while(!pilaux.empty()){
            pila.push(pilaux.top());
            pilaux.pop();
	}
	
        return elemento;
}

 template <class T> 
 T& Cola_max<T>::detras(){
	return pila.top();
}

template <class T> 
bool Cola_max<T>::vacia(){
	return pila.empty();
}

template <class T> 
int Cola_max<T>::num_elementos(){
	return pila.size();
}

template <class T> 
T& Cola_max<T>::maximo(){
    return pilamax.top();
}
#endif