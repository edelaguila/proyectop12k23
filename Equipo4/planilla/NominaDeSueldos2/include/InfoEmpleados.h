#ifndef INFOEMPLEADOS_H
#define INFOEMPLEADOS_H
#include <iostream>
using namespace std;

class InfoEmpleados
{
    private:
		string id, nombre,telefono,direccion,puesto;
		string nombre2;
		//variables para cambio en planilla de sueldos
		int salario, bonificacion, hTrabajadas;
		double igss, isr, montoHTr, salarioTotal;

	public:
		void menu(string n);
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();

};

#endif // INFOEMPLEADOS_H
