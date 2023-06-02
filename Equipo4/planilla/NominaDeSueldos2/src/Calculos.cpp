#include "Calculos.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
using namespace std;

void Calculos::calculoSueldo(string i, string n, string p)
{
    fstream file;
    puesto2 = p;
    id = i;
    nombre = n;
    file.open("PuestoDeTrabajo.txt", ios::in);
    file >> puesto >> salarioBase;
    while(!file.eof())
    {
        if(puesto2==puesto)
        {
            salario2=salarioBase;
        }
        file >> puesto >> salarioBase;
    }
    verPago(salario2);
}
void Calculos::verPago(int s)
{
    fstream file, file1;
    salario = s;
    hTrabajadas = 0;
    montoHTr = 0;
    string beneficio = "bonificacion";
    string impuesto1 = "igss";
    string impuesto2 = "isrmenor";
    string impuesto3 = "isrmayor";
    file.open("Impuestos.txt",ios::in);
    file >> impuesto >> monto;
    while(!file.eof())
    {
        if(beneficio==impuesto)
        {
            bonificacion = monto;
        }
        if(impuesto1==impuesto)
        {
            igss = salario * monto;
        }
        if(impuesto2==impuesto)
        {
            if (salario<=30000 && salario>=0.00)
            {
                isr = salario * monto;
            }
        }
        if(impuesto3==impuesto)
        {
            if(salario>30000)
            {
                isr = salario * monto;
            }
        }
        file >> impuesto >> monto;
    }
    salarioTotal = (salario+bonificacion) - (igss+isr);
    file1.open("PlanillaDeSueldos.txt", ios::app | ios::out);
    file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< bonificacion <<std::left<<std::setw(15)<< hTrabajadas <<std::left<<std::setw(15)<< montoHTr <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< salarioTotal << "\n";
    file1.close();
}

