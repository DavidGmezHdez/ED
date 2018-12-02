/*Implementa la clase vector dinámico usando como representación el tipo list. ¿Qué orden de eficiencia
tiene cada operación?*/

#include <iostream>
#include <list>
using namespace std;
template <typename T>

class Vector_Dinamico
{
private:
    list<T> coefs;
    int nelementos;
public:
    Vector_Dinamico(int elementos)
    {
        nelementos=elementos;
    }

    void AniadirElemento(T elemento)
    {
        if(coefs.size()<nelementos)
            coefs.push_back(elemento);   
    }

    T getElemento(int indice)
    {
        if(indice>nelementos)
        {
            cerr<<"La posición introducida es mayor que el numero de elementos";
            cout<<endl;
            exit(0);
        }
        else{

        typename list<T>::const_iterator p=coefs.begin();
        for(int i=0;i<indice;i++)
        {
                p++;
        }
        return *p;
        }
    }

    int size()
    {
        return coefs.size();
    }

    bool empty()
    {
        return coefs.empty();
    }

    void imprimirVector()
    {
        typename list<T>::const_iterator p=coefs.begin();
        for(p;p!=coefs.end();p++)
        {
            cout<<*p<<" ";
        }
    }
    
    int nElementos()
    {
        return nelementos;
    }
};
int main()
{
    int n;

    cout<<"Introduce el numero de elementos"<<endl;
    cin>>n;

    Vector_Dinamico<int>vector(n);

    for(int i=0;i<vector.nElementos();i++)
    {
        int x;
        cout<<"Introduce el elemento "<<i<<endl;
        cin>>x;
        vector.AniadirElemento(x);
    }
    cout<<endl;
    cout<<"Vector"<<endl;
    vector.imprimirVector();
    
    cout<<endl;
    int y;
    cout<<"Introduce la posición del elemento que quieras obtener"<<endl;
    cin>>y;
    cout<<"El elemento en la posicion "<<y<<" es: "<<vector.getElemento(y)<<endl;

    cout<<endl;
    if(vector.empty())
        cout<<"El vector está vacío"<<endl;
    else
        cout<<"El vector no está vacío, tiene "<<vector.size()<<" elementos"<<endl;

}


