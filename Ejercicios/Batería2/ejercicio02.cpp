/*Implementa una función desencripta que haga el proceso inverso al del ejercicio anterior.
string desencripta(string cad, const map<char, char> &codigo)*/

#include <iostream>
#include <map>
#include <string>

using namespace std;


string encripta(string cad, const map<char, char> &codigo)
{
map<char,char>::const_iterator x;

    for(int i=0;i<cad.size();i++){
    	x=codigo.find(cad[i]);
    	cad[i]=x->second;
    }
    return cad;
}

string desencripta(string cad, const map<char, char> &codigo)
{
	map<char,char>::const_iterator x;
	for(int i=0;i<cad.size();i++){
		x=codigo.find(cad[i]);
		cad[i]=x->first;
	}
	return cad;
}



int main(){

	map<char,char> codigo;
	
	for(char i='a';i<'z';i++){
		codigo.insert({i,i+1});
	}

	string cadena ="holaadios";
	cout<<"Cadena original "<<endl<<cadena<<endl;
	cout<<"Cadena encriptada"<<endl<<encripta(cadena,codigo)<<endl;
	cout<<"Cadena desencriptada"<<endl<<desencripta(cadena,codigo)<<endl;
}