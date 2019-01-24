#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

// excecao  NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{
	out << "No repetido: " << no.info;
	return out;
}



//======================================================
//======================================================

// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

//======================================================
//======================================================

// excecao ArestaRepetida
template <class N>
class ArestaRepetida
{
public:
	N noPartida;
	N noDestino;
	ArestaRepetida(N partida, N destino) {noPartida = partida; noDestino = destino;}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &aresta)
{
	out << "Aresta repetida: " << aresta.noPartida << " , " << aresta.noDestino;
	return out;
}

//======================================================
//======================================================

// excecao ArestaInexistente
template <class N>
class ArestaInexistente
{
public:
	N noPartida;
	N noDestino;
	ArestaInexistente(N partida, N destino) {noPartida = partida; noDestino = destino;}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &aresta)
{
	out << "Aresta inexistente: " << aresta.noPartida << " , " << aresta.noDestino;
	return out;
}

//======================================================
//======================================================
template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

//======================================================
//======================================================

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

//======================================================
//======================================================

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const;
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);

template <class N, class A>
Grafo<N,A>::Grafo()
{

}

template <class N, class A>
Grafo<N,A>::~Grafo()
{
	for (size_t i = 0; i < nos.size(); i++)
		delete nos[i];
}

template <class N, class A>
int Grafo<N,A>::numNos(void) const
{
	return nos.size();
}

template <class N, class A>
int Grafo<N,A>::numArestas(void) const
{
	int n = 0;

	for (size_t i = 0; i < nos.size(); i++)
	{
		n += nos[i]->arestas.size();
	}

	return n;
}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirNo(const N &dados)
{
	for(size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == dados)
			throw NoRepetido<N>(dados);
	}
	No<N,A> *no1 = new No<N,A>(dados);
	nos.push_back(no1);
	return *this;
}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
	bool existeNo = false;

	for (size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == inicio)
		{
			existeNo = true;
			for (size_t j = 0; j < nos[i]->arestas.size(); j++)
			{
				if ((nos[i]->arestas[j].destino)->info == fim)
					throw ArestaRepetida<N>(inicio, fim); //duvida, gera um erro "unknown exception thrown
			}
			No<N,A> *no1 = new No<N,A>(fim);
			Aresta<N,A> aresta1(no1, val);
			nos[i]->arestas.push_back(aresta1);
		}
	}
	if (existeNo == false)
		throw NoInexistente<N>(inicio);
	return *this;
}

template <class N, class A>
A & Grafo<N,A>::valorAresta(const N &inicio, const N &fim)
{
	bool existeAresta = false;
	bool existeNo = false;

	for (size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == inicio)
		{
			existeNo = true;
			for (size_t j = 0; j < nos[i]->arestas.size(); j++)
			{
				if ((nos[i]->arestas[j].destino)->info == fim)
				{
					existeAresta = true;
					return nos[i]->arestas[j].valor;
				}
			}
		}
	}

	if (existeNo == false)
			throw NoInexistente<N>(inicio);

	if (!existeAresta)
		throw ArestaInexistente<N>(inicio, fim);
}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::eliminarAresta(const N &inicio, const N &fim)
{
	bool existeAresta = false;
	bool existeNo = false;

	for (size_t i = 0; i < nos.size(); i++)
	{
		if (nos[i]->info == inicio)
		{
			existeNo = true;
			for (size_t j = 0; j < nos[i]->arestas.size(); j++)
			{
				if ((nos[i]->arestas[j].destino)->info == fim)
				{
					existeAresta = true;
					nos[i]->arestas.erase(nos[i]->arestas.begin()+i);
					break;
				}
			}
		}
	}

	if (existeNo == false)
			throw NoInexistente<N>(inicio);

	if (!existeAresta)
		throw ArestaInexistente<N>(inicio, fim);

	return *this;
}

template <class N, class A>
void Grafo<N,A>::imprimir(std::ostream &os) const
{
	for (size_t i = 0; i < nos.size(); i++)
	{
		os << "( " << nos[i]->info;

		for (size_t j = 0; j < nos[i]->arestas.size(); j++)
		{
			os << "[ " << (nos[i]->arestas[j].destino)->info << " " <<  nos[i]->arestas[j].valor << "] ";
		}

		os << ") ";
	}
}
