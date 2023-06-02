#include "Empleados.h"
#include "Usuario.h"
#include "Bitacora.h"
#include "Planilla.h"
#include "InfoEmpleados.h"
#include <ctime>
#include <fstream>
#include <iomanip>
Bitacora llamarBitacora3;
Planilla pagoempleado;
InfoEmpleados verinfo;

void Empleados::menuGeneralEmpleados(string n)
{
    system("cls");
    nombre = n;
    int choice2;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados |"<<endl;
	cout<<"\t\t\t-------------------------------------"<<endl;
	cout<<"\t\t\t 1). Informacion personal laboral "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). LOG OUT"<<endl;
		cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice2;

        switch(choice2)
        {
            case 1:
                infopersonalEmpleados(nombre);
                break;
            case 2:
                procesoEmpleados(nombre);
                break;
            case 3:
                informesEmpleados(nombre);
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
	system("cls");
    }while(choice2!= 4);
}
void Empleados::infopersonalEmpleados(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados - Informacion personal laboral - 900 |"<<endl;
	cout<<"\t\t\t--------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Informacion Personal "<<endl;
	cout<<"\t\t\t 2. Procesos Diciplinarios "<<endl;
	cout<<"\t\t\t 3. Rendimiento "<<endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora3.ingresoBitacora(nombre,"900", "RIP");
                verinfo.buscar();
                break;
            case 2:
                llamarBitacora3.ingresoBitacora(nombre,"900", "RPE");
                cout << "\n\t\t\tDebe solicitarlo personalmente en oficinas  " << endl;
                system("pause");
                break;
            case 3:
                llamarBitacora3.ingresoBitacora(nombre,"900", "RPD");
                cout << "\n\t\t\tinformacion no disponible por el momento " << endl;
                system("pause");
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 4);
}
void Empleados::procesoEmpleados(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t---------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados -   Proceso - 1000  |"<<endl;
	cout<<"\t\t\t---------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Solicitar nuevo puesto "<<endl;
	cout<<"\t\t\t 2. Solicitar horas extras "<<endl;
	cout<<"\t\t\t 3. Servicio de ayuda "<<endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora3.ingresoBitacora(nombre,"1000", "SNP");
                cout << "\n\t\t\tDebe solicitarlo personalmente en oficinas  " << endl;
                system("pause");
                break;
            case 2:
                llamarBitacora3.ingresoBitacora(nombre,"1000", "RPD");
                cout << "\n\t\t\tNo hay horas extras disponibles por el momento  " << endl;
                system("pause");
                break;
            case 3:
                llamarBitacora3.ingresoBitacora(nombre,"1000", "SHE");
                cout << "\n\t\t\t| Ext. 62541  | Oficina central - 704 |" << endl;
                system("pause");
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 4);
}
void Empleados::informesEmpleados(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados -   Informes   - 1100|"<<endl;
	cout<<"\t\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. visualizar nomina de pago "<<endl;
	cout<<"\t\t\t 2. Visualizar descuentos aplicados "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora3.ingresoBitacora(nombre,"1100", "VNP");
                pagoempleado.buscarpago();
                break;
            case 2:
                llamarBitacora3.ingresoBitacora(nombre,"1100", "VPE");
                cout <<"\t\t\tDescuentos aplicados: " << endl;
                cout <<"\n\t\t\t descuentos segun codigo de trabajo de Guatemala |IGSS, ISR, IRTRA| no hay descuentos extras" << endl;
                system("pause");
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 3);
}
