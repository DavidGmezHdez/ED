/*Implementa una función que, dada una lista l de tipo T y un elemento x de tipo T, elimine el elemento
x de todas las posiciones en las que aparezca en l. Por ejemplo: si x = 1 y l = (2, 1, 1, 1, 1, 5, 3) el
resultado deberı́a ser (2, 5, 3)
void elimina(list<T> &l, const T &x)*/

#include <iostream>
#include <list>
using namespace std;
template <typename T>

void elimina(list<T> &l, const T &x)
{
	typename list<T>::const_iterator p=l.begin();
	while (p!=l.end())
	{
		if(*p==x)
			p=l.erase(p);
		else
			p++;
	}
}


int main()
{

	list<int>lista;
	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(3);

	list<int>::const_iterator q=lista.begin();

	cout<<"Lista sin eliminar repetidos"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;

	elimina(lista,1);
	
	q=lista.begin();

	cout<<"Lista con repetidos eliminados"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}	

}