#include "Usuario.h"

Usuario::Usuario( string Nombre,  string Password) {
	this-> Nombre=Nombre;
	this-> Password=Password;
}


string Usuario::getNombre(){

return Nombre;
}

void Usuario::setNombre(string Nombre){
	this->Nombre =Nombre;
}

string Usuario::getPassword(){

return Password;
}

void Usuario::setPassword(string Password){
	this->Password =Password;
}
