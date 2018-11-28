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





int main(){

	map<char,char> codigo;
	
	for(char i='a';i<'z';i++){
		codigo.insert({i,i+1});
	}

	string cadena ="holaadios";
	cout<<"cadena sin encriptar: "<<cadena<<endl;
	cout<<"cadena encriptada: "<<encripta(cadena,codigo)<<endl;
}