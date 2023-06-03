#ifndef INFORMES_H
#define INFORMES_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
#include "Bitacora.h"

using namespace std;

class Informes
{
    public:
        void menuInformes();

    protected:

    private:
        string nombrePuesto, encargadoPuesto, tituloPuesto;
        double salarioPuesto,idPuesto,porcentajeIsr, porcentajeSeguro, totalIgss, totalIsr, totalSeguro;
         double totalDescuentos, totalHoras, totalSueldo;
         double horasTrabajadas, valorHoraExtra;
         double bonificacion;
         double salarioDiario, valorHoraNormal;
         double valorporcentajeIgss;
         double porcentajeigss;
};

#endif // INFORMES_H
