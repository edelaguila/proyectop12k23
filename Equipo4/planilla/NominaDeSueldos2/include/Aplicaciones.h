#ifndef APLICACIONES_H
#define APLICACIONES_H
#include <iostream>
using namespace std;

class Aplicaciones
{
    private:
		string id,nombre,estado;
		string nombre2;
	public:
		void menu(string n);
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // APLICACIONES_H
