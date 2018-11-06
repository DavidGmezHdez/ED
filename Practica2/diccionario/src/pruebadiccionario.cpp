#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario
   
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    Algunas sugerencias: */
    
   //- Obtener las definiciones asociadas a una palabra   
  
   string palabra="a";
   cout << "Las definiciones de la palabra "<<palabra<<" son:"<<endl;
    for(int i=0; i<mi_diccionario.getDefinicionesPalabra(palabra).size(); i++){
      cout<< mi_diccionario.getDefinicionesPalabra(palabra)[i] << endl;
    }      




    // - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
   char ci='g';
   char cf='i';
   
   cout<<"El diccionario comprendido entre "<<ci<<" y "<<cf<<" es: "<<endl;
   cout<<mi_diccionario.filtroIntervalo(ci,cf)<<endl;

// - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color" 
   string clave="color";
   cout<<"El diccionario con la palabra clave "<<clave<<" es: "<<endl;
   cout<<mi_diccionario.filtroPalabra(clave)<<endl;

// - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
   int ntotal,maxdefiniciones;
   float promedio;
   
   mi_diccionario.Recuento(ntotal,maxdefiniciones,promedio);
   
   cout<<"El numero total de definiciones es de: "<<ntotal<<endl<<"El maximo de definiciones asociadas a una unica palabra: "<<maxdefiniciones<<endl
   <<"El promedio de definiciones por palabra es: "<<promedio<<endl;     
   

}
