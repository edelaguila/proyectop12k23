#include "usuario.h"
#include "bitacora.h"
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

main()
{
	usuario proyectoFinal;
	proyectoFinal.menuAdministrador();
	return 0;
}
