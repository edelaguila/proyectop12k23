#ifndef BITACORA_H
#define BITACORA_H

#include "usuario.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
using namespace std;
class bitacora
{
    public:
        void ingreso(string nombreAd, string code);
        void desplegarBitacora(string nombreAd, string code);
    protected:
    private:
};
#endif // BITACORA_H
