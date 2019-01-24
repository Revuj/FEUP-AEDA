#include "Veiculo.h"
#include <iostream>

using namespace std;


//VEICULO
Veiculo::Veiculo(string mc, int m, int a)
{
	marca = mc;
	mes = m;
	ano = a;
}

int Veiculo::getAno() const
{
	return ano;
}

string Veiculo::getMarca() const
{
	return marca;
}

int Veiculo::info() const
{
	cout << "Marca = " << marca << endl;
	cout << "Ano = " << ano << endl;
	cout << "Mes = " << mes << endl;
	return 3;
}

bool Veiculo::operator < (const Veiculo & v) const
{
	if ((this->ano < v.ano) || (this->ano == v.ano && this->mes < v.mes))
		return true;
	else
		return false;
}

//MOTORIZADO
Motorizado::Motorizado(string mc, int m, int a,string c,int cil) : Veiculo(mc, m, a)
{
	combustivel = c;
	cilindrada = cil;
}


string Motorizado::getCombustivel() const
{
	return combustivel;
}

int Motorizado::info() const
{
	int infoV = Veiculo::info();
	cout << "Combustivel = " << combustivel << endl;
	cout << "Cilindrada = " << cilindrada << endl;
	return infoV + 2;
}

float Motorizado::calcImposto() const
{
	if (combustivel == "gasolina")
	{
		if (cilindrada <= 1000)
		{
			if (ano > 1995)
				return 14.56;
			else
				return 8.10;
		}
		else if (cilindrada <= 1300)
		{
			if (ano > 1995)
				return 29.06;
			else
				return 14.56;
		}
		else if (cilindrada <= 1750)
		{
			if (ano > 1995)
				return 45.15;
			else
				return 22.65;
		}
		else if (cilindrada <= 2600)
		{
			if (ano > 1995)
				return 113.98;
			else
				return 54.89;
		}
		else if (cilindrada <= 3500)
		{
			if (ano > 1995)
				return 181.17;
			else
				return 87.13;
		}
		else
		{
			if (ano > 1995)
				return 320.89;
			else
				return 148.37;
		}
	}
	else
	{
		if (cilindrada <= 1500)
		{
			if (ano > 1995)
				return 14.56;
			else
				return 8.10;
		}
		else if (cilindrada <= 2000)
		{
			if (ano > 1995)
				return 29.06;
			else
				return 14.56;
		}
		else if (cilindrada <= 3000)
		{
			if (ano > 1995)
				return 45.15;
			else
				return 22.65;
		}
		else
		{
			if (ano > 1995)
				return 113.98;
			else
				return 54.89;
		}
	}

}



//AUTOMOVEL
Automovel::Automovel(string mc, int m, int a,string c, int cil) : Motorizado(mc, m, a, c, cil)
{

}

int Automovel::info() const
{
		int infoM = Motorizado::info();
		return infoM;
}



//CAMIAO
Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm) : Motorizado(mc, m, a, c, cil)
{
	carga_maxima = cm;
}

int Camiao::info() const
{
		int infoM = Motorizado::info();
		cout << "Carga Maxima = " << carga_maxima << endl;
		return infoM + 1;
}

//BICICLETA
Bicicleta::Bicicleta(string mc, int m, int a,string t) : Veiculo(mc, m, a)
{
	tipo = t;
}

int Bicicleta::info() const
{
		int infoV = Veiculo::info();
		cout << "Tipo = " << tipo << endl;
		return infoV + 1;
}

float Bicicleta::calcImposto() const
{
	return 0;
}
