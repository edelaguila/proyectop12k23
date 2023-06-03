#include "usuario.h"
#include "bitacora.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;
string codigo;
bitacora bit;
void usuario::menuAdministrador()
{
    int Opciones;
	char x;
	do
    {
	system("cls");
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t|   INGRESO DE ADMINISTRADOR   |" << endl;
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t 1. Ingresar Administrador" << endl;
	cout << "\t\t\t 2. Salir del sistema" << endl;
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t    Opciones a escoger:[1/2]  " << endl;
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t    Ingresa una Opcion: ";
    cin >> Opciones;
    switch(Opciones)
    {
    case 0:
        system("cls");
        std::cout << "*===========================================*" << std::endl;
        std::cout << "||    Bienvenido al Programa EASTER EGG    ||" << std::endl;
        std::cout << "*===========================================*" << std::endl;
        std::cout << std::endl;
        std::cout << "    UUUU   UUUU   MMMM     MMM   GGGGGG   " << std::endl;
        std::cout << "    UUUU   UUUU   MMMMM   MMMM  GGGGGGGG  " << std::endl;
        std::cout << "    UUUU   UUUU   MMMMMM MMMMM GGG        " << std::endl;
        std::cout << "    UUUU   UUUU   MMM MMMM MMM GGG   GGGGG " << std::endl;
        std::cout << "    UUUU   UUUU   MMM  MM  MMM GGG    GGGG  " << std::endl;
        std::cout << "    UUUU   UUUU   MMM      MMM  GGGGGGGGG   " << std::endl;
        std::cout << "    UUUUUUUUUUU   MMM      MMM   GGGGGGG  " << std::endl;
        std::cout << "     UUUUUUUUU    MMM      MMM    GGGGG   " << std::endl;
        std::cout << std::endl;
        std::cout << "            Bienvenido al programa" << std::endl;
        std::cout << "Esperamos que disfrutes explorando nuevas posibilidades." << std::endl;
        std::cout << std::endl;
        std::cout << "=============================================" << std::endl;
        std::cout << "||          NOMBRE DE LOS CREADORES        ||" << std::endl;
        std::cout << "=============================================" << std::endl;
        std::cout << "||     9959-22-9790        Javier Lima     ||" << std::endl;
        std::cout << "||     9959-22-9304        Kesdy Melgar    ||" << std::endl;
        std::cout << "||     9959-22-8           Julio Molina    ||" << std::endl;
        std::cout << "||     9959-22-5755        Erick Solares   ||" << std::endl;
        std::cout << "=============================================" << std::endl;
        std::cout << std::endl;
        break;
    case 1:
        insertarAdministrador();
		break;
	case 2:
	    system("cls");
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )===================================( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)===================================(_____)"<< endl;
		exit(0);
	default:
	    std::cout << "=====================================================" << std::endl;
        std::cout << "||  Opcion invalida...Por favor prueba otra vez..  ||" << std::endl;
        std::cout << "=====================================================" << std::endl;
	}
	getch();
    }while(Opciones!= 4);
}
void usuario::insertarAdministrador()
{

    vector<string> usuarios;
    vector<string> claves;

    usuarios.push_back("Kesdy");
    usuarios.push_back("Erick");
    usuarios.push_back("Julio");
    usuarios.push_back("Javier");

    claves.push_back("KES");
    claves.push_back("ERI");
    claves.push_back("JUL");
    claves.push_back("JAV");

    int contador = 0;
    bool ingresa = false;
    do
    {
        system("cls");
        fstream file;
        cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )===================================( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / | INGRESA LOS DATOS DE ADMINISTRACION | / |"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)===================================(_____)"<< endl;
        cout << "\        ================================================="<< endl;
        cout << "\t\t\tIngresa Usuario \n";

        cout << "\t\t\tUsuario: ";
        cin >> nameAdministrador;

        char caracter;
        cout << "\t\t\tPassword: ";
        caracter = getch();
        getline(cin, passwordAdministrador);

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                passwordAdministrador.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (passwordAdministrador.length() > 0)
                {
                    cout << "\b \b";
                    passwordAdministrador = passwordAdministrador.substr(0, passwordAdministrador.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == nameAdministrador && claves[i] == passwordAdministrador)
            {
                ingresa = true;
                break;
            }
        }
        if (!ingresa)
        {
            system("cls");
            std::cout << "=====================================================" << std::endl;
            std::cout << "||  El Administrador y/o password son incorrectos  ||" << std::endl;
            std::cout << "=====================================================" << std::endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        system("cls");
        std::cout << "================================================================" << std::endl;
        std::cout << "||  Haz fallado 3 veces, no puedes acceder al sistema. ADIOS  ||" << std::endl;
        std::cout << "================================================================" << std::endl;
        codigo="7000";
        bitacora bit;
        bit.ingreso(nameAdministrador,codigo);
    }

    else
    {
    codigo="7001";
    bitacora bit2;
    bit2.ingreso(nameAdministrador,codigo);
    int Opciones;
	char x;
	do
    {
	system("cls");
	std::cout << "**=========================================================================================================**" << std::endl;
	std::cout << "||       BBBBBB   IIII   EEEEEEE  NN     NN   VV     VV   EEEEEEE   NN    NN   IIII   DDDDDD   OOOOOOO     ||" << std::endl;
    std::cout << "||       BB   BB   II    EE       NNNN   NN   VV     VV   EE        NNNN  NN    II    DD   DD  OO   OO     ||" << std::endl;
    std::cout << "||       BBBBBB    II    EEEEE    NN NN  NN    VV   VV    EEEEE     NN NN NN    II    DD   DD  OO   OO     ||" << std::endl;
    std::cout << "||       BB   BB   II    EE       NN   NNNN     VV VV     EE        NN  NNNN    II    DD   DD  OO   OO     ||" << std::endl;
    std::cout << "||       BBBBBB   IIII   EEEEEEE  NN    NNN       V       EEEEEEE   NN   NNN   IIII   DDDDDD   OOOOOOO     ||" << std::endl;
    std::cout << "**=========================================================================================================**" << std::endl;
    std::cout << "||                            Bienvenido, " << nameAdministrador << " al programa de nomina                                     ||" << std::endl;
    std::cout << "||       Esperamos que esta herramienta sea de utilidad para calcular los salarios de los empleados        ||" << std::endl;
    std::cout << "**=========================================================================================================**" << std::endl;
    std::cout << std::endl;
    system("pause");
    system("cls");
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )===================================( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |            MENU DE INICIO           | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)===================================(_____)"<< endl;
    cout << "\        ================================================="<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Ingreso a la nomina        |"<< endl;
    cout << "                 | 2. Informes                   |"<< endl;
    cout << "                 | 3. Cerrar Sesion              |"<< endl;
    cout << "                 | 4. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                      Ingresa una Opcion: ";
    cin >> Opciones;

    switch(Opciones)
    {
    case 1:
        menuTrabajador();
		break;
    case 2:
    system("cls");
    do
    {
        system("cls");
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |            MENU DE INFORME          | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)-----------------------------------(_____)"<< endl;
    cout << "\        -------------------------------------------------"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Trabajadores               |"<< endl;
    cout << "                 | 2. Bitacora                   |"<< endl;
    cout << "                 | 3. Aplicaciones               |"<< endl;
    cout << "                 | 4. Departamentos              |"<< endl;
    cout << "                 | 5. Salir al menu inicial      |"<< endl;
    cout << "                 | 6. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                   Ingresa una Opcion: ";
    cin >> Opciones;

        switch(Opciones)
        {
        case 1:
            desplegarTrabajador();
        break;
        case 2:
            bit.desplegarBitacora(nameAdministrador,"7500");
            break;
        case 3:
            system("cls");
            cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          | / |           CODIGOS DE CAMBIOS        | / |"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)-----------------------------------(_____)"<< endl;
            cout << "         -------------------------------------------------"<< endl;
            cout << "                   7000		INGRESOFALLIDO             "<< endl;
            cout << "                   7001		INGRESO                    "<< endl;
            cout << "                   7300		MENUTRABAJADORES           "<< endl;
            cout << "                   7301		AGRTRABAJADORES            "<< endl;
            cout << "                   7302		REPTRABAJADORES            "<< endl;
            cout << "                   7303		MODTRABAJADORES            "<< endl;
            cout << "                   7304		BUSTRABAJADORES            "<< endl;
            cout << "                   7305		BORTRABAJADORES            "<< endl;
            cout << "                   7400		REPAPLICACIONES            "<< endl;
            cout << "                   7500        MENUDEPARTAMENTOS          "<< endl;
            cout << "                   7501        REPADMINISTRACION          "<< endl;
            cout << "                   7502        REPVENTAS                  "<< endl;
            cout << "                   7999		SALIDA                     "<< endl;
            cout << "         ------------------------ -------------------------"<< endl;
            bit.ingreso(nameAdministrador,"7400");
            system("pause");
            break;
        case 4:
            menuDepartamentos();
            bit.ingreso(nameAdministrador,"7500");
            break;
        case 5:
            system("cls");
            cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          |___|    Redireccionando al inicio....    |___|"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)-----------------------------------(_____)"<< endl;
                return;
        case 6:
        system("cls");
	    bitacora bit;
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
        cout << "" << endl;
        cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
        cout << "" << endl;
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
		exit(0);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 4);
    break;
	case 3:
	    system("cls");
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|    Redireccionando al inicio....    |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
		return;
		bitacora bit;
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
    case 4:
        system("cls");
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
		exit(0);
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 3);
}
}

void usuario::menuTrabajador()
{
    int Opciones;
	char x;
	do
    {
    system("cls");
    cout << "       888b      88    ,ad8888ba,    88b           d88  88  888b      88         db               "<< endl;
    cout << "       8888b     88   d8'    `''8b   888b         d888  88  8888b     88        d88b              "<< endl;
    cout << "       88 `8b    88  d8'        `8b  88`8b       d8'88  88  88 `8b    88       d8'`8b             "<< endl;
    cout << "       88  `8b   88  88          88  88 `8b     d8' 88  88  88  `8b   88      d8'  `8b            "<< endl;
    cout << "       88   `8b  88  88          88  88  `8b   d8'  88  88  88   `8b  88     d8YaaaaY8b           "<< endl;
    cout << "       88    `8b 88  Y8,        ,8P  88   `8b d8'   88  88  88    `8b 88    d8''''''''8b          "<< endl;
    cout << "       88     `8888   Y8a.    .a8P   88    `888'    88  88  88     `8888   d8'        `8b         "<< endl;
    cout << "       88      `888    `'Y8888Y'     88     `8'     88  88  88      `888  d8'          `8b        "<< endl;
    cout << "                                                                                                  "<< endl;
    cout << "                                                                                                  "<< endl;
    cout << "                    88        88  88b           d88    ,ad8888ba,                                 "<< endl;
    cout << "                    88        88  888b         d888   d8''    `'8b                                "<< endl;
    cout << "                    88        88  88`8b       d8'88  d8'                                          "<< endl;
	cout << "                    88        88  88 `8b     d8' 88  88                                           "<< endl;
	cout << "                    88        88  88  `8b   d8'  88  88      88888                                "<< endl;
	cout << "                    88        88  88   `8b d8'   88  Y8,        88                                "<< endl;
	cout << "                    Y8a.    .a8P  88    `888'    88   Y8a.    .a88                                "<< endl;
	cout << "                    `''Y8888Y''   88     `8'     88   `''Y88888P''                                "<< endl;
    cout << "                                                                                           "<< endl;
	system("pause");
	system("cls");
	bitacora bit;
	codigo="7300";
	bit.ingreso(nameAdministrador,codigo);
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )===================================( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |              NOMINA UMG             | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)===================================(_____)"<< endl;
    cout << "\        ================================================="<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Ingresar Trabajador        |"<< endl;
    cout << "                 | 2. Desplegar Trabajador       |"<< endl;
    cout << "                 | 3. Modificar Trabajador       |"<< endl;
    cout << "                 | 4. Buscar Trabajador          |"<< endl;
    cout << "                 | 5. Borrar Trabajador          |"<< endl;
    cout << "                 | 6. Regresar al inicio         |"<< endl;
    cout << "                 | 7. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                    Ingresa una Opcion: ";
    cin >> Opciones;
    switch(Opciones)
    {
    case 1:
    	do
    	{
    		insertarTrabajador();
    		cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )===================================( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          | / |  Desea gregar un nuevo trabajador?  | / |"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)===================================(_____)"<< endl;
            cout << "         =================================================" <<endl;
            cout << "                Pulsa Y para si ||| Pulsa N para No     " <<endl;
            cout << "         =================================================" <<endl;
            cout << "                Selecciona una respuesta: ";
    		cin >> x;
		}while(x == 'y'||x == 'Y');
		break;
	case 2:
		desplegarTrabajador();
		break;
	case 3:
		modificarTrabajador();
		break;
	case 4:
		buscarTrabajador();
		break;
	case 5:
		borrarTrabajador();
		break;
    case 6:
        system("cls");
        cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
        cout << "" << endl;
        cout << "          __^__                                     __^__"<< endl;
	    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|    Redireccionando al inicio....    |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
                break;
	case 7:
	    system("cls");
	    bitacora bit;
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
        cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
        cout << "" << endl;
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
        exit(0);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 6);
}
void usuario::insertarTrabajador()
{
	system("cls");
	fstream file;
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |    Agregar informacion Trabajador   | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)-----------------------------------(_____)"<< endl;
	cout << "\t\t  Ingresa ID del trabajador : ";
	cin >> ID;
	cout << "\t\t  Ingresa Nombre del trabajor : ";
	cin >> name;
	cout << "\t\t  Ingresa Contrasena Trabajador : ";
	cin >> password;
	cout << "\t\t  Ingresa el numero de telefono del trabajador : ";
	cin >> telefono;
	cout << "\t\t  Ingrese departamento V/A/C/R(Ventas, Administracion, Contabilidad, Recepcion): ";
	cin >> departamento;
	cout << "\t\t  Ingresa El salario del trabajador : Q";
	cin >> salario;
	cout << "\t\t  Ingresa las horas extras trabajadas : ";
	cin >> cantidadHoras;
	cout << "\t\t  Ingresa el valor de las extras trabajadas : Q";
	cin >> valorHoras;
    totalHoras = cantidadHoras*valorHoras;
    cout << "\t\t  Ingresa el valor del adelanto : Q";
    cin >> adelantos;
    system("cls");
    cout << "=============================================" <<endl;
    cout << "||     Listo! nuevo trabajador agregado    ||" <<endl;
    cout << "=============================================" <<endl;
    IGSS = (salario+totalHoras)*(0.0483);
    IRTRA = (salario+totalHoras)*(0.01);
    salarioNeto=(salario+totalHoras)-(IGSS+IRTRA);
	if (departamento=="V")
    {
        departamento="Ventas";
        file.open("Ventas.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    if (departamento=="A")
    {
        departamento="Admin";
        file.open("Administracion.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    if (departamento=="C")
    {
        departamento="Conta";
        file.open("Contabilidad.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    if (departamento=="R")
    {
        departamento="Recep";
        file.open("Recepcion.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    file.open("Usuarios.txt", ios::app | ios::out);
	file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::setw(15)<< telefono << std::left << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
	bitacora bit;
	codigo="7301";
	bit.ingreso(nameAdministrador,codigo);
	file.close();
}
void usuario::desplegarTrabajador()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "                                               __^__                                     __^__"<< endl;
    cout << "                                              ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "                                               | / |                                     | / |"<< endl;
    cout << "                                               | / |   Tabla de Detalles de Trabajador   | / |"<< endl;
    cout << "                                               |___|                                     |___|"<< endl;
    cout << "                                              (_____)-----------------------------------(_____)"<< endl;
    cout << "===============================================================================================================================================================" << endl;
    cout << "ID             NOMBRE       PASSWORD         TELEFONO         PUESTO      SALARIO     HORAS EXTRAS       IGSS           IRTRA        SALARIO NETO    ADELANTOS " << endl;
    cout << "===============================================================================================================================================================" << endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7302";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::modificarTrabajador()
{
	system("cls");
	fstream file,file1;
	string user_ID;
	int found = 0;
	cout << "\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{   cout << "" << endl;
	    cout << "\n\tUsuario: " << nameAdministrador << endl << endl;
		cout << "\n Ingrese ID del usuario que quiere modificar: ";
		cin >> user_ID;
		file1.open("Record.txt",ios::app | ios::out);
		        file >> ID >> name >> password >> telefono >> departamento >> salario >> cantidadHoras >> IGSS >> IRTRA >> salarioNeto >>adelantos ;
		while(!file.eof())
		{
			if(user_ID!=ID)
			{
			 file1 << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::setw(15)<< telefono << std::left << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
			}
			else
			{
				cout << "\t\t\tIngrese ID Persona: ";
				cin >> ID;
				cout << "\t\t\tIngrese Nombre Persona: ";
				cin >> name;
				cout << "\t\t\tIngrese Contrasena Persona: ";
				cin >> password;
				cout << "\t\t\tIngrese Telefono Persona: ";
				cin >> telefono;
				cout << "\t\t\tIngrese Departamento Persona: ";
				cin >> departamento;
                file1 << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::setw(15)<< telefono << std::left << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
				found++;
			}
			        file >> ID >> name >> password >> telefono >> departamento >> salario >> cantidadHoras >> IGSS >> IRTRA >> salarioNeto >>adelantos ;

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
        bitacora bit;
        codigo="7303";
        bit.ingreso(nameAdministrador,codigo);
	}
}
void usuario::buscarTrabajador()
{
	system("cls");
	fstream file;
	int found = 0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{

		cout << "\n-------------------------Datos del Trabajador buscada------------------------" << endl;
		cout << "\n\t\t\tNo hay informacion...";
	}
	else
	{
		string user_ID;
        cout << "" << endl;
        cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
		cout << "          __^__                                      __^__"<< endl;
        cout << "         ( ___ )------------------------------------( ___ )"<< endl;
        cout << "          | / |                                      | / |"<< endl;
        cout << "          | / |     Datos del Trabajador buscado     | / |"<< endl;
        cout << "          |___|                                      |___|"<< endl;
        cout << "         (_____)------------------------------------(_____)"<< endl;
		cout << "\nIngrese ID de la Persona que quiere buscar: ";
		cin >> user_ID;
		file >> ID >> name >> password >> telefono >> departamento >> salario >> cantidadHoras >> IGSS >> IRTRA >> salarioNeto >>adelantos ;
		while(!file.eof())
		{
			if(user_ID == ID)
			{
				cout << "                 *============================* "<< endl;
                cout << "                                              "<< endl;
                cout << "                   ID Trabajador: "<< ID << endl;
                cout << "                   Nombre Trabajador : "<< name << endl;
                cout << "                   Contrasena Trabajador : "<< password << endl;
                cout << "                   Salario : Q"<< salario << endl;
                cout << "                   Pago de IGSS : Q"<< IGSS << endl;
                cout << "                   Pago de IRTRA: Q"<< IRTRA << endl;
                cout << "                   Cantidad de horas extras: "<< cantidadHoras << endl;
                cout << "                   Total de adelantos: Q"<< adelantos << endl;
                cout << "                   Total de las horas extras: Q"<< totalHoras << endl;
                cout << "                   Salario Neto : Q"<< salarioNeto << endl;
                cout << "                                              "<< endl;
                cout << "                 *============================* "<< endl;
				found++;
			}
			file >> ID >> name >> password >> telefono >> departamento >> salario >> cantidadHoras >> IGSS >> IRTRA >> salarioNeto >>adelantos ;
		}
		if(found == 0)
		{
			cout<<"\n\t\t\t Trabajador no encontrado...";
		}
		file.close();
		bitacora bit;
        codigo="7304";
        bit.ingreso(nameAdministrador,codigo);
	}
}
void usuario::borrarTrabajador()
{
	system("cls");
	fstream file,file1;
	string user_ID;
	int found = 0;
	cout << "\n-------------------------Detalles Usuario a Borrar-------------------------" << endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{   cout << "" << endl;
	    cout << "\n\tUsuario: " << nameAdministrador << endl << endl;
		cout << "\n Ingrese el ID del Usuario que quiere borrar: ";
		cin >> user_ID;
		file1.open("Record.txt",ios::app | ios::out);
        file >> ID >> name >> password >> telefono >> departamento >> salario >> cantidadHoras >> IGSS >> IRTRA >> salarioNeto >>adelantos ;
		while(!file.eof())
		{
			if(user_ID!=ID)
			{
                file1 << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << password << std::left << std::setw(15)<< telefono << std::left << std::setw(15)<< departamento << std::left << std::setw(15)  << salario << std::left << std::setw(15) << cantidadHoras << std::setw << std::setw(15) << IGSS << std::left << std::setw(15) << IRTRA << std::left << std::setw(15) << salarioNeto << std::setw << std::setw(15) << adelantos << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
        file >> ID >> name >> password >> telefono >> departamento >> salario >> cantidadHoras >> IGSS >> IRTRA >> salarioNeto >>adelantos ;
		}
		if(found == 0)
		{
			cout<<"\n\t\t\t ID Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
        bitacora bit;
        codigo="7304";
        bit.ingreso(nameAdministrador,codigo);
	}
}
void usuario::desplegarAdministracion()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "                                               __^__                                     __^__"<< endl;
    cout << "                                              ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "                                               | / |                                     | / |"<< endl;
    cout << "                                               | / |   Tabla de Detalles de Trabajador   | / |"<< endl;
    cout << "                                               |___|     Departamento Administrativo     |___|"<< endl;
    cout << "                                               |___|                                     |___|"<< endl;
    cout << "                                              (_____)-----------------------------------(_____)"<< endl;
    cout << "===============================================================================================================================================================" << endl;
    cout << "ID             NOMBRE       PASSWORD         PUESTO         TELEFONO      SALARIO     HORAS EXTRAS       IGSS           IRTRA        SALARIO NETO    ADELANTOS " << endl;
    cout << "===============================================================================================================================================================" << endl;
	file.open("Administracion.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7501";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::desplegarVentas()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "                                               __^__                                     __^__"<< endl;
    cout << "                                              ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "                                               | / |                                     | / |"<< endl;
    cout << "                                               | / |   Tabla de Detalles de Trabajador   | / |"<< endl;
    cout << "                                               |___|        Departamento de Ventas       |___|"<< endl;
    cout << "                                               |___|                                     |___|"<< endl;
    cout << "                                              (_____)-----------------------------------(_____)"<< endl;
    cout << "===============================================================================================================================================================" << endl;
    cout << "ID             NOMBRE       PASSWORD         PUESTO         TELEFONO      SALARIO     HORAS EXTRAS       IGSS           IRTRA        SALARIO NETO    ADELANTOS " << endl;
    cout << "===============================================================================================================================================================" << endl;
	file.open("Ventas.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7502";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::desplegarContabilidad()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "                                               __^__                                     __^__"<< endl;
    cout << "                                              ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "                                               | / |                                     | / |"<< endl;
    cout << "                                               | / |   Tabla de Detalles de Trabajador   | / |"<< endl;
    cout << "                                               |___|     Departamento Contabilidad       |___|"<< endl;
    cout << "                                               |___|                                     |___|"<< endl;
    cout << "                                              (_____)-----------------------------------(_____)"<< endl;
    cout << "===============================================================================================================================================================" << endl;
    cout << "ID             NOMBRE       PASSWORD         PUESTO         TELEFONO      SALARIO     HORAS EXTRAS       IGSS           IRTRA        SALARIO NETO    ADELANTOS " << endl;
    cout << "===============================================================================================================================================================" << endl;
	file.open("Contabilidad.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7501";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::desplegarRecepcion()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "                                               __^__                                     __^__"<< endl;
    cout << "                                              ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "                                               | / |                                     | / |"<< endl;
    cout << "                                               | / |   Tabla de Detalles de Trabajador   | / |"<< endl;
    cout << "                                               |___|     Departamento Recepcion          |___|"<< endl;
    cout << "                                               |___|                                     |___|"<< endl;
    cout << "                                              (_____)-----------------------------------(_____)"<< endl;
    cout << "===============================================================================================================================================================" << endl;
    cout << "ID             NOMBRE       PASSWORD         PUESTO         TELEFONO      SALARIO     HORAS EXTRAS       IGSS           IRTRA        SALARIO NETO    ADELANTOS " << endl;
    cout << "===============================================================================================================================================================" << endl;
	file.open("Recepcion.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7501";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::menuDepartamentos()
{
    int Opciones;
    do
    {
    system("cls");
    cout << "" << endl;
    cout << "\t\t   Nombre Administrador: " << nameAdministrador << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |            MENU DEPARTAMENTOS       | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)-----------------------------------(_____)"<< endl;
    cout << "\        -------------------------------------------------"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Administracion             |"<< endl;
    cout << "                 | 2. Ventas                     |"<< endl;
    cout << "                 | 3. Contabilidad               |"<< endl;
    cout << "                 | 4. Recepcion                  |"<< endl;
    cout << "                 | 5. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 |      Ingresa una Opcion       |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cin >> Opciones;

        switch(Opciones)
        {
        case 1:
            desplegarAdministracion();
            break;
        case 2:
            desplegarVentas();
            break;
        case 3:
            desplegarContabilidad();
            break;
        case 4:
            desplegarRecepcion();
            break;
        case 5:
            system("cls");
            bitacora bit;
            codigo="7999";
            bit.ingreso(nameAdministrador,codigo);
            cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
            cout << "" << endl;
            cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
            cout << "          |___|            vuelva pronto            |___|"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)-----------------------------------(_____)"<< endl;
            exit(0);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 5);
}
