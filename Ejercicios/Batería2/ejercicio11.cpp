#include <iostream>
#include <list>
using namespace std;

void inserta_antes(list<int> &l, int x)
{
	typename list<int>::iterator p = l.begin();
	int entero=x;
	for(p;p!=l.end();p++)
	{
		if(*p==x)
		{
			entero-=1;
			l.insert(p,entero);
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
	lista.push_back(3);
	list<int>::const_iterator q=lista.begin();

	cout<<"Lista original"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;

	inserta_antes(lista,1);

	q=lista.begin();
	
	cout<<"Lista insertada"<<endl;
	for (q;q!=lista.end();q++){
		cout<<*q<<" ";
	}
	cout<<endl;	




}