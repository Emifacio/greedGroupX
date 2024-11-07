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

///Ranking

void menuEstadisticas() {
    int ranking[10] {};
    int opcion;
    srand(time(0));
    cargarPuntosAutomaticos(ranking);
    ordenar(ranking, 10);
    bool rankear = true;

    while (rankear) {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1 - Cargar Puntos" << endl;
        cout << "2 - Mostrar Ranking" << endl;
        cout << "0 - Volver al menu principal" << endl;
        cin >> opcion;
        rlutil::msleep(1000);

        switch (opcion) {
            case 1:
                sonidoEleccion();
                cargarPuntos(ranking);
                break;
            case 2:
                sonidoEleccion();
                mostrarRanking(ranking);
                                break;
            case 0:
                sonidoEleccion();
                rlutil::cls();
                cout << "Volviendo al menu principal..." << endl;
                mostrarBarraDivisoraLarga();
                rlutil::msleep(1000);
                rlutil::cls();
                rankear = false;
                break;
                return;
        }
    }
}



void cargarPuntos(int ranking[]) {
    int puntos;
    cout << "Ingrese un nuevo puntaje: ";
    cin >> puntos;

    // busca en que índice insertar el nuevo puntaje
    int index = 0;
    while (index < 10 && puntos < ranking[index]) {
        index++;
    }

    // mueve el arreglo para hacer espacio para el nuevo valor
    for (int i = 9; i > index; i--) {
        ranking[i] = ranking[i-1];
    }

    // agrega el nuevo valor
    ranking[index] = puntos;
}

void mostrarRanking(int ranking[]) {
        for(int i = 0; i < 10; i++) {
        if(ranking[i] != 0){

    cout << "#" << std::setfill(' ') << std::setw(2) << i+1 << std::setw(10) << ranking[i] << endl;
    }
}
    system("pause");
}

void cargarPuntosAutomaticos(int ranking[]){
    for(int i=0; i <10; i++){
        ranking[i] = rand() % 100 + 1;
        }
}

void ordenar(int vec[], int cant)
{
     int actual, masGrande, j, temp;

     for (actual = 0; actual < cant - 1; actual++)
     {
         masGrande = actual;

         for (j = actual ; j < cant; j++){
              if (vec[j] > vec[masGrande]){
                  masGrande = j;
                  }
                }

        // guia 1 - ejercicio 2
          temp = vec[actual];
          vec[actual] = vec[masGrande];
          vec[masGrande] = temp;
     }
}



