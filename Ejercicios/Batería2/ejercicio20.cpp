/*Escribe un programa que permita leer de la entrada estándar una serie de coordenadas (como un par
de float) y que contabilice de forma eficiente el número de veces que aparece cada uno de los pares.*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<pair<float,float>,int> mapa;
    int n;
    float x,y;
    
    cout<<"Introduce el numero de coordenadas"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Introduce la primera coordenada del elemento "<<i<<endl;
        cin>>x;
        cout<<"Introduce la segunda coordenada del elementio "<<i<<endl;
        cin>>y;
        map<pair<float,float>,int>::iterator iterador=mapa.find({x,y});
        if(iterador==mapa.end())
            mapa.insert({{x,y},1});
        else
            ++iterador->second;
    }
     map<pair<float,float>,int>::const_iterator p;
    for(p=mapa.begin();p!=mapa.end();p++)
    {
        cout<<"["<<p->first.first<<","<<p->first.second<<"] ("<<p->second<<" veces)"<<endl; 
    }
}