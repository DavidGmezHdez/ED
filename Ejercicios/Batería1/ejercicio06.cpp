#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
template <typename T>


class cola{
	private:
		stack<T>pila1;
		stack<T>pila2;

	public:
		cola(){
			pila1=stack<T>();
			pila2=stack<T>();
		}

		cola(stack<T>pil1,stack<T>pil2){
			pila1=pil1;
			pila2=pil2;
		}

		stack<T>getPila1(){
			return pila1;
		}
		
		stack<T>getPila2(){
			return pila2;
		}

		cola(cola &cola){
			pila1=cola.getPila1();
			pila2=cola.getPila2();
		}

		void push(const T x){
			pila1.push(x);
		}

		void pop(){
		int contador=0;
		bool encontrado=false;
		int tamanio=pila1.size();
			while(encontrado){
				pila2.push(pila1.top());
				pila1.pop();
				contador++;
				if(contador==tamanio)
					pila1.pop();
					encontrado=true;
			}

			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
		}


		

		T& front(){
		
			while(!pila1.empty()){
				pila2.push(pila1.top());
				pila1.pop();
			}

			T& elemento=pila2.top();

			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
			return elemento;
		}


		T& back(){
			return pila1.top();
		}

		bool empty(){
			return pila1.empty();
		}

		int size(){
			return pila1.size();
		}


		bool operator<(cola<T>& cola){

			bool resultado=false;
			stack<T>pilaux=cola.getPila1();
			if(pila1.size()!=pilaux.size())
				cerr<<"Las colas no tienen el mismo tamaño";


			while(!pila1.empty() && !pilaux.empty()){
				if(pila1.top()<pilaux.top())
					resultado=true;
				else
					resultado=false,

				pila1.pop();
				pilaux.pop();
			}
		}

		bool operator==(cola<T>& cola){

			bool resultado=false;
			stack<T>pilaux=cola.getPila1();
			if(pila1.size()!=pilaux.size())
				cerr<<"Las colas no tienen el mismo tamaño";


			while(!pila1.empty() && !pilaux.empty()){
				if(pila1.top()==pilaux.top())
					resultado=true;
				else
					resultado=false,

				pila1.pop();
				pilaux.pop();
			}
		}
};

int main()
{
	cola<int> tail;
	tail.push(1);
	tail.push(2);
	tail.push(3);
	cout<<"El elemento frontal de la cola es: "<<tail.front()<<endl;
	cout<<"El elemento trasero de la cola es: "<<tail.back()<<endl;
	if(tail.empty())
		cout<<"La cola está vacía"<<endl;
	else
		cout<<"La cola no está vacía, tiene "<<tail.size()<<" elementos"<<endl;
	cola<int>tail2;
	tail2.push(4);
	tail2.push(5);
	tail2.push(6);


	if(tail<tail2)
		cout<<"Las cola 1 es menor que la cola 2"<<endl;
	else
		cout<<"La cola 1 es mayor que la cola 2"<<endl;


	if(tail==tail2)
		cout<<"La cola 1 es igual que la cola 2"<<endl;
	else
		cout<<"La cola 1 es distinta que la cola 2"<<endl;

}