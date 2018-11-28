#include <iostream>
#include <queue>
#include <string>
using namespace std;

class comparacion{
public:
	bool operator()(string cadena1,string cadena2){
		bool resultado;
		int contador1=0;
		int contador2=0;
		int c1=0;
		int c2=0;
		
		for(int i=0;i<cadena1.size();i++){
			if(cadena1[i]=='a' || cadena1[i]=='e' || cadena1[i]=='i' || cadena1[i]=='o' || cadena1[i]=='u')
				contador1++;
		}
		for(int i=0;i<cadena2.size();i++){
			if(cadena2[i]=='a' || cadena2[i]=='e' || cadena2[i]=='i' || cadena2[i]=='o' || cadena2[i]=='u')
				contador2++;
		}

		if(contador1<contador2)
			c1++;
		else
			c2++;

		if(contador1==contador2){
			if (cadena1[0]<cadena2[0])
				c1++;
			else
				c2++;
		}

		if(c1>c2)
			resultado=true;
		else
			resultado=false;

		return resultado;

	}
};

int main(){

	priority_queue<string,vector<string>,comparacion> cola;
	cola.push("abcd");
	cola.push("abcde");
	cola.push("aeiou");
	cola.push("dcba");

	while(!cola.empty()){
		cout<<cola.top()<<endl;
		cola.pop();
	}
}