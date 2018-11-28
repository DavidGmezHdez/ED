#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
template <typename T>



void insertar(queue<T> &P, int pos, const T &x){
	queue<T>colaux;
	int contador=0;
	bool posicion=false;

	while(!posicion){
		colaux.push(P.front());
		P.pop();
		contador++;
		if(contador==pos)
			posicion=true;
	}
	colaux.push(x);
	while(!P.empty()){
		colaux.push(P.front());
		P.pop();
	}
	while(!colaux.empty()){
		P.push(colaux.front());
		colaux.pop();
	}
}

int main()
{
	queue<int>cola;
	int x=4;
	int posicion=3;

	cola.push(1);
	cola.push(2);
	cola.push(3);
	cola.push(4);
	cola.push(5);

	cout<<"La cola original es: 12345"<<endl;

	insertar(cola,posicion,x);

	cout<<"El elemento a insertar es 4 en la posicion 3"<<endl<<"La cola final queda asi: "<<endl;

	while(!cola.empty())
	{
		cout<<cola.front();
		cola.pop();
	}
}