/*#include <iostream>
using namespace std;
#include<ctime>

///Ranking

int ranking [10] {};
 srand(time(0));

do{
    system("cls");
    cout << "MENU PRINCIPAL" << endl;
    cout << "1 - Cargar Puntos" << endl;
    cout << "2 - Mostrar Ranking" << endl;
    cout << "0 - Salir" << endl;
    cin >> opcion;

    switch(opcion){
        case 11:
            cargarPuntosAutomaticos(ranking);
            break;
        case 1:
            cargarPuntos(ranking);
        case 2:




    }
}

//Otra manera de cargar puntos
void cargarPuntos(int ranking[]){
        cout << "Ingrese un nuevo puntaje: ";
        cin >> ranking[10];
        ordenar(ranking);
       }

void cargarPuntos(int ranking[]) {
    int puntos;
    cout << "Ingrese un nuevo puntaje: ";

    cin >> puntos;

    if(puntos > ranking[9]) {
        ranking[9] = puntos;
        ordenar(ranking, 10);
    }
}


void mostrarRanking(int rankingp[]) {
    for(int i = 0; i < 10; i++) {
        if(ranking[i] != 0){
        cout << "#" << setfill('0') << setw(2) << i+1 <<setfil('.') setw(10) << ranking[i] << endl;
        -
    }
}
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

         for (j = actual 1; j < cant; j++)
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


