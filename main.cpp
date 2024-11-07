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


     mostrarmostrarGreed();

     rlutil::cls();

    int selection = mostrarMenu();
    procesarSelection( selection);

    selection = mostrarMenu();
    procesarSelection( selection);
    return 0;
}
