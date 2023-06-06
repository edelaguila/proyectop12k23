#ifndef HORASEXTRA_H
#define HORASEXTRA_H

#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Menus.h"
#include "Bitacora.h"

class HorasExtra
{
    public:
        void menuHorasExtra ();

    protected:

    private:
        string nombrePuesto, encargadoPuesto, tituloPuesto;
        double idPuesto, salarioPuesto, salarioDiario, valorHoraNormal, valorHoraExtra;
        double bonificacion;
};

#endif // HORASEXTRA_H
