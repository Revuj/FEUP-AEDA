/*
 * Empacotador.cpp
 */

#include "MaquinaEmpacotar.h"
#include <sstream>
#include <algorithm>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


/* a implementar pelos estudantes */

unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	unsigned contador = 0;

//	sort(objs.begin(), objs.end());
//	reverse(objs.begin(), objs.end());

	for(unsigned int i = 0; i < objs.size(); i++) {
		cout << "peso: " << objs[i].getPeso() << endl;
		if (objs[i].getPeso() <= capacidadeCaixas) {
			this->objetos.push(objs[i]);
			objs.erase(objs.begin() + i);
			i--;
			contador++;
		}
	}
	return contador;
}


Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	vector<Caixa> aux;

	while (!this->caixas.empty()) {
		if (this->caixas.top().getCargaLivre() >= obj.getPeso()) {
			Caixa retorno = this->caixas.top();
			this->caixas.pop();

			while (!this->caixas.empty()) {
				aux.push_back(this->caixas.top());
				this->caixas.pop();
			}

			for (unsigned int i = 0; i < aux.size(); i++) {
				this->caixas.push(aux[i]);
			}

			return retorno;
		}
		else {
			aux.push_back(this->caixas.top());
			this->caixas.pop();
		}
	}

	Caixa novaCaixa(capacidadeCaixas);

	for (unsigned int i = 0; i < aux.size(); i++) {
		this->caixas.push(aux[i]);
	}

	return novaCaixa;
}


unsigned MaquinaEmpacotar::empacotaObjetos() {
	while(!this->objetos.empty()) {
		Objeto o = this->objetos.top();
		this->objetos.pop();
		Caixa c = procuraCaixa(o);
		c.addObjeto(o);
		this->addCaixa(c);
	}
	return this->caixas.size();
}

string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {

	if (this->objetos.empty()) {
		return "Nao ha objetos!\n";
	}
	HEAP_OBJS objs = this->objetos;
	stringstream ss;

	while(!objs.empty()) {
		ss << objs.top() << endl;
		objs.pop();
	}

	return ss.str();
}



Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
	if (this->caixas.empty())
		throw MaquinaSemCaixas();

	Caixa max;

	HEAP_CAIXAS cs = this->caixas;

	while(!cs.empty()) {
		if (cs.top().getSize() > max.getSize()) {
			max = cs.top();
		}
		cs.pop();
	}
	return max;
}



