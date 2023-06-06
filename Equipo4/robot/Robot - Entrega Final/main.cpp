#include <iostream>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"

using namespace std;

int main()
{
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022

    gamemap map;
    player hero;
    //map.draw();
    while(map.isGameOver==false)
    {
      cout << "Introduce comando de movimiento: Arriba: <w> , Izquierda: <a>, Abajo: <s>, Derecha: <d> : <x> --> Salir " << endl;
      hero.callInput();

      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();
      }
      //map.draw();

    }
    player credito;
    credito.drawCreditos();
    return 0;
}
