#include <iostream>
#include "bintree.h"

typename bintree<T>::node mas_profunda(const bintree<T> &Arb)
{
    typename bintree<T>::const_iterator iterador = Arb.begin_level();
    int contador=0;

    for (iterador;iterador!=Arb.end_level();iterador++){
        if (*iterador == Arb.size()-1)
            return *iterador;
    }
}

int main()
{
    bintree<int> arbol(7);
    typename bintree<T>::node profundo;

    //Creamos el arbol que aparece como ejemplo en el guión
    arbol.insert_left(prueba.root(),1);





}