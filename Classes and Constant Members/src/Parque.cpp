#include "Parque.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli)
{
	vagas = lot;
}

unsigned int ParqueEstacionamento::getNumLugares() const
{
	return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
	return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const
{
	for (int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i].nome == nome)
			return i;
	}

	return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
	if (clientes.size() < numMaximoClientes)
	{
		InfoCartao cliente;
		cliente.nome = nome;
		cliente.presente = false;
		clientes.push_back(cliente);

		return true;
	}
	else
		return false;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if (vagas == 0)
		return false;

	if (posicaoCliente(nome) == -1)
		return false;

	if (clientes[posicaoCliente(nome)].presente == true)
		return false;

	clientes[posicaoCliente(nome)].presente = true;
	vagas--;
	return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (size_t i = 0; i < clientes.size(); i++)
		{
			if (clientes[i].nome == nome)
			{
				if (clientes[i].presente == true)
					return false;
				else
				{
					clientes.erase(clientes.begin() + i);
					return true;
				}
			}
		}
	return false;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	for (size_t i = 0; i < clientes.size(); i++)
			{
				if (clientes[i].nome == nome)
				{
					if (clientes[i].presente == true)
					{
						clientes.erase(clientes.begin()+i);
						vagas++;
						return true;
					}
					else
						return false;
				}
			}
	return false;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
	return (lotacao - vagas);
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const
{
	return clientes.size();
}
