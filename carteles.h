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
void sonidoMostrarGreed();
void playSpiral(int startFreq, int steps, int duration);
void sonidoEleccion();
void sonidoRonda();
void sonidoPuntaje();
void mostrarmostrarGreed();
void pedirNombre(std::string& jugador1, std::string& jugador2);
int mostrarMenu();
void procesarSelection(int selection);

void mostrarPrimerTurno(std::string jugador1);

void mostrarRonda(int ronda);
void mostrarNroTirada(int cDtiradas);
void mostrarNroTiradasMasUno(int cDtiradas);

void mostrarTituloDadosBloqueadores();
void mostrarTituloTiradaDados();
void mostrarTituloDadosQSuman();

void mostrarDuplicaONo(bool duplicar);
void mostrarResumenPuntaje(int puntaje, int ronda, int aP[]);
char preguntaContinuarTirando(char pregunta);

void mostrarPuntajeTirada(int puntaje);
void mostrarPuntajeRonda(int ronda, int aP[]);

void mostrarMsjCambioJugador(std::string jugador);

void mostrarMsjSumaCero();

void mostrarMsjFinRondas(std::string jugador, int ronda, int aP[]);

void mostrarTotalPtsAmbosJugadores(std::string jugador1, std::string jugador2, int acumuladoPuntajeTotalJugador1, int acumuladoPuntajeTotalJugador2);

void mostrarGanador(std::string jugador);

void mostrarMsjFinalJuego();

void mostrarBarraDivisora();
void mostrarBarraDivisoraLarga();
///probar
void mostrarGanadorColor(std::string jugador);
void mostrarMsjFinalJuegoColor();
void imprimirPatronAlternadoColor(int posicionC,int posicionF);
void mostrarMsjCambioJugadorColor(std::string jugador);
void mostrarResumenPuntajeColor(int puntaje, int ronda, int aP[]);
int mostrarMenuColor();
void mostrarCreditos();
void mostrarRondaColor(int ronda);
void mostrarNroTiradaColor(int cDtiradas, int ronda);
void mostrarNroTiradasMasUnoColor(int cDtiradas, int ronda);
void FelitacionesColor(int puntajeTotal );

void mostrarPrimerTurnoColor(std::string jugador1);


void mostrarMsjSumaCeroColor();

