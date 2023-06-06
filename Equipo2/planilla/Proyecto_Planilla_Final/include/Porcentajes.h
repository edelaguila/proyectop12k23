#ifndef PORCENTAJES_H
#define PORCENTAJES_H

#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
#include "Bitacora.h"

using namespace std;

class Porcentajes
{
    public:
        void menuporcentajes();

    protected:

    private:
        string nombrePuesto, encargadoPuesto, tituloPuesto;
        double idPuesto, porcentajeIgss, porcentajeIsr, porcentajeSeguro, salarioPuesto;
        double bonificacion;



};

#endif // PORCENTAJES_H
