/*Una variante del vector disperso es aquella en la que se puede definir cual es el valor nulo. Modifica
la clase anterior de forma que se pueda definir cual es el valor nulo al crear un objeto. Implementa
también cambiar_nulo(const T &n)*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <typename T>

class vdisperso {
private:
    list< pair<int, T> > coefs;
    int n=0;
    T VNulo;
public:
vdisperso(const vector<T> &v,const T& nulo)
{
    VNulo=nulo;
    typename vector<T>::const_iterator p = v.begin();

    for(p;p!=v.end();p++,n++)
    {
        if(*p!=VNulo)
            coefs.push_back(pair<int,T>(n,*p));
    }
}
void asignar_coeficiente(int i, const T &x)
{
    typename list<pair<int,T>>::iterator iterador=coefs.begin();
    bool insertada=false;
    int posicion=i;

    for(iterador;iterador!=coefs.end() || !insertada;iterador++)
    {
        if(iterador->first == posicion)
            iterador->second=x;
            insertada=true;
    }

    if(!insertada)
        coefs.push_back(pair<int,T>(i,x));
}
vector<T> convertir() const
{
    vector<T> resultado;
    resultado.reserve(n);
    typename list<pair<int,T>>::const_iterator iterador=coefs.begin();
    typename vector<T>::const_iterator p = resultado.begin();
    for(int j=0;j<resultado.size();j++)
    {
        if(iterador->first == j){
            resultado.push_back(iterador->second);
            iterador++;
        }
        else
            resultado.push_back(0);
            p++;
    }

    return resultado;
    }


void imprimir_vector()
{
    typename list<pair<int,T>>::iterator iterador=coefs.begin();
    for(iterador;iterador!=coefs.end();iterador++){
    cout<<"["<<iterador->first<<","<<iterador->second<<"]";
    }
}
void cambiarNulo(const T &nulo)
{
    VNulo=nulo;
    typename vector<T>::const_iterator p = coefs.begin();

    for(p;p!=coefs.end();p++,n++)
    {
        if(*p!=VNulo)
            coefs.push_back(pair<int,T>(n,*p));
    }
}
};

int main()
{
    vector<int>vec;
	int n;
    int nulo;

    cout<<"Intrdouce el valor nulo"<<endl;
    cin>>nulo;

 

	cout << "Introduzca valores para rellenar el vector: (-1 para acabar)"
		 << endl;
	cin >> n;
	while( n != -1){
		vec.push_back(n);
		cout << "Introduzca valores para rellenar el vector: (-1 para acabar)" 
			 << endl;		
		cin >> n;
	}


	cout << "Vector con los valores introducidos: " << endl;
	typename vector<int>::const_iterator p = vec.begin();

	for(p; p != vec.end(); p++){
		cout << *p<< "  ";
	}

	cout<<endl;

	vdisperso <int>vdis(vec,nulo);
    cout<<"Vector disperso"<<endl;
	vdis.imprimir_vector();

	cout<<endl;

}   