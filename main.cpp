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
	vector<Cliente*> Clientes;
	vector<Vehiculo*> Vehiculos;
	int opc, opc2=0,m;
	string User, Password, name, pass, cargo, ihss, marca, modelo, year;
	double precio;

	Administrador* admi = new Administrador("Gerente","12343","abi","1221");
	Administradores.push_back(admi);


	cout << "-------RENTA DE AUTOMOVILES------" << endl;
	cout << "\n----Menu----\n1.Entrar como Administrador \n2.Entrar como Cliente:\n3.Registrar Cliente\n4.Registrar Administrador: ";
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
						cout << "\nIngrese una opción: \n1.Ingresar Autos\n2.Modificar Autos\n3.Eliminar Autos\n4.Salir";
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
								cout << "----MODIFICAR VEHICULO----\n";

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
								cout << "\n-----ELIMINAR VEHICULO----\n";

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
				}else{
					if (i == Administradores.size())
						cout << "\nUSUARIO O CONTRASEÑA INCORRECTOS";
				}
			}//FIN FOR
	//FIN ADMINISTRADOR
	//INICIO LOGIN CLIENTE
	} else if (opc==2){
		cout << "Ingrese usuario: ";
		cin >> User;
		cout << "Ingrese contraseña: ";
		cin >> Password;

		for (int i = 0; i < Clientes.size(); ++i)
		{
			if(User == (Clientes[i])->getNombre() && Password == (Clientes[i])->getPassword()){
				while(opc!=3){
				int opc3, pos2;
				cout << "LOGIN CLIENTE\n";
				i = Clientes.size();
				cout << "Ingrese una opción:\n1.Alquilar Automovil\n2.Guardar Factura: ";
				cin >> opc3;
				if (opc3==1){
					for (int i = 0; i < Vehiculos.size(); ++i)
					{
						cout << i << " " << Vehiculos[i]->getPlaca() << " " << Vehiculos[i]->getMarca() << " " << Vehiculos[i]->getYear() << " " << Vehiculos[i]->getPrecio() << " " << Vehiculos[i]->getEstado() << endl;
					}
					cout << "Ingrese la posición del auto que desea alquilar: ";
					cin >> pos2;
					if (pos2<0||pos2>Vehiculos.size()){
						cout << "\nPOSICION INEXISTENTE";
					}else{
						cout << "Usted Alquilo el auto: " << endl;
						cout << Vehiculos[pos2]->getMarca() << " " << Vehiculos[pos2]->getModelo() << " " << Vehiculos[pos2]->getPrecio();
						Vehiculos[pos2]->setEstado(true);
					}

				//FIN IF ALQUILAR AUTO	
				} else if (opc==2){
					//TODO: ARCHIVO
				}else{
					cout << "OPCION INVALIDA";
				}
			}//FIN WHILE
			}//FINF INGRESO O LOGIN
		}//FIN FOR

	}//FIN CLIENTES



	return 0;
}