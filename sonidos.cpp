/// Funciones de sonido
#include <iostream>
#include <string>
#include "funciones.h"
#include "ranking.h"
#include "rlutil.h"
#include "carteles.h"
#include "modoJuego.h"
#include "ranking.h"
using namespace std;


void playSpiral(int startFreq, int steps, int duration) {
    for (int i = 0; i < steps; ++i) {
        Beep(startFreq + (i * 50), duration);
        Sleep(25);
    }
}


void sonidoEleccion()
{
    Beep(1175, 50);
    Sleep(4);
    Beep(1046, 50);
    Sleep(3);
}


void sonidoRonda()
{
    Beep(1568, 100);
    Sleep(7);
    Beep(1175, 50);
    Sleep(3);
    Beep(1046, 50);
    Sleep(2);
    Beep(988, 60);
    Sleep(1);
    Beep(880, 150);
    Sleep(10);
}

void sonidoPuntaje()
{
    Beep(659, 100);
    Sleep(15);
    Beep(659, 100);
    Sleep(15);
    Beep(784, 300);
}

void sonidoMostrarGreed(){
        Beep(1568, 100);
        Sleep(8);
        Beep(1175, 50);
        Sleep(4);
        Beep(1046, 50);
        Sleep(3);
        Beep(988, 60);
        Sleep(2);
        Beep(880, 150);
        Sleep(20);
        }
