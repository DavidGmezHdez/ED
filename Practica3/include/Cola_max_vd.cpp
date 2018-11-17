#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H
#include "Cola_max_vd.h"
using namespace std;

template <class T> 
Cola_max<T>::Cola_max(){
			vectorelementos=vector<T>();
			vectormax=vector<T>();
		}

template <class T> 
Cola_max<T>::Cola_max(vector<T>vec1,vector<T>vec2,vector<T>vec3){
			vectorelementos=vec1;
			vectormax=vec3;
		}
template <class T> 
Cola_max<T>::Cola_max(Cola_max &cola){
			vectorelementos=cola.getVectorElementos();
			vectormax=cola.getVectorMax();
		}
template <class T> 
void Cola_max<T>::poner(const T x){
    T max;
    vectorelementos.push_back(x);
    
    if(vectormax.empty()){
        max = (int) 0;
    }
    
    else{
        max = (T) maximo();
    }
    
    if(x < max){
        vectormax.push_back(x);
        posicion = vectormax.size() - 1;
    }
    
    else{
        for(int i=vectormax.size(); i>posicion; i--){
            vectormax.pop_back();
        }
        
        for(int i=vectormax.size(); i<vectorelementos.size(); i++){
            vectormax.push_back(x);
        }
}
}

 template <class T>
 void Cola_max<T>::quitar(){
     vector<T> aux;
        vectorelementos[0]=-1;
        
	for(int i=0; i<vectorelementos.size(); i++){
            if(vectorelementos[i]!=-1)
		aux.push_back(vectorelementos[i]);
	}
	
	vectorelementos=aux;
	aux.clear();
        vectormax[vectormax.size()-1]=-1;
        
	for(int i=0; i<vectormax.size(); i++){
            if(vectormax[i]!=-1)
		aux.push_back(vectormax[i]);
	}
        
    vectormax=aux;
}

 template <class T> 
 T& Cola_max<T>::frente(){
     return vectorelementos.front();
}

template <class T> 
bool Cola_max<T>::vacia(){
	return vectorelementos.empty();
}

template <class T> 
int Cola_max<T>::num_elementos(){
	return vectorelementos.size();
}

template <class T> 
T& Cola_max<T>::maximo(){
    return vectormax.back();
}


#endif
