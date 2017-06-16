#include "Usuario.h"
#include "Vehiculo.h"
#include "Cliente.h"
#include "Administrador.h"
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <stdlib.h>
#include <time.h>

string Placa();

int main(){

	vector<Usuario*> Usuarios;
	vector<Administrador*> Administradores;
	vector<Cliente*> Clientes;
	vector<Vehiculo*> Vehiculos;
	ofstream archivo;
	ifstream myfile;
	int opc, opc2=0,m, cont=0;
	char resp = 's';
	string User, Password, name, pass, cargo, ihss, marca, modelo, year;
	double precio;

	Administrador* admi = new Administrador("Gerente","12343","abi","1221");
	Administradores.push_back(admi);
	Cliente* Client = new Cliente("Gold", "Abi", "1221");
	Clientes.push_back(Client);
	

	//****CARGAR ARCHIVO*************
	/*myfile.open("Reporte.dat", ios::binary);

		while(!myfile.eof()&&!myfile.fail()){
			cout << "HOLAAAAAAAAAAAAAAA";
			Vehiculo* veh = new Vehiculo("op","op","op","op", 0.00,0);
			veh->read(myfile);
			Vehiculos.push_back(veh);
			cout << "la placa es:"<< veh->getPlaca();
			}
		
			
		
	myfile.close();
	cout << Vehiculos.size();*/


	while (resp == 's' || resp == 'S'){

	cout << "-------RENTA DE AUTOMOVILES------" << endl;
	cout << "\n----Menu----\n1.Entrar como Administrador \n2.Entrar como Cliente:\n3.Registrar Administrador\n4.Registrar Cliente\n5.Generar e Imprimir Reporte de Autos ";
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
						string placa;
						i = Administradores.size();
						while (opc2!=4){
						cout << "\nIngrese una opción: \n1.Ingresar Autos\n2.Modificar Autos\n3.Eliminar Autos\n4.Salir ";
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
								placa = Placa();
								Vehiculo* V = new Vehiculo(placa, marca, modelo, year, precio, false);
								Vehiculos.push_back(V);
								

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
				} else if (opc3==2){
					string status;
					archivo.open(User.c_str());

				if (Vehiculos[i]->getEstado()==false){
						status = "NoAlquilado";
				}else{
					status = "Alquilado";
				}
					archivo << "-----FACTURACIÓN----" << endl;
					archivo << Vehiculos[pos2]->getMarca() << " " << Vehiculos[pos2]->getModelo() << " " << Vehiculos[pos2]->getYear() << " " << status << endl;
					archivo << "Total a Pagar:        L.   " << Vehiculos[pos2]->getPrecio();
					archivo.close();
				}else{
					cout << "OPCION INVALIDA";
				}

			}//FIN WHILE
			}//FINF INGRESO O LOGIN
		}//FIN FOR

	//FIN CLIENTES
	//INICIO REGISTRO DE ADMINISTRADORES
	}else if(opc==3){
		cout << "Ingrese nombre: ";
		cin >> name;
		cout << "Ingrese Contraseña: ";
		cin >> pass;
		cout << "Ingrese Cargo: ";
		cin >> cargo;
		cout << "Ingrese IHSS: ";
		cin >> ihss;
		Administrador* adm = new Administrador(cargo, ihss, name, pass);
		Administradores.push_back(adm);
		

	//FIN REGISTRO DE ADMINISTRADORES
	//INICIO REGISTRO DE CLIENTES
	}else if (opc==4){
		string member;
		cout << "Ingrese nombre: ";
		cin >> name;
		cout << "Ingrese Contraseña: ";
		cin >> pass;
		cout << "Que tipo de membresia tiene?\n1.Normal\n2.Platinum\n3.Gold ";
		cin >> m;

		if (m==1){
			member = "Normal";
		}else if (m==2){
			member = "Platinum";
		}else{
			member = "Gold";
		}
		Cliente* Cost = new Cliente(member,name,pass);
		Clientes.push_back(Cost);
	//FIN REGISTRO DE CLIENTES
	//REPORTE
	}else if (opc==5){
		string status;
		archivo.open("Reporte.txt");
		archivo << "---REPORTE VEHICULOS---" << endl << endl;

		for (int i = 0; i < Vehiculos.size(); ++i)
		{
			if (Vehiculos[i]->getEstado()==false){
				status = "NoAlquilado";
			}else{
				status = "Alquilado";
			}
			archivo << Vehiculos[i]->getPlaca() << " " << Vehiculos[i]->getMarca() << " " << Vehiculos[i]->getYear() << " " << Vehiculos[i]->getPrecio() << " " << status << endl;
			cout << i << " " << Vehiculos[i]->getPlaca() << " " << Vehiculos[i]->getMarca() << " " << Vehiculos[i]->getYear() << " " << Vehiculos[i]->getPrecio() << " " << status << endl;
		}
		archivo.close();

		archivo.open("Reporte.dat", ios::binary);
		for (int i = 0; i < Vehiculos.size(); ++i)
		{
			if (Vehiculos[i]!=NULL){
				Vehiculos[i]->write(archivo);
			}
		}

		archivo.close();



	}else{
		cout << "\nOPCION INVALIDA";
	}
	cout << "Desea seguir en el programa? ";
	cin >> resp;

}//FIN WHILE



	return 0;
}

string Placa(){
	int num;
	string numero = "";
	string letras[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	string number[10] = {"1","2","3","4","5","6","7","8","9","0"};

	for (int i = 0; i < 3; ++i)
	{
		num = rand()%27;
		numero = numero + letras[num];
	}

	for(int i=0; i<3; i++){
		num = rand()%10;
		numero = numero + number[num];
	}

return numero;

}