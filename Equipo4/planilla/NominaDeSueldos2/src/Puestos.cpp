#include "Puestos.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void Puestos::ingresarPuesto(string n)
{
    system("cls");
    nombre = n;
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	fstream file;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
	cout<<"\n----------------------------------------------- Agregar detalles de Puesto --------------------------------------------"<<endl;
	cout<<"\n\n\t\t\tIngresa nombre del puesto   : ";
	cin>>puesto;
	cout<<"\t\t\tIngrese el salario base         : ";
	cin>>salarioBase;
	file.open("PuestoDeTrabajo.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< puesto <<std::left<<std::setw(15)<< salarioBase << "\n";
	file.close();
	system("pause");
}
void Puestos::visualizarPuesto(string n)
{
    system("cls");
     nombre = n;
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n----------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------Tabla de Detalles de Puestos ----------------------------------------------"<<endl;
	cout<<"\n\tPuesto" <<setw(15)<< "Monto";
	file.open("PuestoDeTrabajo.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> puesto >> salarioBase;
		while(!file.eof())
		{
			total++;
			cout<<"\n\t"<<puesto<<"\t"<<salarioBase;
			file >> puesto >> salarioBase;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	cout << endl;
	system("pause");
}
void Puestos::buscarPuesto(string n)
{
	system("cls");
    nombre = n;
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	fstream file;
	int found=0;
	file.open("PuestoDeTrabajo.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del puesto buscado------------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del puesto buscado------------------------------"<<endl;
		cout<<"\nIngrese el nombre del puesto que quiere buscar: ";
		cin>>participant_id;
		file >> nombre >> salarioBase;
		while(!file.eof())
		{
			if(participant_id==puesto)
			{
				cout<<"\t\t\t Nombre Puesto: "<<nombre<<endl;
				cout<<"\t\t\t Salario correspondiente: "<<salarioBase<<endl;
				found++;
			}
			file >> nombre >> salarioBase;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrado...";
		}
		file.close();
	}
}
