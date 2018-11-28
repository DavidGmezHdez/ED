#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool palindromo(const string &cad){
	bool resultado=false;
	stack<char> pilaux;
	queue<char> colaux;

	for(int i=0;i<cad.size();i++)
	{
		if(cad[i]!=' ')
			pilaux.push(cad[i]);
	}

	for(int i=0;i<cad.size();i++)
	{
		if(cad[i]!=' ')
			colaux.push(cad[i]);
	}
	

	while(!pilaux.empty()){
		if(pilaux.top()==colaux.front())
			resultado=true;
		else
			resultado=false;

		pilaux.pop();
		colaux.pop();
	}
	return resultado;
}

int main()
{
	string palindro1="arde ya la yedra";
	string palindro2="arde ya la yedraeeoo";
	bool resultado1=palindromo(palindro1);
	bool resultado2=palindromo(palindro2);


	if(resultado1){
		cout<<"La cadena "<<palindro1<<" es un palindromo"<<endl;
	}
	else{
		cout<<"La cadena "<<palindro1<<" no es un palindromo"<<endl;
	}


	if(resultado2){
		cout<<"La cadena "<<palindro2<<" es un palindromo"<<endl;
	}
	else{
		cout<<"La cadena "<<palindro2<<" no es un palindromo"<<endl;
	}
}

