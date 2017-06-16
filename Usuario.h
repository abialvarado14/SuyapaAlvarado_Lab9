#pragma once

#include <string>
using namespace std;

class Usuario{

protected:

	string Nombre;
	string Password;

public:

	Usuario(string, string);
	string getNombre();
	void setNombre(string Nombre);
	string getPassword();
	void setPassword(string Password);
	virtual ~Usuario();


};
