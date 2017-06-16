#pragma once

#include <string>

using namespace std;

class Vehiculo{

protected:

	string Placa;
	string Marca;
	string Modelo;
	string Year;
	double Precio;

public:

	Vehiculo(string, string, string, string, double);
	string getPlaca();
	void setPlaca(string Placa);
	string getMarca();
	void setMarca(string Marca);
	string getModelo();
	void setModelo(string Modelo);
	string getYear();
	void setYear(string Year);
	double getPrecio();
	void setPrecio(double Precio);


};
