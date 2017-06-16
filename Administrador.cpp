#include "Administrador.h"


Administrador::Administrador( string cargo,  string Seguro, string Nombre, string Password) : Usuario(Nombre, Password) {
	this-> cargo=cargo;
	this-> Seguro=Seguro;
	this->Nombre=Nombre;
	this->Password=Password;
}


string Administrador::getcargo(){

return cargo;
}

void Administrador::setcargo(string cargo){
	this->cargo =cargo;
}

string Administrador::getSeguro(){

return Seguro;
}

void Administrador::setSeguro(string Seguro){
	this->Seguro =Seguro;
}

Administrador::~Administrador(){
	
}
