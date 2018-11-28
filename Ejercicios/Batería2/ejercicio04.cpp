#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

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





vector<string> veces(const map<string,int> &palabras, int num)
{
	vector<string> palabra;
	for (map<string,int>::const_iterator iterador=palabras.cbegin();iterador!=palabras.cend();iterador++)
	{
		if (iterador->second ==num)
		palabra.push_back(iterador->first);

	}	
	return palabra;
}

int main(){
map<string,int>contador=contar("texto.txt");
	
	cout<<"Palabras y numero de veces que aparecen"<<endl;
	for (map<string,int>::const_iterator iterador=contador.cbegin();iterador!=contador.cend();iterador++)
	{
		cout<<iterador->first << " "<<iterador->second<<endl;
	}	


	vector<string>palabras=veces(contador,2);
 	
 	cout<<"Palabras que aparecen 2 veces"<<endl;
 	for (int i=0;i<palabras.size();i++){
	cout<<palabras[i]<<" "<<endl;
	}






}