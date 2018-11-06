#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
template <typename T>

class pila
{
private:
	queue<T>cola1;
	queue<T>cola2;
public:

	pila(){
		cola1=queue<T>();
		cola2=queue<T>();
	}

	pila(queue<T>col1,queue<T>col2){
		cola1=col1;
		cola2=col2;
	}

	queue<T>getCola1(){
		return cola1;
	}

	queue<T>getCola2(){
		return cola2;
	}

	pila(pila &pila){
		cola1=pila.getCola1();
		cola2=pila.getCola2();
	}

	void push(const T x){
		cola1.push(x);
	}

	void pop(){
		int contador=0;
		bool encontrado=false;
		int tamanio=cola1.size();
		while(encontrado){
			cola2.push(cola1.front());
			cola1.pop();
			contador++;
			if(contador==tamanio)
				cola1.pop();
				encontrado=true;
		}
		while(!cola2.empty()){
			cola1.push(cola2.front());
			cola2.pop();
		}
	}

	T& top(){
		return cola1.back();
	}

	bool empty(){
		return cola1.empty();
	}

	int size(){
		return cola1.size();
	}


	bool operator<(pila<T>& pila){
		bool resultado=false;
		queue<T>colaux=pila.getCola1();
		if(cola1.size()!=colaux.size())
			cerr<<"Las pilas tienen diferente tamaño"<<endl;

		while(!cola1.empty() && !colaux.empty()){
			if(cola1.front()<colaux.front())
				resultado=true;
			else
				resultado=false,

				cola1.pop();
				colaux.pop();
		}
	}

	bool operator==(pila<T>& pila){
	bool resultado=false;
		queue<T>colaux=pila.getCola1();
		if(cola1.size()!=colaux.size())
			cerr<<"Las pilas tienen diferente tamaño"<<endl;

		while(!cola1.empty() && !colaux.empty()){
			if(cola1.front()==colaux.front())
				resultado=true;
			else
				resultado=false,

				cola1.pop();
				colaux.pop();
			}
	}
};


int main()
{
	pila<int> cell;
	cell.push(1);
	cell.push(2);
	cell.push(3);
	cout<<"El elemento superior de la pila es: "<<cell.top()<<endl;
	if(cell.empty())
		cout<<"La pila está vacía"<<endl;
	else
		cout<<"La pila no está vacía, tiene "<<cell.size()<<" elementos"<<endl;
	pila<int>cell2;
	cell2.push(4);
	cell2.push(5);
	cell2.push(6);


	if(cell<cell2)
		cout<<"Las pila 1 es menor que la pila 2"<<endl;
	else
		cout<<"La pila 1 es mayor que la pila 2"<<endl;


	if(cell==cell2)
		cout<<"La pila 1 es igual que la pila 2"<<endl;
	else
		cout<<"La pila 1 es distinta que la pila 2"<<endl;










}
