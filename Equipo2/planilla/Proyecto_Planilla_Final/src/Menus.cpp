#include "Menus.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <ctime>

UsuarioPlanilla traerMenu;
EmpleadosPlanilla enviarMenuE;
Puestos enviarMenuP;
Departamento enviarMenuD;
Bitacora imprimirBitacora;

string Menus::menuInicial(string nombreUsuario)
{
    string userName = nombreUsuario;
   // system("cls");
    int optEscoger = 0;
    bool repetir = true;
    do
    {
    system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Hola " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t---------------------------------------------\n";
    cout << "\t\t\t| Bienvenido al Sistema de Nominas de Empleados |";
    cout << "\n\t\t\t-----------------------------------------------"<<endl;

    cout << "\n\t\t\t1. Menu Catalogos"<<endl;
    cout << "\t\t\t2. Menu Procesos"<<endl;
    cout << "\t\t\t3. Menu Informes"<<endl;
    cout << "\t\t\t4. Salir del Sistema" << endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] - [4]";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
       system("cls");
       menuCatalogos(userName);
        break;
    }

    case 2:{
        system("cls");
        menuProcesos(userName);
    break;
    }
    case 3:{
        system("cls");
        subMenuInformes(userName);
        break;
        }
    case 4:{
             exit(0);
        break;
    }
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(optEscoger!=4);
}

string Menus::menuCatalogos(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int optEscoger;
    bool repetir = true;
    do
    {
            system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Hola " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t| Bienvenido al Menu de Catalogos |";
    cout << "\n\t\t\t---------------------------------"<<endl;

    cout << "\n\t\t\t1. Empleados"<<endl;
    cout << "\t\t\t2. Puestos"<<endl;
    cout << "\t\t\t3. Departamentos"<<endl;
    cout << "\t\t\t4. Regresar" << endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] - [4]";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
    enviarMenuE.menuEmpleadosPlanilla(userName);
       system("cls");

                break;
    }

    case 2:{
        system("cls");
        enviarMenuP.menuPuestos(userName);
    break;
    }
    case 3:{
        system("cls");
        enviarMenuD.DepartamentosPlanilla(userName);
        break;
        }
    case 4:
        system("cls");
       menuInicial(userName);
        break;
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(optEscoger!=4);
}

string Menus::subMenuInformes(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int optEscoger;
    bool repetir = true;
    do
    {
    system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Hola " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t| Bienvenido al Menu de Informes |";
    cout << "\n\t\t\t---------------------------------"<<endl;

    cout << "\n\t\t\t1. Bitacora"<<endl;
    cout << "\t\t\t2. Usuarios"<<endl;
    cout << "\t\t\t3. Regresar" << endl;
    cout << "\n\n\t\t\t------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3]";
    cout << "\n\t\t\t--------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
       system("cls");
       imprimirBitacora.imprimirDatosBitacora();
    break;
    }

    case 2:{
        system("cls");
            traerMenu.menuUsuario(userName);
    break;
    }
    case 3:
        menuInicial(userName);
        break;

    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(optEscoger!=3);
}

string Menus::menuProcesos(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int optEscoger;
  bool repetir = true;
    do
    {
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Hola " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t| Bienvenido al Menu de Procesos |";
    cout << "\n\t\t\t---------------------------------"<<endl;
    cout << "\t\t\t1. Descuentos"<<endl;
    cout << "\t\t\t2. Horas Extras"<<endl;
    cout << "\t\t\t3. Total a Pagar"<<endl;
    cout << "\t\t\t4. Porcentajes"<<endl;
    cout << "\t\t\t5. Salario Diario"<<endl;
    cout << "\t\t\t6. Salir del Sistema" << endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t| Opciones a escoger: [1] - [2] - [3] - [4]- [5]- [6]";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {

    case 1:{
       system("cls");
       Descuentos menu;
       menu.menuDescuentos();
       system("pause");
                break;
    }

    case 2:{
        system("cls");
        Descuentos menu;
        menu.menuHorasExtra();
        system("cls");
        system("pause");

    break;
    }
    case 3:{
        system("cls");
        Descuentos menu;
        menu.menuTotalPago();
        system("pause");
        break;
        }
    case 4:{
        system("cls");
        Porcentajes menu;
        menu.menuporcentajes();
        system("pause");
        break;
        }
    case 5:{
        system("cls");
        HorasExtra menu;
        menu.menuHorasExtra();
        system("pause");
        break;
        }
    case 6:{
        system("cls");
        menuCatalogos(userName);
        system("pause");
        break;
    }
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(repetir);
}

