#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
template <typename T>

/*CLASE VENTANA*/
class Ventana{
private:
	stack<T>pila1;
	stack<T>pila2;
	stack<T>pilaux;
public:
	//Constructor por defecto
	Ventana(){
		pila1=stack<T>();
		pila2=stack<T>();
		pilaux=stack<T>();
	}
	/*FUNCION INSERTAR
		- Inserta un elemento en la pila 1
	*/
	void Insertar(const T x){
		pila1.push(x);
	}

	/*FUNCION MOVER DERECHA
		- Mueve el elemento superior de la pila 1 a la pila 2
		- Solo lo hace si la pila 1 tiene elementos
	*/
	void moverDerecha(){

		if(pila1.size()>0){
			pila2.push(pila1.top());
			pila1.pop();
		}
		else
			cerr<<"La pila está vacía"<<endl;
	}

	/*FUNCION MOVER IZQUIERDA
		- Mueve el elemento superior de la pila 2 a la pila 1
		- Solo lo hace si la pila 2 tiene elementos
	*/
	void moverIzquierda(){
		if(pila2.size()>0){
			pila1.push(pila2.top());
			pila2.pop();
		}
		else
			cerr<<"La pila está vacía"<<endl;
	}
	
	/*FUNCION BORRAR ELEMENTO
		- Borra el elemento superior de la pila 1
	*/
	void borrarElemento(){
		pila1.pop();
	}
	
	/*FUNCION MOSTRAR ELEMENTOS
		- Muestra los elementos de la pila 1
	*/
	void getElementos(){
		while(!pila1.empty()){
			cout<<pila1.top();
			pilaux.push(pila1.top());
			pila1.pop();
		}
		cout<<endl;

		while(!pilaux.empty()){
			pila1.push(pilaux.top());
			pilaux.pop();
		}

	}


};


main(){
	Ventana<int> ventanal;
	for(int i=1;i<=5;i++){
		ventanal.Insertar(i);
	}

	//Mostramos los elementos de la ventana
	ventanal.getElementos();
	//Movemos 1 elemento a la derecha
	ventanal.moverDerecha();
	//Mostramos los elementos de nuevo, tiene que salir un elemento menos
	ventanal.getElementos();
	//Movemos el elemento que habiamos movido a la derecha de vuelta a la izquierda
	ventanal.moverIzquierda();
	//Volvemos a mostrar los elementos, esta vez nos tiene que mostrar todos los elementos
	ventanal.getElementos();

}













