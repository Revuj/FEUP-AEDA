#include <queue>
#include <cstdlib>
#include "Balcao.h"
#include "exceptions.h"

using namespace std;


Cliente::Cliente() {
	int randNum = rand()% 5 + 1;
	this->numPresentes = randNum;
}


int Cliente::getNumPresentes() const {
	return this->numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te) {
	this->tempo_atual = 0;
	int randNum = rand()% 20 + 1;
	this->prox_chegada = randNum;
	this->prox_saida = 0;
	this->clientes_atendidos = 0;
}      


void Balcao:: proximoEvento()
{
	if (this->prox_chegada > this->prox_saida)
		this->saida();
	else
		this->chegada();
}


void Balcao::chegada()
{
	Cliente c1;
	this->clientes.push(c1);
	int randNum = rand()% 20 + 1;
	this->prox_chegada = randNum;
	this->prox_saida = this->tempo_atual + c1.getNumPresentes()*this->tempo_embrulho;

	cout << this->tempo_atual << endl;
	cout << this->clientes.front().getNumPresentes();
}   


void Balcao::saida()
{
	Cliente c1 = this->clientes.front();
	this->clientes.pop();
	this->clientes_atendidos++;
	this->prox_saida = this->tempo_atual + this->clientes.front().getNumPresentes()*this->tempo_embrulho;
	cout << this->tempo_atual << endl;
	cout << c1.getNumPresentes();

}


int Balcao::getTempoAtual() const { return tempo_atual; }


int Balcao::getProxChegada() const { return prox_chegada; }


ostream & operator << (ostream & out, const Balcao & b1)
{
	out << "Clientes atendidos: " << b1.clientes_atendidos << endl;
	out << "Numero de clientes em espera: " << b1.clientes.size() << endl;
     return out;
}


int Balcao::getTempoEmbrulho() const {
	return this->tempo_embrulho;
}


int Balcao::getProxSaida() const {
	return prox_saida;
}


int Balcao::getClientesAtendidos() const {
	return this->clientes_atendidos;
}


Cliente & Balcao::getProxCliente() {
	if (this->clientes.empty())
		throw FilaVazia();
	else
		return this->clientes.front();
}

      
