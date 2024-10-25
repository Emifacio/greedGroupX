#include<iostream>
#include<ctime>
#include "funciones.h"
//#include "ranking.h"
#include "carteles.h"

using namespace std;


int main(){


    srand(time(0));
    string jugador1, jugador2;
    int x, ronda, aPt = 0, aP[3] = {}, aPt2 = 0, aP2[3] = {};
    bool duplicar;
    char pregunta = 'S';
    int eleccion;
//  int ranking[]{};



    mostrarCartelGreed();
    pedirNombre(jugador1,jugador2);

    cout << endl;
    cout << "==================================="<< endl;
    cout << endl;

    eleccion = mostrarMenu();
    procesarSeleccion(eleccion);

    cartelPrimerTurno(jugador1);

    for (ronda = 0; ronda < 3; ronda++) {
        int x, tam = 2, t = 5, vB[2] = {}, vD[t] = {}, cD = 0, puntaje = 0, cDtiradas = 1;

        cartelRonda(ronda);
        tiradaBloqueadores(vB, tam);
        mostrarDados(vB, tam);
        cout << endl;
        cout << "==================================="<< endl;

        tiradaDeDados(vD, t);
        cartelNroTirada(cDtiradas);
        mostrarDados(vD, t);
        cout << endl;

        ///TODO if para representar la respuesta numerica en palabra SI/NO
        duplicar = dadosIguales(vD, t);
        cout << "Son iguales? " << duplicar << endl;
        cout << "===================================" << endl;

        cD = dadosNuevos(vD, t, vB);
        ///actualizacion tamanio de dados
        t = cD;
        mostrarDados(vD, t);
        cout << endl;


        puntaje = sumarDados(vD, t);
        if(duplicar == true){
            puntaje = puntaje*2;
        }
        cout << "Puntos Tirada : " << puntaje << "pts" << endl;
        aP[ronda] += puntaje;
        cout << "Puntos Ronda : " << aP[ronda] << "pts"<< endl;
        cout << "==================================="<< endl;
        cout << endl;


        //Pregunta si desea continuar tirando
        do
        {
            if(duplicar != true){
                cout << "Desea continuar tirando (S para seguir o N para sumar los puntos acumulados): " << endl;
                cin >> pregunta;
                cout << endl;
            } else {
                pregunta = 'S';
            }
            //cout << endl;

            //limpiar la pantalla
            system("cls");


            // Volver a mostrar los dados bloqueadores después de limpiar la pantalla
            cout << "Dados bloqueadores:" << endl;
            mostrarDados(vB, tam);
            cout << endl;

                if( pregunta == 'S') {
                tiradaDeDados(vD, t);
                cDtiradas++;
                cout << "Tirada Nro : " << cDtiradas << endl;
                cout << endl;
                mostrarDados(vD, t);
                cout << endl;


                duplicar = dadosIguales(vD, t);
                cout << "Son iguales? " << duplicar << endl;
                cout << "===================================" << endl;


                cD = dadosNuevos(vD, t, vB);
                ///cout<<" cD "<<cD;
                cout << endl;
                t = cD;

                mostrarDados(vD, t);
                cout << endl;

                puntaje = sumarDados(vD, t);
                if(duplicar == true) {
                    puntaje = puntaje*2;
                }
                cout << "===================================" << endl;
                cout << "Puntos Tirada: " << puntaje << "pts" << endl;
                if(puntaje != 0) {
                    aP[ronda] += puntaje;
                cout << "Puntos Ronda : " << aP[ronda] << "pts" << endl;
                } else {
                    aP[ronda] = 0;
                    cout << "Te quedaste sin dados!! Sumas : " << aP[ronda] << "pts!" << endl;
                    pregunta = 'N';
                }
                cout << "===================================" << endl;
                cout << endl;
            } else {
                cout << jugador1 << " consiguio en la ronda " << ronda+1 << " : "<< aP[ronda] <<"pts!" <<endl;
                //TODO: mensaje personalizado si fue una buena ronda o no.
                cout << "------------------------------------------" << endl;
                cout << endl;
             }
        } while(pregunta != 'N');


        cout << endl;
        cout << "Es el turno de " << jugador2 << "." << endl;
        cout << endl;
        cout << "BUENA SUERTE!"<< endl;
        cout << endl;


        t = 5;
        cD = 0;
        puntaje = 0;
        cDtiradas = 1;
        cout << "===================================" << endl;
        cout << "Ronda Nro : " << ronda + 1 << endl;
        cout << "===================================" << endl;
        tiradaBloqueadores(vB, tam);

        mostrarDados(vB, tam);
        cout << endl;

        tiradaDeDados(vD, t);
        cout << "Tirada Nro : " << cDtiradas << endl;
        cout << "==================================="<< endl;
        cout << endl;
        mostrarDados(vD, t);
        cout << endl;
        duplicar = dadosIguales(vD, t);
        cout << "Son iguales? " << duplicar << endl ;
        cout << "===================================" <<endl;
        // Llama a la función para filtrar los dados bloqueados y devuelve cuántos quedan
        cD = dadosNuevos(vD, t, vB);
         t = cD;
        //Muestra los dados disponibles después de filtrar los bloqueados
        mostrarDados(vD, t);
        cout << endl;
         // Suma los puntos de los dados disponibles
        puntaje = sumarDados(vD, t);
        // Duplica si corresponde
        if(duplicar == true)
        {
            puntaje = puntaje*2;
        }
        cout << "Puntos Tirada : " << puntaje << " pts" <<endl;
        aP2[ronda] += puntaje;
        cout<<"Puntos Ronda : "<< aP2[ronda] << " pts" << endl;
///pregunta continuacion de tirada
        do
        {
            if(duplicar != true)
            {
                cout << "Desea continuar tirando ('S' para seguir o 'N' para sumar los puntos acumulados) : " << endl;
                cin >> pregunta;
                cout << endl;
            }
            else
            {
                pregunta = 'S';
            }
            // Limpiar la pantalla
            system("cls");

            // Volver a mostrar los dados bloqueadores después de limpiar la pantalla
            cout << "Dados bloqueadores:" << endl;
            mostrarDados(vB, tam);
            cout << endl;
            cout << endl;
            if( pregunta == 'S') {
                tiradaDeDados(vD, t);
                cDtiradas++;
                cout << "Tirada Nro : " << cDtiradas << endl;
                cout << endl;
                mostrarDados(vD, t);
                cout << endl;
                duplicar = dadosIguales(vD, t);
                cout << "Son iguales? "<< duplicar << endl;
                cout << "===================================" << endl;
                cD = dadosNuevos(vD, t, vB);
                ///cout<<" cD "<<cD; actualiza DADOS NUEVOS
                cout << endl;
                t = cD;

                mostrarDados(vD, t);
                cout << endl;

                puntaje = sumarDados(vD, t);
                if(duplicar == true)
                {
                    puntaje = puntaje*2;
                }

                cout << "Puntos Tirada : " << puntaje << endl;
                if( puntaje != 0)
                {
                    aP2[ronda] += puntaje;
                    cout << "Puntos Ronda : "<< aP2[ronda] << endl;
                }
                else
                {
                    aP2[ronda] = 0;
                    cout << "Te quedaste sin dados!! Sumas : " << aP[ronda] << "pts!" << endl;
                    pregunta = 'N';
                }
            }
              else
              {
                //cout << "Pasamos al siguiente jugador ! " << endl;
                cout << jugador2 << " consiguio en la ronda " << ronda+1 << " : "<< aP[ronda] <<"pts!" <<endl;
                cout <<"Nada mal!" <<endl;
                cout << endl;
                cout << "===================================" << endl;
                cout << endl;
               }
        }
        while(pregunta != 'N');
        cout << endl;
        // TODO eliminar esta linea en la ultima ronda
        if(ronda!=2){
        cout << "Es el Turno de " << jugador1 << "." << endl;
        }
        }
    for(x = 0; x < 3; x++)
    {
        aPt += aP[x];
    }
    for( x = 0; x < 3; x++)
    {
        aPt2 += aP2[x];
    }

    cout << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "Puntaje total de las 3 rondas de " << jugador1 << " es : " << aPt << "pts!!" << endl;
    cout << endl;
    cout << "Puntaje total de las 3 rondas de " << jugador2 << " es : " << aPt2 << "pts!!" << endl;
    if(aPt > aPt2)
    {
        cout << endl;
        cout << "El puntaje mas alto fue conseguido por " << jugador1 << "!!!" << endl;
        cout << endl;
        cout << "===================================" << endl;
        cout << endl;
        cout << " ********************************************" << endl;
        cout << "**********************************************" << endl;
        cout <<"    "<< jugador1 << " #GANASTE!! #FELICITACIONES!!!!" << endl;
        cout << "**********************************************" << endl;
        cout << " ********************************************" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "El puntaje mas alto fue conseguido por " << jugador2 << "!!!" << endl;
        cout << endl;
        cout << " ********************************************" << endl;
        cout << "**********************************************" << endl;
        cout << "    "<< jugador2 << " #GANASTE!! #FELICITACIONES!!!!" << endl;
        cout << "**********************************************" << endl;
        cout << " ********************************************" << endl;
        cout << endl;
    }
    cout << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "    EL JUEGO HA FINALIZADO"<<endl;
    cout << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "   <3  GRACIAS POR JUGAR!!! <3" << endl;
    cout << endl;
    cout << "===================================" << endl;
    cout << endl;


    //TODO ofrecer jugar una nueva partida.


    return 0;
}







