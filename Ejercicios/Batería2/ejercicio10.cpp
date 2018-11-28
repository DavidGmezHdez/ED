#include <iostream>
#include <list>
using namespace std;
template <typename T>
 
void Ordenar(list<T> &l)
{
	typename list<T>::iterator itr, ant;
	itr = l.begin();
	++itr;
	while (itr != l.end()) {
		ant = itr;
		--ant;
		if(*ant > *itr) {
			while (*ant>*itr &&	ant!=l.begin())
					--ant;
					if (ant==l.begin() &&
					(*ant>*itr))
					l.insert(l.begin(),*itr);
				else {
					++ant;
					l.insert(ant,*itr);
				}
			itr = l.erase(itr);
		} 
		else ++itr;
	} 
}

template <typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2)
{
	typename list<T>::const_iterator p = l1.begin();
	list<T>resultado;

	for(p;p!=l1.end();p++)
	{
		resultado.push_back(*p);
	}

	p=l2.begin();
	for(p;p!=l2.end();p++)
	{
		resultado.push_back(*p);
	}

	Ordenar(resultado);
	return resultado;
}

int main()
{
	list<int>lista1;
	lista1.push_back(1);
	lista1.push_back(7);
	lista1.push_back(9);
	lista1.push_back(5);
	lista1.push_back(3);

	list<int>lista2;
	lista2.push_back(0);
	lista2.push_back(4);
	lista2.push_back(8);
	lista2.push_back(6);
	lista2.push_back(2);

	list<int>::const_iterator q=lista1.begin();
	cout<<"Lista 1"<<endl;
	for (q;q!=lista1.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;

	q=lista2.begin();
	cout<<"Lista 2"<<endl;
	for (q;q!=lista2.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;

	list<int>listamezclada=mezclar(lista1,lista2);
	q=listamezclada.begin();
	cout<<"Lista mezclada"<<endl;
	for(q;q!=listamezclada.end();q++)
	{
		cout<<*q<<" ";
	}
}