#include "Puestos.h"

Menus regresarMenuP;
Bitacora enviarDatosP;
string Puestos::menuPuestos(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    Puestos menu;
    int choice;
    bool repetir = true;
    char x;
	do
    {
	system("cls");

	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|                  !Hola " << userName << "!                  |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
	cout<<"\t\t\t |   Bienvenido al Menu de Puestos  |"<<endl;
	cout<<"\t\t\t-------------------------------------"<<endl;
	cout<<"\n\t\t\t 1. Ingresar Datos de los Puestos "<<endl;
	cout<<"\t\t\t 2. Buscar Puesto"<<endl;
	cout<<"\t\t\t 3. Modificar Datos del Puesto"<<endl;
	cout<<"\t\t\t 4. Elimidar Puestos"<<endl;
	cout<<"\t\t\t 5. Imprimir Datos de Puestos"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        system("cls");
        do
    	{
    		menu.insertarPuestos(userName);
    		cout<<"\n\t\t\t Agregar Otro Empleado (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');

		break;
	case 2:
	    system("cls");
		menu.buscarPuestos(userName);
		break;
	case 3:
	    system("cls");
		menu.modificarPuestos(userName);

		break;
	case 4:
	    system("cls");
		menu.borrarPuestos(userName);

		break;
    case 5:
		system("cls");
		menu.imprimirPuestos(userName);

		break;
	case 6:
	    system("cls");
		regresarMenuP.menuCatalogos(userName);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(repetir);
}

void Puestos::insertarPuestos(string nombreUsuario)
{
    string userName = nombreUsuario;
    enviarDatosP.ingresoDatosBitacora(userName,"7200","ING");
    string accion = "7001";
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Alta (Ingreso) de Puestos -------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id del Puesto           : ";
	cin>>idPuesto;
	cout<<"\t\t\tIngresa Nombre del PPuesto       : ";
	cin>>nombrePuesto;
	cout<<"\t\t\tIngresa el Encargado del Puesto        : ";
	cin>>encargadoPuesto;
	cout<<"\t\t\tIngresa Profesion del Encargado          : ";
	cin>>tituloPuesto;
	cout<<"\t\t\tIngresa Salario del Empleado    : ";
	cin>>salarioPuesto;
	file.open("Puestos.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< idPuesto <<std::left<<std::setw(15)<< nombrePuesto <<std::left<<std::setw(15)<< encargadoPuesto <<std::left<<std::setw(15)<< tituloPuesto <<std::left<<std::setw(15)<< salarioPuesto << "\n";
	file.close();
}

void Puestos::buscarPuestos(string nombreUsuario)
{
    string userName = nombreUsuario;
enviarDatosP.ingresoDatosBitacora(userName,"7210","SRC");

    string accion = "7002";
    fstream file;
	int found=0;
	file.open("Puestos.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Puesto Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Puesto Buscado------------------------"<<endl;
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
}

void Puestos::modificarPuestos(string nombreUsuario)
{
    string userName = nombreUsuario;
    enviarDatosP.ingresoDatosBitacora(userName,"7220","MOD");

    fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Puestos-------------------------"<<endl;
	file.open("Puestos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Puesto que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		while(!file.eof())
		{
			if(participant_id!=idPuesto)
			{
			 file1 <<std::left<<std::setw(15)<< idPuesto <<std::left<<std::setw(15)<< nombrePuesto <<std::left<<std::setw(15)<< encargadoPuesto <<std::left<<std::setw(15)<< tituloPuesto <<std::left<<std::setw(15)<< salarioPuesto << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Id del Puesto            : ";
                cin>>idPuesto;
                cout<<"\t\t\tIngresa Nombre del Puesto        : ";
                cin>>nombrePuesto;
                cout<<"\t\t\tIngresa Encargado del Puesto      : ";
                cin>>encargadoPuesto;
                cout<<"\t\t\tIngresa Profesion del Encargado   : ";
                cin>>tituloPuesto;
                cout<<"\t\t\tIngresa Salario del Puesto     : ";
                cin>>salarioPuesto;
				 file1 <<std::left<<std::setw(15)<< idPuesto <<std::left<<std::setw(15)<< nombrePuesto <<std::left<<std::setw(15)<< encargadoPuesto <<std::left<<std::setw(15)<< tituloPuesto <<std::left<<std::setw(15)<< salarioPuesto << "\n";
				found++;
			}
			file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;

		}
		file1.close();
		file.close();
		remove("Puestos.txt");
		rename("Record.txt","Puestos.txt");
	}
}

void Puestos::borrarPuestos(string nombreUsuario)
{
    string userName = nombreUsuario;
    		enviarDatosP.ingresoDatosBitacora(userName,"7230","DEL");
    string accion = "7004";
    fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Baja (Borrado) de Puestos-------------------------"<<endl;
	file.open("Puestos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Puesto que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		while(!file.eof())
		{
			if(participant_id!= idPuesto)
			{
				file1 <<std::left<<std::setw(15)<< idPuesto <<std::left<<std::setw(15)<< nombrePuesto <<std::left<<std::setw(15)<< encargadoPuesto <<std::left<<std::setw(15)<< tituloPuesto <<std::left<<std::setw(15)<< salarioPuesto << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Puesto no encontrado...";
		}
		file1.close();
		file.close();
		remove("Puestos.txt");
		rename("Record.txt","Puestos.txt");
	}
}

void Puestos::imprimirPuestos(string nombreUsuario)
{
    string userName = nombreUsuario;
    		enviarDatosP.ingresoDatosBitacora(userName,"7240","IMP");
   string accion = "7005";
   fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Informe de Puestos -------------------------"<<endl;
	file.open("Puestos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Puesto           : "<<idPuesto<<endl;
			cout<<"\t\t\t Nombre Puesto           : "<<nombrePuesto<<endl;
			cout<<"\t\t\t Encargado del Puesto    : "<<encargadoPuesto<<endl;
			cout<<"\t\t\t Profesion del Encargado : "<<tituloPuesto<<endl;
			cout<<"\t\t\t Saario del Puesto       : "<<salarioPuesto<<endl;
        file >> idPuesto >> nombrePuesto >> encargadoPuesto >> tituloPuesto >> salarioPuesto;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
