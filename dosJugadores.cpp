/// Funcionalidad del modo 2 jugadores
#include <iostream>
#define FUNCIONES_H
#include <string>
#include "funciones.h"
#include "ranking.h"
#include "rlutil.h"
#include "carteles.h"
using namespace std;
//#include "ranking.h"






void modoDosJugadores(string jugador1, string jugador2){



    srand(time(0));
    string jugador1, jugador2;
    int x, ronda, aPt = 0, aP[3] = {}, aPt2 = 0, aP2[3] = {};
    int eleccion;
//  int ranking[]{};

    mostrarmostrarGreed();
    pedirNombre(jugador1, jugador2);

    mostrarBarraDivisora();

    eleccion = mostrarMenu();
    procesarSeleccion(eleccion);

    mostrarPrimerTurno(jugador1);
 // agregar 1 segundo de espera;

    for (ronda = 0; ronda < 3; ronda++) {

        int x, tam = 2, t = 5, vB[2] = {}, vD[t] = {}, cD = 0, puntaje = 0, cDtiradas = 1;

    ///probar dados dibujados
    int vFila[6]{rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1};
    bool seleccionados[6]{};
    bool duplicar;
    char pregunta = 'S';

    rlutil::hidecursor();  // Oculta el cursor
    rlutil::saveDefaultColor();

    for(int i=1; i<=5; i++)
    {
     dibujarCuadrado(i*10,vFila[i-1]);
     dibujarSombra(i*10,vFila[i-1]);
    }

    for(int i=1; i<=5; i++) {
        int columna=rand()%5;
        while(seleccionados[columna]){
            columna=rand()%5;
        }
        seleccionados[columna]=true;
      vD[columna]=tirarDadoRlutil((columna+1)*10,vFila[columna]);
    }
    ///---------------------------

        mostrarRonda(ronda);
        tiradaBloqueadores(vB, tam);
        mostrarDados(vB, tam);

        mostrarBarraDivisora();

        //tiradaDeDados(vD, t);
        mostrarNroTirada(cDtiradas);
        mostrarDados(vD, t);

        cD = dadosNuevos(vD, t, vB);
        ///actualizacion tamanio de dados
        t = cD;

        mostrarTituloDadosQSuman();
        mostrarDados(vD, t);

        duplicar = dadosIguales(vD, t);

        puntaje = sumarDados(vD, t);

        if(puntaje !=0){
         mostrarDuplicaONo(duplicar);
         }

        if(duplicar == true){
            puntaje = puntaje*2;
        }
        aP[ronda] += puntaje;

        mostrarResumenPuntaje(puntaje, ronda, aP);

        //Pregunta si desea continuar tirando
        do
        {
            if(duplicar == true){
                pregunta = 'S';
                } else {
                pregunta = preguntaContinuarTirando(pregunta);
                }
/// Primera pantalla hasta aqui------------------------------------------------------------------------------------------
            //limpiar la pantalla
            system("cls");

            mostrarTituloDadosBloqueadores();
            mostrarDados(vB, tam);

            mostrarBarraDivisora();

            if( pregunta == 'S') {
            tiradaDeDados(vD, t);
            cDtiradas++;
            mostrarNroTirada(cDtiradas);
            mostrarDados(vD, t);

            cD = dadosNuevos(vD, t, vB);
            t = cD;

            mostrarTituloDadosQSuman();
            mostrarDados(vD, t);

            duplicar = dadosIguales(vD, t);
            puntaje = sumarDados(vD, t);

            if(puntaje != 0){
            mostrarDuplicaONo(duplicar);
            }

            if(duplicar == true) {
                    puntaje = puntaje*2;
            }

            mostrarPuntajeTirada(puntaje);

            if(puntaje != 0) {
            aP[ronda] += puntaje;
            mostrarPuntajeRonda(ronda, aP);
                } else {
                aP[ronda] = 0;
                mostrarMsjSumaCero();
                pregunta = 'N';
                }
                } else {
                    cout << jugador1 << " consiguio en la ronda " << ronda+1 << " : "<< aP[ronda] <<"pts!" <<endl;
                    ///mostrarMensajeSegunPuntaje(ap[ronda]);
                    }

                mostrarBarraDivisora();

                } while(pregunta != 'N');
                mostrarMsjCambioJugador(jugador2);

        t = 5;
        cD = 0;
        puntaje = 0;
        cDtiradas = 1;
        mostrarRonda(ronda);
        tiradaBloqueadores(vB, tam);

        mostrarDados(vB, tam);
        mostrarBarraDivisora();
        tiradaDeDados(vD, t);
        mostrarNroTirada(cDtiradas);
        mostrarDados(vD, t);
        cD = dadosNuevos(vD, t, vB);
        t = cD;
        mostrarTituloDadosQSuman();
        mostrarDados(vD, t);

        duplicar = dadosIguales(vD, t);
        puntaje = sumarDados(vD, t);
        if(puntaje != 0){
            mostrarDuplicaONo(duplicar);
                }
        if(duplicar == true)
            {
            puntaje = puntaje*2;
            }
        aP2[ronda] += puntaje;
        mostrarResumenPuntaje(puntaje, ronda, aP2);

        //pregunta continuacion de tirada
        do {
            if(duplicar == true) {
                pregunta = 'S';
                }
            else {
                pregunta = preguntaContinuarTirando(pregunta);
                   }
            // Limpiar la pantalla
            system("cls");

            if( pregunta == 'S') {
                    mostrarTituloDadosBloqueadores();
                    mostrarDados(vB,tam);
                    mostrarBarraDivisora();
                    tiradaDeDados(vD, t);
                    cDtiradas++;
                    mostrarNroTirada(cDtiradas);
                    mostrarDados(vD, t);
                    cD = dadosNuevos(vD, t, vB);
                    t = cD;
                    mostrarTituloDadosQSuman();
                    mostrarDados(vD, t);

                    duplicar = dadosIguales(vD, t);
                    puntaje = sumarDados(vD, t);

                    if(puntaje != 0){
                        mostrarDuplicaONo(duplicar);
                            }
                    if(duplicar == true && puntaje != 0) {
                        puntaje = puntaje*2;
                            }

                    mostrarPuntajeTirada(puntaje);

                    if( puntaje != 0){
                        aP2[ronda] += puntaje;
                        mostrarPuntajeRonda(ronda, aP2);
                        } else {
                            aP2[ronda] = 0;
                            mostrarMsjSumaCero();
                            pregunta = 'N';
                                }
                    } else {
                        mostrarMsjFinRondas(jugador2, ronda, aP);
                        }
                        }
                        while(pregunta != 'N');
                        if(ronda != 2){
                            mostrarMsjCambioJugador(jugador1);
                        }
            }


    //Recuento de puntos acumulados
    for(x = 0; x < 3; x++)
    {
        aPt += aP[x];
    }
    for( x = 0; x < 3; x++)
    {
        aPt2 += aP2[x];
    }
    if(aPt > aPt2)
    {
        mostrarGanador(jugador1);
    }
    else
    {
        mostrarGanador(jugador2);
    }
    mostrarTotalPtsAmbosJugadores(jugador1, jugador2, aPt, aPt2);
    mostrarMsjFinalJuego();

}
