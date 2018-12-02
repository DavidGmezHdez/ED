/*Define una clase que permita guardar los datos de los pilotos de F1. Por ejemplo, nombre, apellido
(sólo uno), posición en la clasificación, nombre de la escuderı́a. Además debe permitir que se pueda
buscar a un piloto por su apellido. ¿Qué podrı́amos añadir a esa clase para que se pueda buscar
también por cualquiera de los restantes campos?.*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Piloto
{
    string nombre,apellido,nombre_escuderia;
    int posicion;
};


class Pilotos
{
    private:
    list<Piloto>pilotos;
    public:

    Pilotos(){
        pilotos=list<Piloto>(0);
    }


    void aniadirPiloto(Piloto d)
    {
        pilotos.push_back(d);
    }

    int getPosicion(Piloto d)
    {
        return d.posicion;
    }

    string getNombre(Piloto d)
    {
        return d.nombre;
    }

    string getApellido(Piloto d)
    {
        return d.apellido;
    }

    string getEscuderia(Piloto d)
    {
        return d.nombre_escuderia;
    }

    string toString()
    {
        list<Piloto>::const_iterator p=pilotos.begin();
        for(p;p!=pilotos.end();p++)
        {
            cout<<"["<<p->nombre<<","<<p->apellido<<","<<p->posicion<<","<<p->nombre_escuderia<<"]"<<endl;
        }
    }

    list<Piloto>::iterator begin(){
            return pilotos.begin();
    }

    list<Piloto>::iterator end(){
        return pilotos.end();
    }

    int size()
    {
        return pilotos.size();
    }


    Piloto getPiloto(string ape){
            list<Piloto>::iterator p = pilotos.begin();
            bool encontrado = false;
            
            for(int i=0;i<size() && !encontrado;i++){
                if(p->apellido== ape)
                    encontrado = true;
                else
                    p++;
            }
            return *p;
    }
};

int main()
{
    Pilotos lista;
    Piloto pbuscado;
    Piloto p1;
    string nombre1="Sebastian";
    string apellido1="Vettel";
    int posicion1=1;
    string escuderia1="Red Bull Racing";

    p1.nombre=nombre1;
    p1.apellido=apellido1;
    p1.posicion=posicion1;
    p1.nombre_escuderia=escuderia1;

    lista.aniadirPiloto(p1);

    Piloto p2;
    string nombre2="Fernando";
    string apellido2="Alonso";
    int posicion2=2;
    string escuderia2="Ferrari";
 
    p2.nombre=nombre2;
    p2.apellido=apellido2;
    p2.posicion=posicion2;
    p2.nombre_escuderia=escuderia2;

    lista.aniadirPiloto(p2);
    
    Piloto p3;
    string nombre3="Lewis";
    string apellido3="Hamilton";
    int posicion3=3;
    string escuderia3="McLaren Mercedes";

    p3.nombre=nombre3;
    p3.apellido=apellido3;
    p3.posicion=posicion3;
    p3.nombre_escuderia=escuderia3;

    lista.aniadirPiloto(p3);

    cout<<"Imprimimos los pilotos"<<endl;
    lista.toString();
    cout<<endl;
    cout<<"Buscamos el piloto con el apellido Alonso"<<endl;
    pbuscado=lista.getPiloto("Alonso");
    cout<<"["<<pbuscado.nombre<<","<<pbuscado.apellido<<","<<pbuscado.posicion<<","<<pbuscado.nombre_escuderia<<"]"<<endl;
    cout<<endl;
}