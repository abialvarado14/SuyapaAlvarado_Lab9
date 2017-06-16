#pragma once
#include "Usuario.h"

#include <string>
using namespace std;

class Cliente : public Usuario{

protected:

	string Membresia;

public:

	Cliente(string, string, string);
	string getMembresia();
	void setMembresia(string Membresia);
	~Cliente();

};

