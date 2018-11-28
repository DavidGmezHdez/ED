#include <iostream>
#include <list>
using namespace std;
template <typename T>
list<T> inversa(const list<T> &l)
{
	typename list<T>::const_iterator p = --l.end();
	list<T>resultado;

	for(p;p!=l.begin();p--)
	{	
		resultado.push_back(*p);
	}
	resultado.push_back(*p);
	return resultado;
}

int main()
{
	list<int>lista;
	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(7);
	lista.push_back(8);
	lista.push_back(5);
	lista.push_back(3);

list<int>::const_iterator q=lista.begin();

	cout<<"Lista original"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;

	list<int>lista2=inversa(lista);
	
	q=lista2.begin();

	cout<<"Lista inversa"<<endl;
	for (q;q!=lista2.end();q++){
		cout<<*q<<" ";
	}	

}