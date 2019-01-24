#include "zoo.h"


int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *al)
{
	animais.push_back(al);
}

string Zoo::getInformacao() const
{
	string info = "";
	for (size_t i = 0; i < animais.size(); i++)
	{
		info += animais[i]->getInformacao() + "\n";
	}
	return info;
}

bool Zoo::animalJovem(string nomeA)
{
	for (size_t i = 0; i < animais.size(); i++)
	{
		if (animais[i]->getNome() == nomeA)
		{
			if (animais[i]->eJovem())
				return true;
			else
				return false;
		}
	}
	return false;
}

void Zoo::alocaVeterinarios(istream &isV) {
	string nome, codS;

	while(!isV.eof()) {
		getline(isV,nome);
		getline(isV,codS);
		long num = atoi(codS.c_str());
		Veterinario *v1 = new Veterinario(nome, num);
		veterinarios.push_back(v1);
	}

	for(size_t i = 0; i < animais.size(); i++)
		animais[i]->setVeterinario(veterinarios[i]);
}

bool Zoo::removeVeterinario(string nomeV)
{
	for (size_t i = 0; i < veterinarios.size(); i++)
	{
		if (veterinarios[i]->getNome() == nomeV)
		{
			animais[i]->setVeterinario(veterinarios[i+1]);
			veterinarios.erase(veterinarios.begin() + i);
			return true;
		}
	}
	return false;
}

bool Zoo::operator < (Zoo& zoo2) const
{
	if (this->somaIdades() < zoo2.somaIdades())
		return true;
	else
		return false;
}

int Zoo::somaIdades() const
{
	int soma(0);
	for (size_t i = 0; i < animais.size(); i++)
	{
		soma += animais[i]->getIdade();
	}
	return soma;
}
