/// Funciones de carteles para mostrar durante el programa.
#include <iostream>
#define FUNCIONES_H
#include <string>
#include "funciones.h"
#include "ranking.h"
using namespace std;

void mostrarCartelGreed() {
    cout<< endl;
    cout << "  GGGGG    RRRRR    EEEEE   EEEEE   DDDDD   \n";
    cout << " G        R    R   E       E       D    D  \n";
    cout << " G  GGG   RRRRR    EEEE    EEEE    D    D  \n";
    cout << " G    G   R  R     E       E       D    D  \n";
    cout << "  GGGGG   R   R    EEEEE   EEEEE   DDDDD   \n";
    cout << endl;
}


void pedirNombre(string &jugador1, string &jugador2){
cout   << "Ingresar nombre del jugador nro1 :  "<< endl;
cin >> jugador1;
cout   << "Ingresar nombre del jugador nro2 :  "<< endl;
cin >> jugador2;
}


int mostrarMenu() {

    cout << "Bienvenido al menu principal" << endl;
    cout << endl;
    int selection = 0;
        cout << " Por favor elija una de las siguientes opciones - \n";
        cout << " 1. Modo un jugador.\n";
        cout << " 2. Modo dos jugadores.\n";
        cout << " 3. Estadisticas.\n";
        cout << " 4. Creditos.\n";
        cout << " 5. Salir  .\n";
        cout << "\t";
        cin >> selection;

        return selection;
}



void procesarSeleccion(int selection) {
    switch (selection) {
        case 1:
            cout << "Has seleccionado la opcion 1 (Modo un jugador)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //juegaModo1Jugador();
            break;
        case 2:
            cout << "Has seleccionado la opcion 2 (Modo dos jugadores)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //JuegaModo2Jugadores();
            break;
        case 3:
            cout << "Has seleccionado la opcion 3 (Estadísticas)" << endl;
            /*Estadísticas: Deberá mostrar, si existe, el nombre
            y el puntaje del jugador que haya obtenido el puntaje más alto.
            Tener en cuenta que al cerrar la aplicación el puntaje se restablecerá.*/
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
                   //mostrarRanking();
            break;
        case 4:
            cout << "Has seleccionado la opcion 4 (Créditos)" << endl;
            /*Créditos: Deberá mostrar el nombre del equipo (inventar uno)
            junto con sus respectivos legajos, apellidos y nombres.*/
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
}


void cartelPrimerTurno(string jugador1){
    cout << endl;
    cout << "    Es el Turno de " << jugador1 <<"." <<endl;
    cout << endl;
    cout << "           A JUGAR!!"<< endl;
    cout << endl;
}


void cartelRonda(int ronda){
        cout << "==================================="<< endl;
        cout << endl;
        cout << endl;
        cout << "Ronda Nro : " << ronda + 1 << endl;
        cout << "===================================" << endl;
}

void cartelNroTirada(int cDtiradas){
cout << "Tirada Nro : " << cDtiradas << endl;
cout << "===================================" << endl;
}

void cartelDuplicaONo(duplica){
    if(duplica = true){
        cout << "Duplicas puntos!! Los dados son iguales." << endl;
        cout << "Tu siguiente tirada es automatica." << endl;
            }else{
                cout << "No duplicas puntos. Hay un dado o mas distintos." << endl;
                    }
        cout << "===================================" << endl;
    }
