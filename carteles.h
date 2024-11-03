#pragma once
#include<iostream>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"
#include "modoJuego.h"
//#include "ranking.h"
#include "carteles.h"


/**Etiquetas de funciones de mostrares para
mostrar durante el programa.*/

void mostrarmostrarGreed() ;
void pedirNombre(std::string& jugador1, std::string& jugador2);
 int mostrarMenu();

void mostrarPrimerTurno(std::string jugador1);

void mostrarPrimerTurno(std::string jugador1);
void mostrarTituloDadosBloqueadores();

void mostrarRonda(int ronda);
void mostrarEspacioPDados();
void mostrarTituloDadosQSuman();
void mostrarNroTirada(int cDtiradas);
void mostrarDuplicaONo(bool duplicar);
void mostrarResumenPuntaje(int puntaje, int ronda, int aP[]);
char preguntaContinuarTirando(char pregunta);
void mostrarNroTirada(int cDtiradas);
void mostrarPuntajeTirada(int puntaje);
void mostrarPuntajeRonda(int ronda, int aP[]);
void mostrarMsjCambioJugador(std::string jugador);
void mostrarMsjSumaCero();
void mostrarMsjFinRondas(std::string jugador, int ronda, int aP[]);
void mostrarTotalPtsAmbosJugadores(std::string jugador1, std::string jugador2, int acumuladoPuntajeTotalJugador1, int acumuladoPuntajeTotalJugador2);
void mostrarGanador(std::string jugador);
void mostrarMsjFinalJuego();
void mostrarBarraDivisora();
///probar
void titilar(std::string mensaje, int posicionC, int posicionF);
