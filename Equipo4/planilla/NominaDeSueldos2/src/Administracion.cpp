#include "Administracion.h"
#include "Usuario.h"
#include "Bitacora.h"
#include "Aplicaciones.h"
#include "InfoEmpleados.h"
#include "Puestos.h"
#include "Planilla.h"
#include <ctime>
#include <fstream>
#include <iomanip>
Bitacora llamarBitacora2;
Aplicaciones funcionesAplicaciones;
InfoEmpleados InformacionEm;
Usuario ingresoUsuario;
Puestos mandarUsuario;
Planilla llamarFP;
void Administracion::menuGeneralSTAFF(string n)
{
    system("cls");
    int choice1;
    nombre = n;
	do
    {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1). Catalogos "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). LOG OUT"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice1;

    switch(choice1)
    {
    case 1:
        catalogosSTAFF();
		break;
	case 2:
	    procesoSTAFF();
		break;
	case 3:
	    infomesSTAFF();
		break;
    case 4:
		return;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
	system("cls");
    }while(choice1!= 8);
}
void Administracion::catalogosSTAFF()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF - Catalogos - 1200 |"<<endl;
	cout<<"\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Usuarios "<<endl;
	cout<<"\t\t\t 2. Empleados "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                ingresoUsuario.menuSecundario();
                break;
            case 2:
                InformacionEm.menu(nombre);
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!=3);
}
void Administracion::procesoSTAFF()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Procesos  - 1300 |"<<endl;
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Puestos "<<endl;
	cout<<"\t\t\t 2. Aplicaciones "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                puestos();
                break;
            case 2:
                funcionesAplicaciones.menu(nombre);
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 3);
}
void Administracion::infomesSTAFF()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Informes  - 1400 |"<<endl;
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Planilla "<<endl;
	cout<<"\t\t\t 2. Bitacora "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                planilla();
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1400", "REA");
                llamarBitacora2.visualizarBitacora(nombre);
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 3);
}
void Administracion::puestos()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t---------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -  Puestos - 1900 |"<<endl;
	cout<<"\t\t\t---------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Insertar Puesto "<<endl;
	cout<<"\t\t\t 2. Visualizar Puestos "<<endl;
	cout<<"\t\t\t 3. Buscar Puesto "<<endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"1900", "INS");
                mandarUsuario.ingresarPuesto(nombre);
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1900", "REA");
                mandarUsuario.visualizarPuesto(nombre);
                break;
            case 3:
                llamarBitacora2.ingresoBitacora(nombre,"1900", "SEA");
                mandarUsuario.buscarPuesto(nombre);
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 4);
}
void Administracion::planilla()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -  Planilla - 2000 |"<<endl;
	cout<<"\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Visualizar planilla "<<endl;
	cout<<"\t\t\t 2. Buscar empleado en planilla "<<endl;
	cout<<"\t\t\t 3. Modificar planilla " << endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"2000", "REA");
                llamarFP.leerPlanilla(nombre);
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"2000", "SEA");
                llamarFP.buscarPlanilla(nombre);
                break;
            case 3:
                llamarBitacora2.ingresoBitacora(nombre,"2000", "UPD");
                llamarFP.modificarPlanilla(nombre);
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!=4);
}
