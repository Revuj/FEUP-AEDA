#include "animal.h"

//ANIMAL
int Animal::maisJovem = 2000;

Animal::Animal(string nome, int idade)
{
	this->nome = nome;
	this->idade = idade;
	this->vet = NULL;

	if (idade < maisJovem)
		maisJovem = idade;
}

string Animal::getNome() const {
	return nome;
}

int Animal::getMaisJovem() {
	return maisJovem;
}

string Animal::getInformacao() const {
	string info;
	if (vet != NULL)
		info = nome + ", " + to_string(idade) + ", " + vet->getNome() + ", " + to_string(vet->getCodigo());
	else
		info = nome + ", " + to_string(idade);
	return info;
}

void Animal::setVeterinario(Veterinario *vet) {
	this->vet = vet;
}

int Animal::getIdade() const
{
	return idade;
}

//CAO

Cao::Cao(string nome, int idade, string raca) : Animal (nome, idade) {
	this->raca = raca;
}

bool Cao::eJovem() const {
	if (idade < 5)
		return true;
	else
		return false;
}

string Cao::getInformacao() const {
	string info;
	info = Animal::getInformacao() + ", " + raca;
	return info;
}

//VOADOR

Voador::Voador(int vmax, int amax) {
	altura_max = amax;
	velocidade_max = vmax;
}

string Voador::getInformacao() const {
	string info = to_string(velocidade_max) + ", " + to_string(altura_max);
	return info;

}

//MORCEGO

Morcego::Morcego(string nome, int idade, int vmax, int amax) : Animal(nome, idade) , Voador(vmax, amax) {
}

bool Morcego::eJovem() const {
	if (idade < 4)
		return true;
	else
		return false;
}

string Morcego::getInformacao() const {
	string info;
	info = Animal::getInformacao() + ", " + Voador::getInformacao();
	return info;

}


