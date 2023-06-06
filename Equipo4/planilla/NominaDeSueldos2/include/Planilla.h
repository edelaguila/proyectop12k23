#ifndef PLANILLA_H
#define PLANILLA_H
#include <iostream>
using namespace std;

class Planilla
{
    public:
        void leerPlanilla(string n);
        void buscarPlanilla(string n);
        void modificarPlanilla(string n);
        void modificarDPPlanilla(string i, string n);
        void borrarPlanilla(string i);
        void buscarpago();

    private:
        int salario, bonificacion, hTrabajadas, hLaboradas;
        double montoHTr, igss, isr, salarioTotal;
        string id, nombre, nombre2;
};

#endif // PLANILLA_H
