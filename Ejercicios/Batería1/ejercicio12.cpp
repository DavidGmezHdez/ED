#include <iostream>
#include <queue>
#include <string>
using namespace std;

class comparacion{
public:
	bool operator()(string cadena1,string cadena2){
		bool resultado;
		int c1=0;
		int c2=0;
		
		if(cadena1.size()<cadena2.size()){
			c1++;
		}
		else
			c2++;

		if(cadena1.size()==cadena2.size()){
			if(cadena1[0]<cadena2[0])
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
	cola.push("Hola mundo");
	cola.push("Programar en c++ es divertido");
	cola.push("No me gustan las matrices");
	cola.push("Si me gustan las matrices");
	cola.push("Siempre me pierdo en los laberintos");

	while(!cola.empty()){
		cout<<cola.top()<<endl;
		cola.pop();
	}
}