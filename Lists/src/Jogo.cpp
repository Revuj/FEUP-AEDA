/*
 * Jogo.cpp
 *
 */

#include "Jogo.h"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




unsigned int Jogo::numPalavras(const string & frase)
{
	unsigned int number_of_words = 0;

	for (auto iter = frase.cbegin(); iter != frase.cend(); ++iter)
	{
	    if (isspace(*iter))
	    {
	        number_of_words++;
	    }
	}
	number_of_words++;
	return number_of_words;
}


Jogo::Jogo()
{
	this->criancas.clear();
}

Jogo::Jogo(list<Crianca>& lc2)
{
	this->criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
	this->criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
	return this->criancas;
}


string Jogo::escreve() const
{
	stringstream ss;

	list<Crianca>::const_iterator it = this->criancas.begin();

	for (; it != this->criancas.end(); it++)
	{
		ss << it->escreve() << endl;
	}

	return ss.str();
}


Crianca& Jogo::perdeJogo(string frase)
{
	unsigned int npal = numPalavras(frase);
	list<Crianca>::iterator it = criancas.begin();

	//cout << npal << endl;

	while (criancas.size() > 1)
	{
		for (unsigned int i = 1; i < npal; i++)
		{
			it++;
			if (it == criancas.end())
				it = criancas.begin();
		}
		it = this->criancas.erase(it);
		if (it == criancas.end()) it =criancas.begin();
	}


	this->criancas.erase(it);
	return *it;
}


list<Crianca>& Jogo::inverte()
{
	this->criancas.reverse();
	return this->criancas;
}


list<Crianca> Jogo::divide(unsigned id)
{
	list<Crianca>::iterator it = this->criancas.begin();

	for (; it != this->criancas.end(); it++)
	{
		if (it->getIdade() <= id)
			it = this->criancas.erase(it);
	}
	return this->criancas;
}


void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
	this->criancas.insert(this->criancas.begin(), l1.begin(), l1.end());
}


bool Jogo::operator==(Jogo& j2)
{
	list<Crianca>::iterator it1 = this->criancas.begin();
	list<Crianca>::iterator it2 = j2.getCriancasJogo().begin();

	for (; it1 != this->criancas.end(); it1++)
	{
		if (it1->getNome() != it2->getNome() || it1->getIdade() != it2->getIdade())
			return false;
		it2++;
	}
	return true;
}


list<Crianca> Jogo::baralha() const
{

	list<Crianca> l1(this->criancas);
	list<Crianca> l2;

	list<Crianca>::iterator it = l1.begin();

	for (unsigned int i = 0; i < this->criancas.size(); i++)
	{
		int randomNumber = rand() % (l1.size());
		advance(it, randomNumber);
		l2.push_back(*it);
		l1.erase(it);
		it = l1.begin();
	}

	return l2;
}
