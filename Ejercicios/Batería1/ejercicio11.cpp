#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Alumno
{
	string nombre;
	string apellidos;
	int prioridad;
};

class comparacion{
public:
	bool operator()(Alumno al1,Alumno al2){
		bool resultado;
		if(al1.prioridad<al2.prioridad)
			resultado=true;
		else
			resultado=false;

	return resultado;
	}
};

int main(){
	priority_queue<Alumno,vector<Alumno>,comparacion> cola;
	cola.push({"Fernandez Alcaide","Alex",8});
	cola.push({"Alonso Díaz","Fernando",10});
	cola.push({"García Díaz","Raúl",7});
	cola.push({"Cuerva Heredia","Javier",4});

	while(!cola.empty()){
		cout<<cola.top().apellidos<<" "<<cola.top().nombre<<" "<<cola.top().prioridad<<endl;
		cola.pop();
	}
}