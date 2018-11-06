#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
template <typename T>

void insertar(stack<T> &P, int pos, const T &x){
	stack<T>pilaux;
	int contador=0;
	bool posicion=false;

	while (!posicion)
	{	
		pilaux.push(P.top());
		P.pop();
		contador++;
		if(contador==pos)
			posicion=true;
	}

	P.push(x);
	while (!pilaux.empty()){
		P.push(pilaux.top());
		pilaux.pop();
	}

}

int main()
{

	stack<int>pila;
	int x=4;
	int posicion=3;

	pila.push(1);
	pila.push(2);
	pila.push(3);
	pila.push(4);
	pila.push(5);

	insertar(pila,posicion,x);

	while(!pila.empty())
	{
		cout<<pila.top();
		pila.pop();
	}


}