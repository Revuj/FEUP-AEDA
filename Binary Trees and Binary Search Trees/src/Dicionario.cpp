#include <iostream>
#include <string>
#include <fstream>
#include "Dicionario.h"
#include "BST.h"

using namespace std;


BST<PalavraSignificado> Dicionario::getPalavras() const
{ return palavras; }



bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const
{
	return(this->palavra < ps1.palavra);
}


void Dicionario::lerDicionario(ifstream &fich)
{
	string palavra;
	string significado;

	while(!fich.eof()) {
		getline(fich, palavra);
		getline(fich, significado);

		PalavraSignificado ps(palavra, significado);

		this->palavras.insert(ps);
	}
}


string Dicionario::consulta(string palavra) const
{
     BSTItrIn<PalavraSignificado> it = this->palavras;

     string pAntes, sAntes, pApos, sApos;

     while(!it.isAtEnd()) {
    	 PalavraSignificado ps = it.retrieve();

    	 if (ps.getPalavra() == palavra)
    		 return ps.getSignificado();
    	 else if (ps.getPalavra() > palavra) {
    		 if (!it.isAtEnd()) {
    			 pApos = it.retrieve().getPalavra();
    			 sApos = it.retrieve().getSignificado();
    		 }
    		 else {
    			 pApos = "";
    			 sApos = "";
    		 }
    		 throw(PalavraNaoExiste(pAntes, sAntes, pApos, sApos));
    	 }

			 pAntes = it.retrieve().getPalavra();
			 sAntes = it.retrieve().getSignificado();
			 it.advance();


     }

     throw(PalavraNaoExiste(pAntes, sAntes, "", ""));
}


bool Dicionario::corrige(string palavra, string significado)
{
	// a alterer
		return true;
}


void Dicionario::imprime() const
{
	BSTItrIn<PalavraSignificado> it = this->palavras;

	while(!it.isAtEnd()) {
		cout << it.retrieve().getPalavra() << endl;
		cout << it.retrieve().getSignificado() << endl;

		it.advance();
	}
}
