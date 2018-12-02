/*Implementa la función intercalar(vector<T> &v, vector<pair<int, T> > pos)
que inserta el segundo elemento de cada par de pos en v en los lugares indicados por el primer
elemento de cada par de pos*/

#include <iostream>
#include <vector>
using namespace std;
template <typename T>

void intercalar(vector<T> &v,vector<pair<int,T>>pos)
{
    typename vector<T>::const_iterator p=v.begin();
    typename vector<pair<int,T>>::const_iterator q=pos.begin();

for(q;q!=pos.end();q++){
    for(int i=0;i<q->first;i++)
    {   
        p++;
    }
    v.insert(p,q->second);      
    }
}

int main()
{
    vector<int> vec;
	vector<pair<int,int>> posicion;
    int n;


    cout<<"Introduce el numero de elementos"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"Introduce el elemento "<<i<<endl;
        cin>>x;
        vec.push_back(x);
    }
    posicion.push_back(pair<int,int>(1,2));

    typename vector<int>::const_iterator iterador=vec.begin();
    cout<<endl;
    cout<<"Vector inicial"<<endl;
    for(iterador;iterador!=vec.end();iterador++)
    {
        cout<<*iterador<<" ";
    }

    intercalar(vec,posicion);

    iterador=vec.begin();
    cout<<endl;
    cout<<"Vector intercalado"<<endl;
    for(iterador;iterador!=vec.end();iterador++)
    {
        cout<<*iterador<<" ";
    }
    cout<<endl;

}