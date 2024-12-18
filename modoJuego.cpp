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
    rlutil::msleep(500);
    rlutil::cls();
    mostrarBarraDivisoraLarga();
   cout << "                Cargando datos para tu partida..." << endl;
   mostrarBarraDivisoraLarga();
    rlutil::msleep(500);
    rlutil::cls();
    srand(time(0));

    int x, ronda, aPt = 0, aP[3] = {}, aPt2 = 0, aP2[3] = {};

    mostrarPrimerTurnoColor(jugador1);

        ///Ronda1
        ronda = 0;
        codigoRonda(jugador1, ronda, aPt, aP);
        mostrarMsjCambioJugadorColor(jugador2);
        codigoRonda(jugador2, ronda, aPt2, aP2);
        mostrarMsjCambioJugadorColor(jugador1);
        ///Ronda2
        ronda = 1;
        codigoRonda(jugador1, ronda, aPt, aP);
        mostrarMsjCambioJugadorColor(jugador2);
        codigoRonda(jugador2, ronda, aPt2, aP2);
        mostrarMsjCambioJugadorColor(jugador1);
        ///Ronda3
        ronda = 2;
        codigoRonda(jugador1, ronda, aPt, aP);
        mostrarMsjCambioJugadorColor(jugador2);
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
            mostrarGanadorColor(jugador1);
        } else {
            mostrarGanadorColor(jugador2);
            }
    mostrarTotalPtsAmbosJugadores(jugador1, jugador2, aPt, aPt2);
    rlutil::msleep(2000);
    system("cls");
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    mostrarMsjFinalJuegoColor();
    cout << "Presione cualquier tecla para continuar ... " << endl;
    rlutil::anykey();
    rlutil::cls();
 }


/// Funcionalidad 1 Jugador

void modoUnJugador(){

 srand(time(0));// en el main

    string jugador;
    int x, ronda, aPt=0, aP[3]= {};

    mostrarBarraDivisoraLarga();
    cout << "Bienvenido  al modo 1 Jugador." << endl;
     mostrarBarraDivisoraLarga();
     cout << "Ingresa tu nombre" << endl;
     cin >> jugador;
     cout << "Estas listo para tirar los dados de la suerte ?" << endl;
     rlutil::msleep(2000);
     rlutil::cls();

        ronda = 0;
        codigoRonda(jugador, ronda, aPt, aP);
        ronda = 1;
        codigoRonda(jugador, ronda, aPt, aP);
        ronda = 2;
        codigoRonda(jugador, ronda, aPt, aP);
        for(x = 0; x < 3; x++) {
        aPt += aP[x];
            }

    ///cout << "Felicitaciones!!! Tu puntaje total para las 3 rondas  fue de : " << aPt << "!!!" << endl;
    FelitacionesColor(aPt);
    mostrarMsjFinalJuego();
    cout << "Presione cualquier tecla para continuar ... " << endl;
    rlutil::anykey();
    rlutil::cls();
}


 /// Funcionalidad de la ronda

void codigoRonda(string jugador, int ronda, int aPt, int aP[]){
        srand(time(0));
        int tam = 2, t = 5, vB[2] = {}, vD[t] = {}, cD = 0, puntaje = 0, cDtiradas = 1;
        bool duplicar;
        char pregunta = 'S';

        //mostrarRondaColor(ronda);
        mostrarNroTiradaColor(cDtiradas, ronda);
        mostrarTituloDadosBloqueadores();
        rlutil::locate(1,9);
        tiradaBloqueadores(vB, tam);
        rlutil::locate(1,11);
        mostrarDados(vB,tam);
        mostrarTituloTiradaDados();
        playSpiral(800, 6, 60);
        tiradaDeDados(vD,t);
        rlutil::locate(1,17);
        mostrarDados(vD, t);
        duplicar = dadosIguales(vD, t);

        cD = dadosNuevos(vD, t, vB);
        ///actualizacion tamanio de dados

        t = cD;
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
            rlutil::msleep(2000);
            rlutil::cls();
            mostrarmostrarGreed();
            /// Primera pantalla hasta aqui------------------------------------------------------------------------------------------
            rlutil::msleep(2000);
            rlutil::cls();
            if( pregunta == 'S') {
           // mostrarRondaColor(ronda);
            mostrarNroTiradasMasUnoColor(cDtiradas, ronda);
            mostrarTituloDadosBloqueadores();
            rlutil::locate(1,11);
            mostrarDados(vB, tam);
            rlutil::locate(1,13);
            dibujarBloqueadoresQuieto(vB);
            mostrarTituloTiradaDados();
            playSpiral(800, 6, 60);
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
                  } while(pregunta != 'N');
                  rlutil::msleep(1000);
                system("cls");
            }
