#include "Vehiculo.h"

Vehiculo::Vehiculo( string Placa,  string Marca,  string Modelo,  string Year,  double Precio, bool Estado) {
	this-> Placa=Placa;
	this-> Marca=Marca;
	this-> Modelo=Modelo;
	this-> Year=Year;
	this-> Precio=Precio;
	this-> Estado=Estado;
}


string Vehiculo::getPlaca(){

return Placa;
}

void Vehiculo::setPlaca(string Placa){
	this->Placa =Placa;
}

string Vehiculo::getMarca(){

return Marca;
}

void Vehiculo::setMarca(string Marca){
	this->Marca =Marca;
}

string Vehiculo::getModelo(){

return Modelo;
}

void Vehiculo::setModelo(string Modelo){
	this->Modelo =Modelo;
}

string Vehiculo::getYear(){

return Year;
}

void Vehiculo::setYear(string Year){
	this->Year =Year;
}

double Vehiculo::getPrecio(){

return Precio;
}

void Vehiculo::setPrecio(double Precio){
	this->Precio =Precio;
}

bool Vehiculo::getEstado(){

return Estado;
}

void Vehiculo::setEstado(bool Estado){
	this->Estado =Estado;
}
