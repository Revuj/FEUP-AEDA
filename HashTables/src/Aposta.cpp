#include "Aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(unsigned num) const
{
	if (numeros.find(num) != numeros.end())
		return true;
	else
		return false;
}


void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
	for (unsigned int i = 0; n > 0 && i < valores.size(); i++) {
		if (numeros.find(valores[i]) == numeros.end()) {
			numeros.insert(valores[i]);
			n--;
		}
	}
}


unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
	unsigned certos = 0;
	tabHInt::const_iterator it = sorteio.begin();

	for(; it != sorteio.end(); it++) {
		if (this->contem(*it))
			certos++;
	}
	return certos;
}

unsigned Aposta::somaNumeros() const {
	tabHInt::const_iterator it = numeros.begin();

	unsigned somatorio = 0;

	for(; it != numeros.end(); it++) {
		somatorio += *it;
	}

	return somatorio;
}




