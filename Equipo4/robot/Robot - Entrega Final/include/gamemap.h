#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"
#include <iostream>
using namespace std;
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [15][10];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        virtual ~gamemap();
        bool isGameOver = false;
        void bienvenida();

    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
        string nombre;
        int contador = 0;
        void segundoNivel();
        void tercerNivel();
        void cuartoNivel();
};

#endif // GAMEMAP_H
