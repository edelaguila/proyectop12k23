#include "Aplicaciones.h"
#include "Bitacora.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;
Bitacora llamarBitacora4;

void Aplicaciones::menu(string n)
{
    nombre2 = n;
    int choice;
	char x;
	do
    {
	system("cls");
    cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	cout<<"\t\t\t--------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF - Aplicaciones - 1700  |"<<endl;
	cout<<"\t\t\t--------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar aplicacion"<<endl;
	cout<<"\t\t\t 2. Despliegue aplicaciones"<<endl;
	cout<<"\t\t\t 3. Modificar aplicacion"<<endl;
	cout<<"\t\t\t 4. Buscar aplicacion"<<endl;
	cout<<"\t\t\t 5. Borrar aplicacion"<<endl;
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
    		llamarBitacora4.ingresoBitacora(nombre2,"1700", "INS");
    		insertar();
    		cout<<"\n\t\t\t Agrega otra aplicacon(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		llamarBitacora4.ingresoBitacora(nombre2,"1700", "REA");
		desplegar();
		break;
	case 3:
		llamarBitacora4.ingresoBitacora(nombre2,"1700", "UPD");
		modificar();
		break;
	case 4:
		llamarBitacora4.ingresoBitacora(nombre2,"1700", "SEA");
		buscar();
		break;
	case 5:
		llamarBitacora4.ingresoBitacora(nombre2,"1700", "DEL");
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
void Aplicaciones::insertar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles de Aplicacion ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id de la aplicacion         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre de la aplicacion     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa estado de la aplicacion (ACTIVO / NO ACTIVO)   : ";
	cin>>estado;
	file.open("Aplicaciones.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estado << "\n";
	file.close();
}
void Aplicaciones::desplegar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Aplicaciones -------------------------"<<endl;
	file.open("Aplicaciones.txt",ios::in);
	cout<<"\n\n\tId\tAplicacion\tEstado\n\n";
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> estado;
		while(!file.eof())
		{
			total++;
			cout<<"\t"<<id<<"\t"<<nombre<<"\t"<<estado<<endl;
			file >> id >> nombre >> estado;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void Aplicaciones::modificar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles de una Aplicaciones-------------------------"<<endl;
	file.open("Aplicaciones.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la aplicacion que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> estado;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estado << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id de la Aplicacion: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre de la Aplicacion: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Estado de la Aplicacion: ";
				cin>>estado;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estado << "\n";
				found++;
			}
			file >> id >> nombre >> estado;

		}
		file1.close();
		file.close();
		remove("Aplicaciones.txt");
		rename("Record.txt","Aplicaciones.txt");
	}
}
void Aplicaciones::buscar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int found=0;
	file.open("Aplicaciones.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Aplicacion buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de la Aplicacion buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Aplicacion que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> estado;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Aplicacion: "<<id<<endl;
				cout<<"\t\t\t Nombre Aplicacion: "<<nombre<<endl;
				cout<<"\t\t\t Estado Aplicacion: "<<estado<<endl;
				found++;
			}
			file >> id >> nombre >> estado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Aplicacion no encontrada...";
		}
		file.close();
	}
}
void Aplicaciones::borrar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles de la Aplicacion a Borrar-------------------------"<<endl;
	file.open("Aplicacion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Aplicacion que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> estado;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estado << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de aplicacion exitoso";
			}
			file >> id >> nombre >> estado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id de Aplicacion no encontrado...";
		}
		file1.close();
		file.close();
		remove("Aplicacion.txt");
		rename("Record.txt","Aplicacion.txt");
	}
}



