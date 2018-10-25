#include <cassert>
#include <string>
#include "Termino.h"


Termino::Termino()
{
	palabra=null;
	definiciones=null;
	ndefiniciones=0;
}

Termino::Termino(string pala,string* def)
{
	palabra=pala;
	definiciones=def;
	ndefiniciones=def.length();

}

Termino::Termino(const Termino& T)
{
	*this=T;
}

void Termino::setPalabra(string Palabr)
{
	palabra=Palabr;
}

void Termino::AniadirDefinicion(string definicion)
{
	for (int i=0;i<ndefiniciones;i++)
	{
		if (cmp(definiciones[i],definicion)!=0)
		{
			ndefiniciones++;
			definiciones[ndefiniciones]=definicion;
		}
	}
}




Termino & operator=(const Termino & original)
{
	if(this!=&original)
	{
		this->palabra = original.palabra;
		this->definiciones = original.definiciones;
		this->ndefiniciones = original.ndefiniciones;
	}
	else
		cerr<<"Los terminos son los mismos"<<endl;
}



stream& operator <<(ostream &os, const Termino &p)
{
	os<<p.getPalabra()<<endl<<p.getnDefiniciones;
	for(int i=0;i<p.getnDefiniciones();i++)
	{
		os<<"Definicion numero["<<i<<"]: "<<p.getDefiniciones<<endl;
	}

return os;
}



