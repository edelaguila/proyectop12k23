#include "InfoEmpleados.h"
#include "Bitacora.h"
#include "Calculos.h"
#include "Planilla.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
Bitacora llamarBitacora5;
Calculos mandarInformacion;
Planilla mandarParametros;
void InfoEmpleados::menu(string n)
{
    nombre2 = n;
    int choice;
	char x;
	do
    {
	system("cls");
    cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	cout<<"\t\t\t--------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PERSONAS - 1600 |"<<endl;
	cout<<"\t\t\t--------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Personas"<<endl;
	cout<<"\t\t\t 2. Despliegue Personas"<<endl;
	cout<<"\t\t\t 3. Modifica Personas"<<endl;
	cout<<"\t\t\t 4. Busca Personas"<<endl;
	cout<<"\t\t\t 5. Borra Personas"<<endl;
	cout<<"\t\t\t 6. Regresar a menu anterior"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		llamarBitacora5.ingresoBitacora(nombre2,"1600", "INS");
    		insertar();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
	    llamarBitacora5.ingresoBitacora(nombre2,"1600", "REA");
		desplegar();
		break;
	case 3:
	    llamarBitacora5.ingresoBitacora(nombre2,"1600", "UPD");
		modificar();
		break;
	case 4:
	    llamarBitacora5.ingresoBitacora(nombre2,"1600", "SEA");
		buscar();
		break;
	case 5:
	    llamarBitacora5.ingresoBitacora(nombre2,"1600", "DEL");
		borrar();
		break;
	case 6:
		return;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void InfoEmpleados::insertar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	string participant_id;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n------------------------------------------------- Agregar detalles Persona ---------------------------------------------"<<endl;
    cout<<"\n\t\t\tIngresa Id Persona         : ";
    cin>>id;
    cout<<"\t\t\tIngresa Nombre Persona     : ";
    cin>>nombre;
    cout<<"\t\t\tIngresa Telefono Persona   : ";
    cin>>telefono;
    cout<<"\t\t\tIngresa Direccion Persona  : ";
    cin>>direccion;
    cout<<"\t\t\tIngresa Puesto Persona     : ";
    cin>>puesto;
    file.open("RegistroEmpleados.txt",ios::app | ios::out);
    file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto << "\n";
    cout << endl;
    system("pause");
    mandarInformacion.calculoSueldo(id, nombre, puesto);
    file.close();
}
void InfoEmpleados::desplegar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	cout<<"\n\n\tId\tNombre\t\tTelefono\tDireccion\tPuesto\n\n";
	file.open("RegistroEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono >> direccion >> puesto;
		while(!file.eof())
		{
			total++;
			cout<<"\t"<<id<<"\t"<<nombre<<"\t\t"<<telefono<<"\t\t"<<direccion<<"\t\t"<<puesto<<endl;
			file >> id >> nombre >> telefono >> direccion >> puesto;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void InfoEmpleados::modificar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("RegistroEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la persona que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono >> direccion >> puesto;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto << "\n";
            }
			else
			{
				cout<<"\t\t\tId de la persona          : "<<id;
				cout<<"\n\t\t\tIngrese Nombre Persona   : ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Telefono Persona  : ";
				cin>>telefono;
				cout<<"\t\t\tIngrese Direccion Persona : ";
				cin>>direccion;
				cout<<"\t\t\tPuesto persona(NO ACTIVO) : "<<puesto;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto << "\n";
				found++;
			}
			file >> id >> nombre >> telefono >> direccion >> puesto;

		}
		if(found==0)
        {
            cout<<"\n\t\tEmpleado no encontrado..."<<endl;
        }
		file1.close();
		file.close();
		remove("RegistroEmpleados.txt");
		rename("Record.txt","RegistroEmpleados.txt");
	}
	id = participant_id;
	mandarParametros.modificarDPPlanilla(id, nombre);
	cout<<endl;
	system("pause");
}
void InfoEmpleados::buscar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int found=0;
	file.open("RegistroEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono >> direccion >> puesto;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Persona     : "<<id<<endl;
				cout<<"\t\t\t Nombre Persona     : "<<nombre<<endl;
				cout<<"\t\t\t Telefono Persona   : "<<telefono<<endl;
				cout<<"\t\t\t Direccion Persona  : "<<direccion<<endl;
				cout<<"\t\t\t Puesto Persona     : "<<puesto<<endl;
				found++;
			}
			file >> id >> nombre >> telefono >> direccion >> puesto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
	system("pause");
}
void InfoEmpleados::borrar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<endl;
	file.open("RegistroEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono >> direccion >> puesto;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto << "\n";
			}
			else
			{
				found++;
			}
			file >> id >> nombre >> telefono >> direccion >> puesto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("RegistroEmpleados.txt");
		rename("Record.txt","RegistroEmpleados.txt");
	}
	id = participant_id;
	mandarParametros.borrarPlanilla(id);
	cout<<endl;
	system("pause");
}
