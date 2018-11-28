#include <iostream>
#include <list>
using namespace std;
template <typename T>

void inversa(list<T> &l)
{
	typename list<T>::const_iterator p = --l.end();
	list<T>aux;

	for(p;p!=l.begin();p--)
	{	
		aux.push_back(*p);
	}
	aux.push_back(*p);
	l.clear();

	p=aux.begin();

	for(p;p!=aux.end();p++)
	{
		l.push_back(*p);
	}

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

	inversa(lista);
	
	q=lista.begin();

	cout<<"Lista inversa"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}	
}