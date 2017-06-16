#include "Cliente.h"

Cliente::Cliente( string Membresia, string Nombre, string Password): Usuario(Nombre,Password) {
	this-> Membresia=Membresia;
	this->Nombre=Nombre;
	this->Password=Password;
}

string Cliente::getMembresia(){

return Membresia;
}

void Cliente::setMembresia(string Membresia) {
	this->Membresia =Membresia;
	
}

Cliente::~Cliente(){
	
}
