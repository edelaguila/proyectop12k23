#include "Porcentajes.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puestos.h"


using namespace std;
void Porcentajes::menuporcentajes()
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
    double porcentajeIgss = (4.83/100);
    double porcentajeIsr = 0.05;
    double porcentajeSeguro = 0.02;

	cout<<"\n\t\t\tPorcentaje igss: " << porcentajeIgss <<endl;
    cout <<"\n\t\t\tPorcentaje isr: "<< porcentajeIsr << endl;
    cout <<"\n\t\t\tPorcentaje seguro: "<< porcentajeSeguro << endl;

  file.open("valores.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< porcentajeIgss <<std::left<<std::setw(15)<< porcentajeIsr <<std::left<<std::setw(15)<< porcentajeSeguro<<"\n";
    file.close();

	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
}




