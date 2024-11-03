#include<iostream>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"
//#include "ranking.h"
#include "carteles.h"
using namespace std;



void modoDosJugadores() {
    string jugador1, jugador2;

    pedirNombre(jugador1, jugador2);
    srand(time(0));


    int x, ronda, aPt = 0, aP[3] = {}, aPt2 = 0, aP2[3] = {};

    mostrarPrimerTurno(jugador1);

    rlutil::msleep(1000);

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
            rlutil::cls();

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
                    rlutil::msleep(1000);
                    }

                mostrarBarraDivisora();

                } while(pregunta != 'N');
                mostrarMsjCambioJugador(jugador2);
                rlutil::msleep(1000);

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
            rlutil::cls();

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
    rlutil::msleep(2000);

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
    // TODO mostrarMsjRecordAlcanzado(); --> mostrar mensaje si alcanza un nuevo record
    // Ranking() --> Menu para anotar record

    mostrarMsjFinalJuego();

    //TODO ofrecer jugar una nueva partida.
}
////////////////////////////////////////////////////////////////////1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////1//1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Funcionalidad 1 Jugador

void modoUnJugador(){

 srand(time(0));

    int x, ronda, aPt, aP[3]= {};
    //TODO mostrarMjeBienvenidaUnJugador();
    //mostrarMjeBienvenidaUnJugador();
    cout << endl;
    cout << endl;
    cout << "Bienvenido  al modo 1 Jugador." << endl;
    cout << endl;
    cout << endl;
    rlutil::msleep(1000);

    for (ronda = 0; ronda < 3; ronda++) {

            int x, tam = 2, t = 5, vB[2] = {}, vD[t] = {}, cD = 0, puntaje = 0, cDtiradas = 1;
            char pregunta = 'S'; // Variable para la decisión del usuario de continuar o no
            bool duplicar;///Variable para saber si hay que duplicar el puntaje

            mostrarRonda(ronda);
            tiradaBloqueadores(vB, tam);
            mostrarDados(vB, tam);

            mostrarBarraDivisora();

            // Llama a la función para generar los dados del jugador
            tiradaDeDados(vD,t);
			mostrarNroTirada(cDtiradas);

			mostrarDados(vD, t);
            // Llama a la función para filtrar los dados bloqueados y devuelve cuántos quedan
            cD = dadosNuevos(vD,t,vB);
            t = cD;
            // Muestra los dados disponibles después de filtrar los bloqueados
            mostrarTituloDadosQSuman();
            mostrarDados(vD, cD);

            duplicar=dadosIguales(vD,t);

            // Suma los puntos de los dados disponibles
            puntaje = sumarDados(vD, cD);

            if (puntaje != 0){
                    mostrarDuplicaONo(duplicar);
                                    }

            if(duplicar==true) {
                puntaje=puntaje*2;
                                        }
            aP[ronda] += puntaje;

            mostrarResumenPuntaje(puntaje, ronda, aP);

            // Bucle para permitir al usuario decidir si continuar o no con la tirada de dados
            do {
                if(duplicar == true){
                    pregunta = 'S';
                        } else {
                            pregunta = preguntaContinuarTirando(pregunta);
                                  }

                            rlutil::cls();

                            mostrarTituloDadosBloqueadores();
                            mostrarDados(vB, tam);

                            mostrarBarraDivisora();


                          if(pregunta == 'S') {

                            tiradaDeDados(vD,t);
                            cDtiradas++;
                            mostrarNroTirada(cDtiradas);
                            mostrarDados(vD,t);

                            cD=dadosNuevos(vD,t,vB);
                            t=cD;

                            mostrarTituloDadosQSuman();
                            mostrarDados(vD,t);

                            duplicar=dadosIguales(vD,t);
                            puntaje=sumarDados(vD,t);

                            if(puntaje != 0){
                                mostrarDuplicaONo(duplicar);
                            }

                            if(duplicar==true) {
                                puntaje=puntaje*2;
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
                                cout <<"Jugador1 consiguio en la ronda " << ronda+1 << " : "<< aP[ronda] <<"pts!" <<endl;
                                ///mostrarMensajeSegunPuntaje(ap[ronda]);
                                }

								cout << "Pasamos a la siguiente ronda" << endl;

								cout << endl;
                                cout << endl;

								mostrarPuntajeRonda(ronda, aP);

								mostrarBarraDivisora();

                                }while(pregunta != 'N');
								mostrarRonda(ronda);
                            }

    for(x=0; x<3; x++)
    {
        aPt+=aP[x];
    }

    // TODO mostrar mensaje de felicitaciones si alcanza un nuevo record
    // mostrarRanking() --> Menu para anotar record
    cout << "Felicitaciones!!! Tu puntaje total para las 3 rondas  fue de : " << aPt << "!!!" << endl;
	cout << endl;
    cout << endl;
	cout << endl;

	rlutil::msleep(5000);

    //TODO ofrecer jugar una nueva partida.


}


