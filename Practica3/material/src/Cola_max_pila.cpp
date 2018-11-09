#include "Cola_max_pila.h"

cola::cola(){
			pila=stack<T>();
			pilaux=stack<T>();
			pilamax=stack<T>();
		}

cola::cola(stack<T>pil1,stack<T>pil2,stack<T>pil3){
			pila=pil1;
			pilaux=pil2;
			pilamax=pil3;
		}
cola::cola(cola &cola){
			pila=cola.getPila();
			pilaux=cola.getPilaux();
			pilamax=cola.getPilamax();
		}
void cola::frente(const T x){
	pila.push(x);
	if(pilamax.front()<x || pilamax.empty())
		pilamax.push(x);
	else
		pilamax.push(x);
		actualizarMaximos(x);
}

void cola::quitar(){
	int contador=0;
		bool encontrado=false;
		int tamanio=pila.size();
			while(encontrado){
				pilaux.push(pila.top());
				pila.pop();
				contador++;
				if(contador==tamanio)
					pila.pop();
					encontrado=true;
			}

			while(!pilaux.empty()){
				pila.push(pilaux.top());
				pilaux.pop();
			}
}

T& cola::frente(){
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

T& cola::detras(){
	return pila.top();
}

bool cola::vacia(){
	return pila.empty();
}

int cola::num_elementos(){
	return pila.size();
}

T& cola::maximo(){
	while(!pilamax.empty()){
				pilaux.push(pilamax.top());
				pilamax.pop();
			}

			T& elemento=pilaux.top();

			while(!pilaux.empty()){
				pilamax.push(pilaux.top());
				pilaux.pop();
			}
	return elemento;
}

void cola::actualizarMaximos(const T x){
	int contador=0;
	while(!pilamax.empty()){
		contador++;
		pilamax.pop();
	}

	while(contador!=0){
		pilamax.push(x)
		contador--;
	}
}