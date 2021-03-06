/*Una forma eficiente de guardar secuencias de valores iguales consiste en guardar cada uno de los
valores seguido del número de veces que aparece en la secuencia. Por ejemplo,
<1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5>
< (1,3), (2,6), (7,5), (12,1), (1,2), (5,2) >
Implementa las funciones:
list<pair<T, int> > comprimir(const list<T> &l)+
list<T> descomprimir(const list<pair<T, int> > &lc)
que permitan convertir entre ambas representaciones.*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <typename T>
list<pair<T, int> > comprimir(const list<T> &l)
{
    list<pair<T,int>> comprimido;
    typename list<T>::const_iterator p=l.begin();
	typename list<T>::const_iterator q=l.begin();
    int contador=1;
for(p;q!=l.end();p++)Prof.Miguel Garcia SilventeUniversidad de Granada
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
ETSI Informática y Telecomunicación, C/Periodista Daniel Saucedo Aranda s/n - 18071 - Granada (España)
{
	q++;
    if(*p==*q)
        contador++;
    else{
        comprimido.push_back(pair<T,int>(*p,contador));
        contador=1;
	}
}
	return comprimido;
}

template <typename T>
list<T> descomprimir(const list<pair<T, int> > &lc)
{
    list<T> descomprimida;
    typename list<pair<T,int>>::const_iterator q=lc.begin();
    for(q;q!=lc.end();q++)
    {
        int contador=0;
        while (contador!=q->second)
        {
            descomprimida.push_back(q->first);
            contador++;
        }
    }
    return descomprimida;
}

int main()
{
 list<int>lista1, lista_descomprimida;
	list<pair<int,int> > lista2;

	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(2);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(7);
	lista1.push_back(12);
	lista1.push_back(1);
	lista1.push_back(1);
	lista1.push_back(5);
	lista1.push_back(5);

	cout << "Lista: " << endl;
	auto wi = lista1.begin();
	for(wi; wi != lista1.end(); ++wi)
		cout << *wi << " ";
	
	cout << endl << endl;

	lista2=comprimir(lista1);

	cout << "Lista comprimida: " << endl;
	auto itpar = lista2.begin();

	for(itpar; itpar != lista2.end(); ++itpar)
		cout << "(" << itpar->first << "," << itpar->second  << ")  ";

	cout << endl << endl;

	lista_descomprimida =descomprimir(lista2);

	cout << "Lista descomprimida" << endl;

	auto we = lista_descomprimida.begin();
	for(we; we != lista_descomprimida.end(); ++we)
		cout << *we << " ";
	
	cout << endl << endl;

}