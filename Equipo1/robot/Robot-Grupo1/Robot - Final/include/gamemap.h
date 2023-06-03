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
        void drawPremio2();
        void drawPremio3();
        void drawPremio4();
        virtual ~gamemap();
        bool isGameOver = false;

    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
        string nombre;
        int contador = 0;
        void loadMapFromFile2();
        void loadMapFromFile3();
        void loadMapFromFile4();
};

#endif // GAMEMAP_H
