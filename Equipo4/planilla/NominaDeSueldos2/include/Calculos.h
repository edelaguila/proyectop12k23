#ifndef CALCULOS_H
#define CALCULOS_H
#include <iostream>
using namespace std;

class Calculos
{
    public:
        void calculoSueldo(string i, string n, string p);
        void verPago(int s);

    private:
        int salario, salario2, salarioBase, bonificacion, hTrabajadas;
        double igss, isr, montoHTr, salarioTotal, monto;
        string id, nombre, puesto, puesto2, fecha, impuesto;
};

#endif // CALCULOS_H
