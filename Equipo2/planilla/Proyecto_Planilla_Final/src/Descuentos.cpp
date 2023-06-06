#include "Descuentos.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puestos.h"
#include "Porcentajes.h"
#include "HorasExtra.h"

using namespace std;

void Descuentos::menuDescuentos()
{

	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Calculo Descuentos ---------------------------------------------"<<endl;
    fstream file;
	int found=0;
	file.open("Puestos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		double participant_id;
		cout<<"\nIngrese Id del Puesto que quiere buscar: ";
		cin>>participant_id;
		file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		while(!file.eof())
		{
			if(participant_id==idPuesto)
			{
				cout<<"\n\n\t\t\t Id Puesto        : "<<idPuesto<<endl;
                cout<<"\n\n\t\t\t Nombre Puesto        : "<<nombrePuesto<<endl;
                cout<<"\t\t\t Encargado Puesto         : "<<encargadoPuesto<<endl;
                cout<<"\t\t\t Profesion del Encargado  : "<<tituloPuesto<<endl;
                cout<<"\t\t\t Salario del Puesto       : "<<salarioPuesto<<endl;
				found++;
			}
			file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Puesto no encontrada...";
		}
		file.close();
	}

    file.open("valores.txt",ios::in);
    file >> porcentajeigss >>porcentajeIsr >> porcentajeSeguro;
    {
    totalIgss = (salarioPuesto * porcentajeigss);
    cout <<"\t\t\t\tTotal IGSS: "<< totalIgss<<endl;
    totalIsr = (salarioPuesto * porcentajeIsr);
    cout <<"\t\t\t\tTotal ISR: " << totalIsr << endl;
    totalSeguro = (salarioPuesto * porcentajeSeguro);
    cout <<"\t\t\t\tTotal seguro: " << totalSeguro<<endl;
    totalDescuentos = totalIgss + totalIsr + totalSeguro;
    cout <<"\t\t\t\tTotal descuentos: "<<totalDescuentos<<endl;
    cout<<"\n"<<endl;
    file.close();
	}
	file.open("descuentos.txt",ios::app | ios::out);
	file<<std::left<<setw(15)<<totalIgss<<std::left<<setw(15)<<totalIsr<<std::left<<setw(15)<<totalSeguro<<std::left<<setw(15)<<totalDescuentos<<"\n";
	file.close();
}
void Descuentos::menuHorasExtra()
{
    system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Calculo Horas Extra ---------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa Horas Trabajadas: ";
	cin>> horasTrabajadas;

    file.open("HorasExtra.txt",ios::in);
    file >> salarioDiario >> valorHoraNormal >> valorHoraExtra;
    {
        cout <<"\t\t\t\tHoras Trabajadas: "<< horasTrabajadas<<endl;
        totalHoras = horasTrabajadas * valorHoraExtra;
        cout <<"\t\t\t\tPago por Horas Extra: "<<totalHoras<<endl;
    file.close();
	}
	file.open("descuentos.txt",ios::app | ios::out);
	file<<std::left<<setw(15)<<salarioDiario<<std::left<<setw(15)<<valorHoraNormal<<std::left<<setw(15)<<valorHoraExtra<<"\n";
	file.close();
}

void Descuentos::menuTotalPago()
{
    system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Calculo Sueldo Total ---------------------------------------------"<<endl;
    file.open("Puestos.txt",ios::in);
    file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
    {
    cout<<"\n\n\t\t\t Id Puesto           : "<<idPuesto<<endl;
			cout<<"\t\t\t Nombre Puesto           : "<<nombrePuesto<<endl;
			cout<<"\t\t\t Encargado del Puesto    : "<<encargadoPuesto<<endl;
			cout<<"\t\t\t Profesion del Encargado : "<<tituloPuesto<<endl;
			cout<<"\t\t\t Salario del Puesto       : "<<salarioPuesto<<endl;
    file.close();
    }

	file.open("HorasExtra.txt",ios::in);
    file >> bonificacion;
    {
        totalSueldo = (salarioPuesto - totalDescuentos) + totalHoras + bonificacion;
        cout <<"\n\t\t\t Total a pagarle es: " << totalSueldo <<endl;
    file.close();
	}

	file.open("descuentos.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< totalSueldo << "\n";
	file.close();
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}

