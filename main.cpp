#include<iostream>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"
#include "ranking.h"
#include "carteles.h"
#include "modoJuego.h"
#include "dados.h"
#include <iomanip>
using namespace std;



int main(){


     int selection;
     mostrarmostrarGreed();
     rlutil::cls();
     do {
        selection = mostrarMenu();
        procesarSelection(selection);
    } while (selection != 5);



    return 0;
}
