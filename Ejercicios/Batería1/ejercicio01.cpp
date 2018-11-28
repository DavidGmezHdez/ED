#include <iostream>
#include <stack>
using namespace std;
template <typename T>

void substituye(stack<T> &P, const T &x, const T &y){
	stack<int>pilaux;

	while (!P.empty())
	{
		pilaux.push(P.top());
		if(pilaux.top()==x){
			pilaux.pop();
			pilaux.push(y);
		}	
		P.pop();
	}

	while(!pilaux.empty()){
		P.push(pilaux.top());
		pilaux.pop();

	}
}

int main(int argc, char * argv[]){
	stack<int> pila;
	int x,y;

	x=1;
	y=0;

	for(int i=1;i<=3;i++){
		pila.push(i);
	}
	pila.push(1);
	cout<<"La cadena original es 1231"<<endl;
	substituye(pila,x,y);

	cout<<"Al sustituir 1 por 0 la cadena obtenida es: "<<endl;
	while(!pila.empty())
	{
		cout<<pila.top();
		pila.pop();
	}
}