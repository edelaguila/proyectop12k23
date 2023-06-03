#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "EmpleadosPlanilla.h"
#include "Departamento.h"
#include "Puestos.h"
#include "Bitacora.h"
#include "Descuentos.h"
#include "Porcentajes.h"
#include "HorasExtra.h"
#include "Informes.h"

using namespace std;

class Menus
{
    public:
        string menuInicial(string nombreUsuario);
        string menuCatalogos(string nombreUsuario);
        string subMenuEmpleados(string nombreUsuario);
        string subMenuInformes(string nombreUsuario);
        string menuProcesos(string nombreUsuario);

    protected:

    private:
};

#endif // MENUS_H
