#pragma once
using namespace std;

/**Etiquetas de funciones de carteles para
mostrar durante el programa.*/

void mostrarCartelGreed() ;
void pedirNombre(string &jugador1, string &jugador2);
int mostrarMenu();
void procesarSeleccion(int selection);
void cartelPrimerTurno(string jugador1);
void cartelRonda(int ronda);
void cartelNroTirada(int cDtiradas);
void cartelDuplicaONo(bool duplica);
