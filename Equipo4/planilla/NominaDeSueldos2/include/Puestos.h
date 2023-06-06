#ifndef PUESTOS_H
#define PUESTOS_H
#include <iostream>
using namespace std;

class Puestos
{
    public:
        void ingresarPuesto(string n);
        void visualizarPuesto(string n);
        void buscarPuesto(string n);

    private:
        string nombre, puesto;
        int salarioBase;
};

#endif // PUESTOS_H
