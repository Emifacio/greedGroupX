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


        duplicar = dadosIguales(vD, t);
        cartelDuplicaONo(duplica);


        cD = dadosNuevos(vD, t, vB);
        ///actualizacion tamanio de dados
        t = cD;
        mostrarDados(vD, t);
        cout << endl;

       // TODO verificar que solo duplique el puntaje de la tirada y automaticamente tire otra vez.
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






