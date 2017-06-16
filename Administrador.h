#pragma once
#include "Usuario.h"
#include <string>
using namespace std;

class Administrador : public Usuario{

protected:

	string cargo;
	string Seguro;

public:

	Administrador(string, string, string, string);
	string getcargo();
	void setcargo(string cargo);
	string getSeguro();
	void setSeguro(string Seguro);
	~Administrador();
};
