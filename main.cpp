#include<iostream>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"
//#include "ranking.h"
#include "carteles.h"
#include "modoJuego.h"
using namespace std;



int main(){

     mostrarmostrarGreed();
     mostrarBarraDivisora();

    int selection = mostrarMenu();
    cout << selection << endl;
          switch (selection) {
        case 1:
            cout << "Has seleccionado la opcion 1 (Modo un jugador)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            modoUnJugador();
            break;
        case 2:
            cout << "Has seleccionado la opcion 2 (Modo dos jugadores)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            modoDosJugadores();
            break;
        case 3:
            cout << "Has seleccionado la opcion 3 (Estadísticas)" << endl;
            //Estadísticas: Deberá mostrar, si existe, el nombre
            // y el puntaje del jugador que haya obtenido el puntaje más alto.
            //Tener en cuenta que al cerrar la aplicación el puntaje se restablecerá.
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
                   //mostrarRanking();
            break;
        case 4:
            cout << "Has seleccionado la opcion 4 (Créditos)" << endl;
            ///Créditos: Deberá mostrar el nombre del equipo (inventar uno)
            //junto con sus respectivos legajos, apellidos y nombres.
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            // mostrarCreditos();
            break;
        case 5:
            cout << "Gracias por jugar GreedX, espero verte pronto nuevamente!" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }


    mostrarBarraDivisora();

    return 0;
}
