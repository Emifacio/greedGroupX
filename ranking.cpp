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
/*
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
*/

// Función para asignar nombres aleatorios a puntajes
void asignarNombresAleatorios(int ranking[], string nombres[]) {
    string nombresAleatorios[] = {"Juan", "Ana", "Carlos", "Lucia", "Pedro", "Sofia", "Luis", "Marta", "Diego", "Valeria"};
    for (int i = 0; i < 10; i++) {
        if (ranking[i] != 0) {
            nombres[i] = nombresAleatorios[rand() % 10];
        }
    }
}



// Función para cargar puntos y nombres ingresados por el usuario
void agregarNombreYPuntaje(int ranking[], string nombres[]) {
    string nombre;
    int puntos;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre;
    cout << "Ingrese el puntaje del jugador: ";
    cin >> puntos;

    // Verifica si el puntaje es lo suficientemente alto para entrar en el ranking
    if (puntos < ranking[9]) {
        cout << "El puntaje no es lo suficientemente alto para entrar en el ranking." << endl;
        return;
    }

    // Busca el índice en el que insertar el nuevo puntaje
    int index = 0;
    while (index < 10 && puntos < ranking[index]) {
        index++;
    }

    // Mueve los elementos del ranking y los nombres hacia abajo para hacer espacio
    for (int i = 9; i > index; i--) {
        ranking[i] = ranking[i - 1];
        nombres[i] = nombres[i - 1];
    }

    // Inserta el nuevo puntaje y nombre en su lugar
    ranking[index] = puntos;
    nombres[index] = nombre;
}

// Función para cargar puntos automáticos
void cargarPuntosAutomaticos(int ranking[], string nombres[]) {
    for (int i = 0; i < 10; i++) {
        ranking[i] = rand() % 100 + 1;
    }
    asignarNombresAleatorios(ranking, nombres);
}

// Función para mostrar el ranking con nombres
void mostrarRanking(int ranking[], string nombres[]) {
    cout << "===== RANKING =====" << endl;
    for (int i = 0; i < 10; i++) {
        if (ranking[i] != 0) {
            cout << "#" << std::setfill(' ') << std::setw(2) << i + 1 << " - "
                 << std::setw(10) << nombres[i] << " : "
                 << std::setw(3) << ranking[i] << " pts" << endl;
        }
    }
rlutil::anykey(); // Pausa hasta que se presione una tecla
}


// Función para ordenar el ranking por puntaje (mayor a menor)
void ordenar(int ranking[], string nombres[], int cant) {
    for (int i = 0; i < cant - 1; i++) {
        for (int j = i + 1; j < cant; j++) {
            if (ranking[i] < ranking[j]) {
                // Intercambia los puntajes
                int tempPuntaje = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = tempPuntaje;

                // Intercambia los nombres
                string tempNombre = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = tempNombre;
            }
        }
    }
}

// Función para cargar puntajes ingresados manualmente
void cargarPuntos(int ranking[], string nombres[]) {
    int puntos;
    cout << "Ingrese un nuevo puntaje: ";
    cin >> puntos;

    if (puntos < ranking[9]) {
        cout << "El puntaje no es lo suficientemente alto para entrar en el ranking." << endl;
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre;

    int index = 0;
    while (index < 10 && puntos < ranking[index]) {
        index++;
    }

    for (int i = 9; i > index; i--) {
        ranking[i] = ranking[i - 1];
        nombres[i] = nombres[i - 1];
    }

    ranking[index] = puntos;
    nombres[index] = nombre;
}

// Función principal para el menú de estadísticas
void menuEstadisticas() {
    int ranking[10] = {};
    string nombres[10] = {};
    int opcion;
    srand(time(0));

    cargarPuntosAutomaticos(ranking, nombres);
    ordenar(ranking, nombres, 10);

    bool rankear = true;
    while (rankear) {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1 - Cargar Puntos" << endl;
        cout << "2 - Mostrar Ranking" << endl;
        cout << "3 - Agregar Nombre y Puntaje" << endl;
        cout << "0 - Volver al menu principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        rlutil::msleep(1000);

        switch (opcion) {
            case 1:
                sonidoEleccion();
                cargarPuntos(ranking, nombres);
                break;
            case 2:
                sonidoEleccion();
                mostrarRanking(ranking, nombres);
                break;
            case 3:
                sonidoEleccion();
                agregarNombreYPuntaje(ranking, nombres);
                break;
            case 0:
                sonidoEleccion();
                rlutil::cls();
                rankear = false;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                rlutil::msleep(1000);
                break;
        }
    }
}


