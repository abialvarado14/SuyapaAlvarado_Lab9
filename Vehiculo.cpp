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

void Vehiculo::write(ofstream& out){
	out.write(reinterpret_cast<char*>(&Placa), sizeof(Placa));
	out.write(reinterpret_cast<char*>(&Marca), sizeof(Marca));
	out.write(reinterpret_cast<char*>(&Modelo), sizeof(Modelo));
	out.write(reinterpret_cast<char*>(&Year), sizeof(Year));
	out.write(reinterpret_cast<char*>(&Estado), sizeof(Estado));
}

void Vehiculo::read(ifstream& in){
	in.read(reinterpret_cast<char*>(&Placa), sizeof(Placa));
	in.read(reinterpret_cast<char*>(&Marca), sizeof(Marca));
	in.read(reinterpret_cast<char*>(&Modelo), sizeof(Modelo));
	in.read(reinterpret_cast<char*>(&Year), sizeof(Year));
	in.read(reinterpret_cast<char*>(&Estado), sizeof(Estado));
}



