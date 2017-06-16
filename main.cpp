#include "Usuario.h"
#include "Vehiculo.h"
#include "Cliente.h"
#include "Administrador.h"
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

int main(){

	vector<Usuario*> Usuarios;
	vector<Administrador*> Administradores;
	vector<Vehiculo*> Vehiculos;
	int opc, opc2=0,m;
	string User, Password, name, pass, cargo, ihss, marca, modelo, year;
	double precio;

	Administrador* admi = new Administrador("Gerente","12343","abi","1221");
	Administradores.push_back(admi);


	cout << "-------RENTA DE AUTOMOVILES------" << endl;
	cout << "Como que tipo de usuario desea entrar?: \n1.Administrador \n2.Cliente: ";
	cin >> opc;

	if (opc==1){
		cout << "Ingrese usuario: ";
		cin >> User;
		cout << "Ingrese contraseña: ";
		cin >> Password;
			//.........LOGIN............
			for (int i = 0; i < Administradores.size(); ++i)
			{
				if(User == (Administradores[i])->getNombre() && Password == (Administradores[i])->getPassword()){
						cout << "----LOGIN ADMI----\n" << endl;
						i = Administradores.size();
						while (opc2!=4){
						cout << "Ingrese una opción: \n1.Ingresar Autos\n2.Modificar Autos\n3.Eliminar Autos";
						cin >> opc2;

						switch(opc2){
							case 1:{
								cout << "Ingrese Marca: ";
								cin >> marca;
								cout << "Ingrese Modelo: ";
								cin >> modelo;
								cout << "Ingrese Año: ";
								cin >> year;
								cout << "Ingrese precio:";
								cin >> precio;
								Vehiculo* V = new Vehiculo("AA029", marca, modelo, year, precio, false);
								Vehiculos.push_back(V);
								/*cout << "Ingrese nombre: ";
								cin >> name;
								cout << "Ingrese Contraseña: ";
								cin >> pass;
								cout << "Ingrese Cargo: ";
								cin >> cargo;
								cout << "Ingrese IHSS: ";
								cin >> ihss;
								Administrador* adm = new Administrador(cargo, ihss, name, pass);
								Administradores.push_back(adm);*/

							break;	
							}//FIN AGREGAR VEHICULO

							case 2:{
								int pos;
								cout << "----MODIFICAR VEHICULO----";

									for (int i = 0; i < Vehiculos.size(); ++i)
									{
										cout << i << " " << Vehiculos[i]->getPlaca() << " " << Vehiculos[i]->getMarca() << " " << Vehiculos[i]->getYear() << " " << Vehiculos[i]->getPrecio() << " " << Vehiculos[i]->getEstado() << endl;
									}
								cout << "Ingrese la posicion a modificar: ";
								cin >> pos;
								if (pos<0 || pos > Vehiculos.size()){

									cout << "POSICION INEXISTENTE.";
								}else{

									cout << "Ingrese Marca: ";
									cin >> marca;
									cout << "Ingrese Modelo: ";
									cin >> modelo;
									cout << "Ingrese Año: ";
									cin >> year;
									cout << "Ingrese precio:";
									cin >> precio;
									Vehiculos[pos]->setMarca(marca);
									Vehiculos[pos]->setModelo(modelo);
									Vehiculos[pos]->setYear(year);
									Vehiculos[pos]->setPrecio(precio);
									cout << "MODIFICACION REALIZADA!";
								}//VALIDACION MODIFICACION
							break;
							}
							//FIN MODIFICAR VEHICULO

							case 3:{
								int pos;
								cout << "-----ELIMINAR VEHICULO----";

								for (int i = 0; i < Vehiculos.size(); ++i)
									{
										cout << i << " " << Vehiculos[i]->getPlaca() << " " << Vehiculos[i]->getMarca() << " " << Vehiculos[i]->getYear() << " " << Vehiculos[i]->getPrecio() << " " << Vehiculos[i]->getEstado() << endl;
									}
								cout << "Ingrese la posicion a eliminar: ";
								cin >> pos;
								if (pos<0 || pos > Vehiculos.size())
									cout << "POSICION INEXISTENTE.";
								else
									Vehiculos.erase(pos+Vehiculos.begin());
								

							break;	
							}

						}//FIN SWITCH MENU DE ADMINISTRADORES
					}//WHILE
				}
			}//FIN FOR


	}//FIN ADMINISTRADOR



	return 0;
}