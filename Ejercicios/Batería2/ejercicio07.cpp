#include <iostream>
#include <list>
using namespace std;
template <typename T>

void elimina_duplicados(list<T> &l)
{
	typename list<T>::iterator p = l.begin();
	for (p;	p != l.end(); ++p) {
	typename list<T>::iterator q = p;
	++q;
	while (q != l.end()) {
		if (*p == *q)
			q = l.erase(q);
		else
			++q;
		}
	}
}


int main()
{

	list<int>lista;
	lista.push_back(2);
	lista.push_back(1);
	lista.push_back(7);
	lista.push_back(8);
	lista.push_back(1);
	lista.push_back(1);
	lista.push_back(5);
	lista.push_back(3);

	list<int>::const_iterator q=lista.begin();

	cout<<"Lista sin eliminar duplicados"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;

	elimina_duplicados(lista);
	
	q=lista.begin();

	cout<<"Lista con duplicados eliminados"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}	



}