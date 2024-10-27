# pragma once
using namespace std;



void pedirNombre(string jugador1, string jugador2);
void acumularPuntaje(int puntajeJ1, int puntajeJ2, vector puntajeRonda[]);
int mostrarMenu();
int procesarSeleccion(int seleccion);
void tiradaBloqueadores(int v[], int t);
void tiradaDeDados(int vD[], int tam);
bool dadosIguales(int vD[], int t);
int dadosNuevos(int vD[5], int vB[2]);
void mostrarDados(int vD[], int nT);



void mostrarCartelGreed();
void pedirNombre(string &jugador1, string &jugador2);
//void acumularPuntaje(int puntajeJ1, int puntajeJ2, vector puntajeRonda[]);
int mostrarMenu();
void procesarSeleccion(int seleccion);
void tiradaBloqueadores(int v[], int t);
int tirarDado();
void tiradaDeDados(int vD[], int tam);
bool dadosIguales(int vD[], int t);
int dadosNuevos(int vD[],int t,int vB[2]);
void mostrarDados(int vD[], int tam);

int sumarDados(int vD[], int t);


