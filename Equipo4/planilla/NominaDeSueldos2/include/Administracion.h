#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H
#include <iostream>
using namespace std;

class Administracion
{
    public:
        void menuGeneralSTAFF(string n);
        void catalogosSTAFF();
        void procesoSTAFF();
        void infomesSTAFF();
        void puestos();
        void planilla();
        void pagos();
    private:
        string nombre;
};

#endif // ADMINISTRACION_H
