#include "Jogador.h"


void Jogador::adicionaAposta(const Aposta & ap)
{
	this->apostas.insert(ap);
}

unsigned Jogador::apostasNoNumero(unsigned num) const
{
	unsigned count = 0;
	tabHAposta::const_iterator it = apostas.begin();

	for (; it != apostas.end(); it++) {
		count += it->getNumeros().count(num);
	}
	return count;
}


tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;

	tabHAposta::const_iterator it = apostas.begin();

	for (; it != apostas.end(); it++) {
		if (it->calculaCertos(sorteio) >= 3) {
			money.insert(*it);
		}
	}

	return money;
}
