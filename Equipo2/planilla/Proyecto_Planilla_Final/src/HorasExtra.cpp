#include "HorasExtra.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puestos.h"

using namespace std;

void HorasExtra::menuHorasExtra()
{
    fstream file;
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

    double salarioDiario;
    double valorHoraNormal;
    double valorHoraExtra;


    salarioDiario = salarioPuesto / 30;
	valorHoraNormal = salarioDiario / 8;
	valorHoraExtra = valorHoraNormal * 1.5;

    cout <<"\n\t\t\tSalario diario es : "<< salarioDiario<< endl;
    cout <<"\n\t\t\tValor hora normal es : "<< valorHoraNormal<< endl;
    cout <<"\n\t\t\tValor hora extra es: "<< valorHoraExtra<< endl;


    file.open("HorasExtra.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< salarioDiario <<std::left<<std::setw(15)<< valorHoraNormal << std::left<<std::setw(15)<< valorHoraExtra <<"\n";
    file.close();

    double bonificacion = 250;

    cout <<"\n\t\t\tBonificacion: "<< bonificacion<< endl;

    file.open("Bonificacion.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< bonificacion <<"\n";
    file.close();


	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}
