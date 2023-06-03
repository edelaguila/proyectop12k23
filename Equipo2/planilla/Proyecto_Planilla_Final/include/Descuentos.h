#ifndef DESCUENTOS_H
#define DESCUENTOS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
#include "Bitacora.h"

using namespace std;

class Descuentos
{
    public:
        void menuDescuentos();
        void menuHorasExtra();
        void menuTotalPago();
        void menuTrabajador();
        double totalHoras;
    protected:

    private:
        string nombrePuesto, encargadoPuesto, tituloPuesto;
        double salarioPuesto,idPuesto,porcentajeIsr, porcentajeSeguro, totalIgss, totalIsr, totalSeguro;
         double totalDescuentos, totalSueldo;
         double horasTrabajadas, valorHoraExtra;
         double bonificacion;
         double salarioDiario, valorHoraNormal;
         double valorporcentajeIgss;
         double porcentajeigss;

};


#endif // DESCUENTOS_H
