#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool parentesis_correctos(string expresion){
	stack<char>pila;
	stack<char>pilaux;
	bool resultado=false;

	for(int i=0;i<expresion.size();i++)
	{
		pila.push(expresion[i]);
	}

	while(!pila.empty()){
		char elemento=pila.top();
		
		if(elemento==')')
			pilaux.push(elemento);
		if(elemento=='(')
			pilaux.pop();

		pila.pop();
	}

	if (pilaux.empty())
		resultado=true;

	return resultado;
}

int main()
{
	string parentesis="(hola)";

	if(parentesis_correctos(parentesis))
		cout<<"La palabra: "<<parentesis<<" es correcta"<<endl;
	else
		cout<<"La palabra: "<<parentesis<<" no es correcta"<<endl;

}