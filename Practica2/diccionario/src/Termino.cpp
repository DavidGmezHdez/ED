#include "Termino.h"

Termino::Termino()
{
	palabra = '\n';
	definiciones = Vector_Dinamico<string>(0);
        ndefiniciones = definiciones.size();
}

Termino::Termino(string pala,Vector_Dinamico<string> def)
{
	palabra=pala;
	definiciones=def;
	ndefiniciones=def.size();
}

Termino::Termino(const Termino& T)
{
	*this=T;
}

void Termino::setPalabra(string Palabr)
{
	palabra=Palabr;
}

void Termino::setnDefiniciones(int n)
{
	if(n<=0)
		ndefiniciones = n;
	else
		cerr<<"El numero es menor que 0";
}

void Termino::AniadirDefinicion(string definicion)
{
	
	definiciones.resize(ndefiniciones+1);
	definiciones[definiciones.size()-1]=definicion;
        ndefiniciones++;
}

Termino & Termino::operator=(const Termino & original)
{
	if(this!=&original)
	{
		this->palabra = original.palabra;
		this->definiciones = original.definiciones;
		this->ndefiniciones = original.ndefiniciones;
		return *this;
	}
	else
		cerr<<"Los terminos son los mismos"<<endl;
}






