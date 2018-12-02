/*Implementa una función bool contenida(const list<T> &l1, const list<T> &l2)
a la que se le pasen dos listas y compruebe si la lista l1 está contenida en l2 (si los elementos apa-
recen en la otra y en el mismo orden).*/

#include <iostream>
#include <list>
using namespace std;
template <typename T>
bool contenida(const list<T> &l1, const list<T> &l2)
{
    typename list<int>::const_iterator p = l2.begin();
    typename list<int>::const_iterator q = l1.begin();
    bool contenida=false;
    int contador=0;

    for(p;p!=l2.end();p++)
    {
        if (*p==*q)
        {
            q++;
            contador++;
            if(contador==l1.size())
                contenida=true;
        }

    }
    return contenida;
}

int main()
{
    list<int>lista1;
	lista1.push_back(2);
	lista1.push_back(3);

	list<int>lista2;
	lista2.push_back(1);
	lista2.push_back(2);
	lista2.push_back(3);
	lista2.push_back(4);


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

    bool contenido=contenida(lista1,lista2);

    if(contenido)
        cout<<"Lista1 está contenida en Lista2"<<endl;
    else    
        cout<<"Lista1 no está contenida en Lista2"<<endl;


    bool contenido2=contenida(lista2,lista1);
    if(contenido2)
        cout<<"Lista2 está contenida en Lista1"<<endl;
    else    
        cout<<"Lista2 no está contenida en Lista1"<<endl;
}
