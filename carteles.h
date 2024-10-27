#pragma once
using namespace std;

/**Etiquetas de funciones de mostrares para
mostrar durante el programa.*/

void mostrarmostrarGreed() ;
void pedirNombre(string &jugador1, string &jugador2);
int mostrarMenu();
void procesarSeleccion(int selection);
void mostrarPrimerTurno(string jugador1);
void mostrarTituloDadosBloqueadores();
void mostrarRonda(int ronda);
void mostrarTituloDadosQSuman();
void mostrarNroTirada(int cDtiradas);
void mostrarDuplicaONo(bool duplicar);
void mostrarResumenPuntaje(int puntaje, int ronda, int aP[]);
char preguntaContinuarTirando(char pregunta);
void mostrarNroTirada(int cDtiradas);
void mostrarPuntajeTirada(int puntaje);
void mostrarPuntajeRonda(int ronda, int aP[]);
void mostrarMsjCambioJugador(string jugador);
void mostrarMsjSumaCero();
void mostrarMsjFinRondas(string jugador, int ronda, int aP[]);
void mostrarTotalPtsAmbosJugadores(string jugador1, string jugador2, int acumuladoPuntajeTotalJugador1, int acumuladoPuntajeTotalJugador2);
void mostrarGanador(string jugador);
void mostrarMsjFinalJuego();
void mostrarBarraDivisora();
