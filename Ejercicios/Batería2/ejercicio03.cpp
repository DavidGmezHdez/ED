#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

map<string,int> contar(string nom_fich)
{
	map<string,int>resultado;
	ifstream is;
	string clave;
	is.open(nom_fich);
	if(is.is_open()){
		while(is>>clave){
			resultado[clave]++;
		}
	}
	else{
		cerr<<"No se ha podido acceder al fichero"<<endl;
	}
	return resultado;
}


int main()
{
	map<string,int>contador=contar("texto.txt");
	
	cout<<"Palabras y numero de veces que aparecen"<<endl;
	for (map<string,int>::const_iterator iterador=contador.cbegin();iterador!=contador.cend();iterador++)
	{
		cout<<iterador->first << " "<<iterador->second<<endl;
	}	


}