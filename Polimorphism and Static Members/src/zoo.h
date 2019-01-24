#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>
#include <string>
#include <iostream>


class Zoo {
	vector<Animal *> animais;
	vector<Veterinario *> veterinarios;
public:
	int numAnimais() const;
	int numVeterinarios() const;
	void adicionaAnimal (Animal *al);
	string getInformacao() const;
	bool animalJovem(string nomeA);
	void alocaVeterinarios(istream &isV);
	bool removeVeterinario (string nomeV);
	bool operator < (Zoo& zoo2) const;
	int somaIdades() const;
	//completar
};


#endif /* ZOO_H_ */
