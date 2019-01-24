#include "Frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1)
{
	veiculos.push_back(v1);
}

int Frota::numVeiculos() const
{
	return veiculos.size();
}

int Frota::menorAno() const
{
	if (numVeiculos() == 0)
		return 0;
	else
	{
		int min = (*veiculos[0]).getAno();

		for (int i = 0; i < numVeiculos(); i++)
		{
			if ((*veiculos[i]).getAno() < min)
				min = (*veiculos[i]).getAno();
		}
		return min;
	}
}

vector<Veiculo *> Frota::operator() (int anoM) const
{
	vector<Veiculo *> anoMVeiculos;

	for (int i = 0; i < numVeiculos(); i++)
	{
		if ((*veiculos[i]).getAno() == anoM)
			anoMVeiculos.push_back(veiculos[i]);
	}

	return anoMVeiculos;
}

float Frota::totalImposto() const
{
	float soma(0);

	for (int i = 0; i < numVeiculos(); i++)
	{
		soma += (*veiculos[i]).calcImposto();
	}

	return soma;
}

