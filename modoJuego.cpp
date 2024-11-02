#include<iostream>
#include<ctime>
#include "funciones.h"
#include "rlutil.h"
//#include "ranking.h"
#include "carteles.h"
using namespace std;



void modoDosJugadores(string& jugador1, string& jugador2) {

    srand(time(0));


    int x, ronda, aPt = 0, aP[3] = {}, aPt2 = 0, aP2[3] = {};

    mostrarPrimerTurno(jugador1);

  //TODO agregar 1 segundo de espera;

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

    //TODO ofrecer jugar una nueva partida.
}


/// Funcionalidad 1 Jugador


/*void modoUnJugador(string jugador1) {

    srand(time(0));


    // Variables para los tamaños de los dados y arrays.
    int x, tam = 2, t = 5, vB[2] = {}, vD[t] = {}, nT = 0, vDn[t] = {}, cD = 0, puntaje = 0;
    char pregunta = 'S'; // Variable para la decisión del usuario de continuar o no
    bool duplicar;///Variable para saber si hay que duplicar el puntaje

    int x, ronda, aPt, aP[3]= {};




    // Llama a la función para generar los dados del jugador
    tiradaDeDados(vD, t);
    cout << "===================================" << endl;

    duplicar=dadosIguales(vD,t);
    cout<<"son iguales o no "<<duplicar<<endl;///Es para verificar despues se elimina!

    // Llama a la función para filtrar los dados bloqueados y devuelve cuántos quedan
    cD = dadosNuevos(vD, vB);

    // Muestra los dados disponibles después de filtrar los bloqueados
    mostrarDados(vD, cD);
    cout << endl;

    // Suma los puntos de los dados disponibles
    puntaje = sumarDados(vD, cD);
    cout << "puntaje " << puntaje << endl;
///Condicion para duplicar el puntaje
    if(duplicar==true)
        {
            puntaje=puntaje*2;
        }
        cout<<"puntaje "<<puntaje<<endl;

    // Bucle para permitir al usuario decidir si continuar o no con la tirada de dados
    do

    for(ronda=0; ronda<3; ronda++)

    {
        int x,tam=2,t=5,vB[2]= {},vD[t]= {},cD=0,puntaje=0,cDtiradas=1;
        bool duplicar;
        char pregunta='S';

        cout<<"==================================="<<endl;
        cout<<"Numero de ronda : "<<ronda+1<<endl;
        cout<<"==================================="<<endl;
        tiradaBloqueadores(vB,tam);

        mostrarDados(vB,tam);
        cout<<endl;
        cout<<"==================================="<<endl;

        tiradaDeDados(vD,t);

        cout<<"Numero de tirada : "<<cDtiradas<<endl;

        mostrarDados(vD,t);
        cout<<endl;
        duplicar=dadosIguales(vD,t);
        cout<<"son iguales o no "<<duplicar<<endl;
        cout<<"==================================="<<endl;
        cD=dadosNuevos(vD,t,vB);
        ///actualizacion tama├▒o de dados
        t=cD;

        mostrarDados(vD,t);
        cout<<endl;
        puntaje=sumarDados(vD,t);
        if(duplicar==true)
        {
            puntaje=puntaje*2;
        }
        cout<<"puntaje "<<puntaje<<endl;
        aP[ronda]+=puntaje;
        cout<<"Puntaje total ronda "<<aP[ronda]<<endl;
///pregunta continuacion de tirada
        do
        {
            if(duplicar!=true)
            {
                cout<<"Desea continuar tirando (S para seguir o N para sumar los puntos acumulados):"<<endl;
                cin>>pregunta;
            }
            else
            {
                pregunta='S';
            }
            cout<<endl;
            if(pregunta=='S')
            {

                tiradaDeDados(vD,t);
                cDtiradas++;
                cout<<"Numero de tirada : "<<cDtiradas<<endl;
                cout<<endl;
                mostrarDados(vD,t);
                cout<<endl;
                duplicar=dadosIguales(vD,t);
                cout<<"son iguales o no "<<duplicar<<endl;
                cout<<"==================================="<<endl;
                cD=dadosNuevos(vD,t,vB);
                ///cout<<" cD "<<cD;
                cout<<endl;
                t=cD;

                mostrarDados(vD,t);
                cout<<endl;

                puntaje=sumarDados(vD,t);
                if(duplicar==true)
                {
                    puntaje=puntaje*2;
                }

                cout<<"puntaje "<<puntaje<<endl;
                if(puntaje!=0)
                {
                    aP[ronda]+=puntaje;
                    cout<<"Puntaje total ronda "<<aP[ronda]<<endl;
                }
                else
                {
                    aP[ronda]=0;
                    cout<<"Puntaje en cero, te quedaste sin dados!! "<<aP[ronda]<<endl;
                    pregunta='N';



                }

            }
            else
            {
                cout<<"Pasamos a la siguiente ronda !"<<endl;



                cout<<"esto dejo Puntaje total ronda "<<aP[ronda]<<endl;
            }



        }
        while(pregunta!='N');
        cout<<"Pasamos a la ronda "<<ronda+2<<endl;

    }
    for(x=0; x<3; x++)
    {
        aPt+=aP[x];
    }


    cout<<"Puntaje total de las 3 rondas : "<<aPt<<endl;
    return 0;
}
}

*/
