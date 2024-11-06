#include<iostream>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"
//#include "ranking.h"
#include "carteles.h"
#include "dados.h"
using namespace std;


void modoDosJugadores() {
    rlutil::cls();
    string jugador1, jugador2;

    pedirNombre(jugador1, jugador2);
    rlutil::msleep(1000);
    rlutil::cls();
    mostrarBarraDivisoraLarga();
   cout << "                Cargando datos para tu partida..." << endl;
   mostrarBarraDivisoraLarga();
    rlutil::msleep(1000);
    rlutil::cls();
    srand(time(0));

    int x, ronda, aPt = 0, aP[3] = {}, aPt2 = 0, aP2[3] = {};

    mostrarPrimerTurno(jugador1);

        ///Ronda1
        ronda = 0;
        sonidoRonda();
        codigoRonda(jugador1, ronda, aPt, aP);
        mostrarMsjCambioJugador(jugador2);
        codigoRonda(jugador2, ronda, aPt2, aP2);
        mostrarMsjCambioJugador(jugador1);
        ///Ronda2
        ronda = 1;
        sonidoRonda();
        Beep(1568, 100); Sleep(8);
        codigoRonda(jugador1, ronda, aPt, aP);
        mostrarMsjCambioJugador(jugador2);
        codigoRonda(jugador2, ronda, aPt2, aP2);
        mostrarMsjCambioJugador(jugador1);
        ///Ronda3
        ronda = 2;
        sonidoRonda();
        Beep(1568, 100); Sleep(8);
        codigoRonda(jugador1, ronda, aPt, aP);
        mostrarMsjCambioJugador(jugador2);
        codigoRonda(jugador2, ronda, aPt2, aP2);

    cout << "Presione cualquier tecla para continuar ... " << endl;
    rlutil::anykey();
    for(x = 0; x < 3; x++) {
        aPt += aP[x];
        }
        for( x = 0; x < 3; x++) {
            aPt2 += aP2[x];
        }
        if(aPt > aPt2) {
            mostrarGanador(jugador1);
        } else {
            mostrarGanador(jugador2);
            }
    mostrarTotalPtsAmbosJugadores(jugador1, jugador2, aPt, aPt2);
    mostrarMsjFinalJuego();
    cout << "Presione cualquier tecla para continuar ... " << endl;
    rlutil::anykey();
    mostrarBarraDivisora();
    int selection = mostrarMenu();
    procesarSelection(selection);
 }


/// Funcionalidad 1 Jugador

void modoUnJugador(){

 srand(time(0));

    string jugador;
    int x, ronda, aPt, aP[3]= {};

    mostrarBarraDivisoraLarga();
    cout << "Bienvenido  al modo 1 Jugador." << endl;
     mostrarBarraDivisoraLarga();
     cout << "Ingresa tu nombre" << endl;
     cin >> jugador;
     cout << "Estas listo para tirar los dados de la suerte ?" << endl;
     rlutil::msleep(1000);
     rlutil::cls();

        ronda = 0;
        sonidoRonda();
        codigoRonda(jugador, ronda, aPt, aP);
         ronda = 1;
         sonidoRonda();
        codigoRonda(jugador, ronda, aPt, aP);
         ronda = 2;
         sonidoRonda();
        codigoRonda(jugador, ronda, aPt, aP);
        for(x = 0; x < 3; x++) {
        aPt += aP[x];
            }

    cout << "Felicitaciones!!! Tu puntaje total para las 3 rondas  fue de : " << aPt << "!!!" << endl;
    mostrarMsjFinalJuego();
    cout << "Presione cualquier tecla para continuar ... " << endl;
    rlutil::anykey();
    mostrarBarraDivisoraLarga();
    int selection = mostrarMenu();
    procesarSelection(selection);
}


 /// Funcionalidad de la ronda

void codigoRonda(string jugador, int& ronda, int aPt, int aP[]){
        srand(time(0));
        int tam = 2, t = 5, vB[2] = {}, vD[t] = {}, cD = 0, puntaje = 0, cDtiradas = 1;
        bool duplicar;
        char pregunta = 'S';

        mostrarRonda(ronda);
        mostrarNroTirada(cDtiradas);
        mostrarTituloDadosBloqueadores();
        rlutil::locate(1,9);
        tiradaBloqueadores(vB, tam);
        rlutil::locate(1,11);
        mostrarDados(vB,tam);
        mostrarTituloTiradaDados();
        tiradaDeDados(vD,t);
        rlutil::locate(1,17);
        mostrarDados(vD, t);

        cD = dadosNuevos(vD, t, vB);
        ///actualizacion tamanio de dados
        t = cD;
        duplicar = dadosIguales(vD, t);
        mostrarTituloDadosQSuman();
        mostrarDados(vD, t);

        puntaje = sumarDados(vD, t);

        mostrarDuplicaONo(duplicar);

        if(duplicar == true){
            puntaje = puntaje*2;
        }
        aP[ronda] += puntaje;
        mostrarResumenPuntaje(puntaje, ronda, aP);
        ///Pregunta si desea continuar tirando
        do
        {
            if(duplicar != true){
               pregunta = preguntaContinuarTirando(pregunta);
                } else {
                pregunta = 'S';
                }
            rlutil::cls();
            mostrarmostrarGreed();
            /// Primera pantalla hasta aqui------------------------------------------------------------------------------------------
            rlutil::msleep(1000);
            rlutil::cls();
            if( pregunta == 'S') {
            mostrarRonda(ronda);
            mostrarNroTiradasMasUno(cDtiradas);
            mostrarTituloDadosBloqueadores();
            rlutil::locate(1,11);
            mostrarDados(vB, tam);
            rlutil::locate(1,13);
            dibujarBloqueadores(vB);
            mostrarTituloTiradaDados();
            tiradaDeDados(vD, t);
            rlutil::locate(1,17);
            cDtiradas++;
            mostrarDados(vD, t);
            duplicar = dadosIguales(vD, t);
            cD = dadosNuevos(vD, t, vB);
            t = cD;
            mostrarDuplicaONo(duplicar);
            mostrarTituloDadosQSuman();
            mostrarDados(vD, t);
            mostrarBarraDivisora();
            puntaje = sumarDados(vD, t);
            if(duplicar == true) {
                    puntaje = puntaje*2;
            }
            if(puntaje != 0) {
            aP[ronda] += puntaje;
            mostrarResumenPuntaje(puntaje, ronda, aP);
                } else {
                aP[ronda] = 0;
                mostrarMsjSumaCero();
                pregunta = 'N';
                }
                } else {
                    cout << jugador << " consiguio en la ronda " << ronda+1 << " : "<< aP[ronda] <<"pts!" <<endl;
                    //mostrarMensajeSegunPuntaje(ap[ronda]);
                    }
                mostrarBarraDivisora();
                } while(pregunta != 'N');
            }
