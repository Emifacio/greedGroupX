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
    int eleccion;
//  int ranking[]{};

    mostrarmostrarGreed();
    pedirNombre(jugador1,jugador2);

    mostrarBarraDivisora();

    eleccion = mostrarMenu();
    procesarSeleccion(eleccion);

    mostrarPrimerTurno(jugador1);

    for (ronda = 0; ronda < 3; ronda++) {
        int x, tam = 2, t = 5, vB[2] = {}, vD[t] = {}, cD = 0, puntaje = 0, cDtiradas = 1;
        bool duplicar;
        char pregunta = 'S';

        mostrarRonda(ronda);
        tiradaBloqueadores(vB, tam);
        mostrarDados(vB, tam);

        mostrarBarraDivisora();

        tiradaDeDados(vD, t);
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


    return 0;
}


/// Funcionalidad 1 Jugador

/*#include<iostream>
#include<ctime>
using namespace std;
///funcion tirada bloqueadores
void tiradaBloqueadores(int v[],int t)
{
    t=2;
    int x,dado;
    cout<<"Dados bloqueadores "<<endl;
    cout<<"==================================="<<endl;
    for(x=0; x<2; x++)
    {
        dado=(rand()%6+1);
        v[x]=dado;

    }
}
///funcion tirada dados
void tiradaDeDados(int vD[],int tam)
{
    tam=5;
    int x;
    cout<<"Tirada de Dados "<<endl;
    cout<<"==================================="<<endl;
    for(x=0; x<tam; x++)
    {
        vD[x]=(rand()%6+1);

    }
}
bool dadosIguales(int vD[], int t)
{
    int x,referencia,c=0;
    referencia=vD[0];
    for(x=0; x<t; x++)
    {
        if(referencia==vD[x])
        {
            c++;
        }
    }
    if(c>1 && c==t)
    {
        return true;
    }
    else
    {
        return false;
    }


}

//cout<<"dados con descuentos"<<endl;
int dadosNuevos(int vD[],int t,int vB[2])
{
    t;
    vD[t]= {};
    int x,cD=0;
    for(x=0; x<t; x++)
    {
        if(vD[x]==vB[0] || vD[x]==vB[1])
        {
            vD[x]=0;

        }
    }
    for(x=0; x<t; x++)
    {
        if(vD[x]!=0)
        {
            vD[cD]=vD[x];
            cD++;
        }
    }
    return cD;
}
///funcion mostrar dados
void mostrarDados(int vD[], int tam)
{
    int x;
    for(x=0; x<tam; x++)
    {
        cout<<"Dado = "<<vD[x]<<endl;
    }
}
///funcion suma de dados
int sumarDados(int vD[],int t)
{
    int x,aP=0;



    for(x=0; x<t; x++)
    {
        aP+=vD[x];
    }

    return aP;
}

int main()
{
    srand(time(0));

    int x,ronda,aPt,aP[3]= {};


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
*/






