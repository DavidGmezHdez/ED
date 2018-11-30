#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <typename T>

class vdisperso {
public:
vdisperso(const vector<T> &v)
{
    typename vector<T>::const_iterator p = v.begin();

    for(p;p!=v.end();p++,n++)
    {
        if(*p!=0)
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

private:
list< pair<int, T> > coefs;
int n=0;
};

int main()
{
    vector<int>v, v2;
	int n;

	cout << "Introduzca valores para rellenar el vector: (-1 para acabar)"
		 << endl;
	cin >> n;
	while( n != -1){
		v.push_back(n);
		cout << "Introduzca valores para rellenar el vector: (-1 para acabar)" 
			 << endl;		
		cin >> n;
	}


	cout << "Vector con los valores introducidos: " << endl;
	typename vector<int>::const_iterator p = v.begin();

	for(p; p != v.end(); p++){
		cout << *p<< "  ";
	}

	cout<<endl;

	vdisperso <int>vdis(v);
    cout<<"Vector disperso"<<endl;
	vdis.imprimir_vector();

	cout<<endl;

}