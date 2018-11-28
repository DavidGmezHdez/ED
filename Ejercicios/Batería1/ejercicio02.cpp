#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool parentesis_correctos(string expresion){
	stack<char>pila;

	for(int i=0;i<expresion.size();i++)
	{
		if(expresion[i]=='(')
			pila.push(expresion[i]);

		if(expresion[i]==')')
			pila.pop();
	}

	return pila.empty();
}

int main()
{
	string parentesis="(hola)";
	string parentesis2="((hola)";

	if(parentesis_correctos(parentesis))
		cout<<"La palabra: "<<parentesis<<" es correcta"<<endl;
	else
		cout<<"La palabra: "<<parentesis<<" no es correcta"<<endl;

	if(parentesis_correctos(parentesis2))
		cout<<"La palabra: "<<parentesis2<<" es correcta"<<endl;
	else
		cout<<"La palabra: "<<parentesis2<<" no es correcta"<<endl;

}