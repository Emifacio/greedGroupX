/// Funciones de mostrares para mostrar durante el programa.
#include <iostream>
#include <string>
#include "funciones.h"
#include "ranking.h"
#include "rlutil.h"
#include "carteles.h"
#include "modoJuego.h"
using namespace std;
//#include "ranking.h"


void playSpiral(int startFreq, int steps, int duration) {
    for (int i = 0; i < steps; ++i) {
        Beep(startFreq + (i * 50), duration);
        Sleep(25);
    }
}


void sonidoEleccion()
{
    Beep(1175, 50);
    Sleep(4);
    Beep(1046, 50);
    Sleep(3);
}


void sonidoRonda()
{
    Beep(1568, 100);
    Sleep(7);
    Beep(1175, 50);
    Sleep(3);
    Beep(1046, 50);
    Sleep(2);
    Beep(988, 60);
    Sleep(1);
    Beep(880, 150);
    Sleep(10);
}

void sonidoPuntaje()
{
    Beep(659, 100);
    Sleep(15);
    Beep(659, 100);
    Sleep(15);
    Beep(784, 300);
}

void sonidoMostrarGreed(){
        Beep(1568, 100);
        Sleep(8);
        Beep(1175, 50);
        Sleep(4);
        Beep(1046, 50);
        Sleep(3);
        Beep(988, 60);
        Sleep(2);
        Beep(880, 150);
        Sleep(20);
        }

void mostrarmostrarGreed()
{
    int c = 15;
    int f = 12;


    for(int x=0; x<20; x++)
    {
        if (x == 1){
        sonidoMostrarGreed();
        }
        if(x%2==0)
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            rlutil::setBackgroundColor(rlutil::BLUE);
        }
        else
        {
            rlutil::setColor(rlutil::BLUE);
            rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
        }
        rlutil::hidecursor();
        cout<< endl;
        rlutil::locate(c,f);
        cout << "  GGGGG    RRRRR    EEEEE   EEEEE   DDDDD  \n";
        rlutil::locate(c,f+1);
        cout << " G        R    R   E       E       D    D  \n";
        rlutil::locate(c,f+2);
        cout << " G  GGG   RRRRR    EEEE    EEEE    D    D  \n";
        rlutil::locate(c,f+3);
        cout << " G    G   R  R     E       E       D    D  \n";
        rlutil::locate(c,f+4);
        cout << "  GGGGG   R   R    EEEEE   EEEEE   DDDDD   \n";
        cout << endl;
        rlutil::msleep(37);
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

}

void pedirNombre(string& jugador1, string& jugador2) {
    rlutil::locate(20,10);
    cout   << " Ingresar nombre del jugador nro1 :  "<< endl;
    rlutil::locate(20,11);
    cin >> jugador1;
    rlutil::locate(20,12);
    cout   << " Ingresar nombre del jugador nro2 :  "<< endl;
    rlutil::locate(20,13);
    cin >> jugador2;
}

int mostrarMenu()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "   ****************************" << endl;
    cout << "   **      Menu Principal    **" << endl;
    cout << "   **                        **" << endl;
    cout << "   **                        **" << endl;
    cout << "   **       Bienvenido       **" << endl;
    cout << "   ****************************" << endl;
    cout << endl;
    int selection = 0;
    cout << " Por favor elije una de las siguientes opciones : \n";
    cout << "       1. Modo un jugador.\n";
    cout << "       2. Modo dos jugadores.\n";
    cout << "       3. Estadisticas.\n";
    cout << "       4. Creditos.\n";
    cout << "       5. Salir  .\n";
    cout << "\t";
    cin >> selection;
    rlutil::hidecursor();

    return selection;
}

void procesarSelection(int selection)
{

    switch (selection)
    {
    case 1:
        sonidoEleccion();
        mostrarBarraDivisoraLarga();
        cout << "Has seleccionado la opcion 1 (Modo un jugador)" << endl;
        mostrarBarraDivisoraLarga();
        rlutil::msleep(500);
        rlutil::cls();
        modoUnJugador();
        break;
    case 2:
        sonidoEleccion();
        mostrarBarraDivisoraLarga();
        cout << "Has seleccionado la opcion 2 (Modo dos jugadores)" << endl;
        mostrarBarraDivisoraLarga();
        rlutil::msleep(500);
        rlutil::cls();
        modoDosJugadores();
        break;
    case 3:
        sonidoEleccion();
        mostrarBarraDivisoraLarga();
        cout << "Has seleccionado la opcion 3 (Estadisticas)" << endl;
        mostrarBarraDivisoraLarga();
        rlutil::msleep(500);
        rlutil::cls();
        menuEstadisticas();
        break;
    case 4:
        sonidoEleccion();
        mostrarBarraDivisoraLarga();
        cout << "Has seleccionado la opcion 4 (Creditos)" << endl;
        mostrarBarraDivisoraLarga();
        rlutil::msleep(500);
        rlutil::cls();
        mostrarCreditos();
        break;
    case 5:
        sonidoEleccion();
        mostrarBarraDivisoraLarga();
        cout << "Gracias por jugar GreedX, espero verte pronto nuevamente!" << endl;
        mostrarBarraDivisoraLarga();
        rlutil::msleep(500);
        rlutil::cls();
        break;
    default:
        mostrarBarraDivisoraLarga();
        cout << "Opcion no valida" << endl;
        mostrarBarraDivisoraLarga();
        break;

    }
}

void mostrarPrimerTurno(string jugador1)
{
    cout << endl;
    cout << "           ==================================="<< endl;
    cout << "           ||                               ||"<< endl;
    cout << "                  Es el Turno de " << jugador1 <<endl;
    cout << endl;
    cout << "           ||           A JUGAR!!           ||"<< endl;
    cout << "           ||                               ||"<<endl;
    cout << "           ==================================="<< endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "           Presiona una tecla para comenzar..." << endl;
    rlutil::anykey();
    rlutil::cls();
}

void mostrarTituloDadosBloqueadores()
{
    cout << endl;
    cout << "Dados bloqueadores:" << endl;
    cout << "==================================="<<endl;
}

void mostrarRonda(int ronda)
{
    cout << endl;
    cout << "       ********************"<< endl;
    cout << "       ** Ronda Nro : " << ronda + 1 << "  **" <<endl;
}

void mostrarNroTirada(int cDtiradas)
{
    cout <<"       **                **" << endl;
    cout << "       ** Tirada Nro : " <<  cDtiradas << " **" <<endl;
    cout << "       ********************" << endl;
    cout << endl;
}

void mostrarNroTiradasMasUno(int cDtiradas)
{
    cout <<"       **                **" << endl;
    cout << "       ** Tirada Nro : " <<  cDtiradas+1 << " **" <<endl;
    cout << "       ********************" << endl;
    cout << endl;
}

void mostrarTituloTiradaDados()
{

    cout << endl;
    cout << "===================================" << endl;
    cout << "Tirada de Dados " << endl;
    cout << "===================================" << endl;

}


void mostrarEspacioPDados()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void mostrarTituloDadosQSuman()
{
    cout << endl;
    cout << "==================================="<< endl;
    cout << "Dados que suman : " << endl;
    cout << "==================================="<< endl;
    cout << endl;
}

void mostrarDuplicaONo(bool duplicar)
{
    if(duplicar == true)
    {
        cout << endl;
        cout << "*Duplica puntos: Los dados son iguales." << endl;
        cout << "**Siguiente tirada automatica." << endl;
        cout << "Presione una tecla para continuar." << endl;
        rlutil::anykey();
    }
    else
    {
        cout << endl;
        cout << "*No duplica: Uno o mas dados distintos." << endl;
    }
    cout << endl;
}

void mostrarResumenPuntaje(int puntaje, int ronda, int aP[])
{
    sonidoPuntaje();
    cout << "   ****************************" << endl;
    cout << "   ** Puntos Tirada : " << puntaje << " pts **" << endl;
    cout << "   **                        **" << endl;
    cout << "   **                        **" << endl;
    cout << "   **  Puntos Ronda : " << aP[ronda] << " pts **" << endl;
    cout << "   ****************************" << endl;
    cout << endl;
}

char preguntaContinuarTirando(char pregunta)
{
    cout << " ¿Deseas continuar tirando (S/N)?" << endl;
    cin >> pregunta;
    cout << endl;

    return pregunta;
}



void mostrarPuntajeTirada(int puntaje)
{
    cout << " **************************" << endl;
    cout << " ** Puntos Tirada : " << puntaje << " pts **" << endl;
    cout << " **                       **" << endl;

}

void mostrarPuntajeRonda(int ronda, int aP[])
{
    cout << " **                       **" << endl;
    cout << " **  Puntos Ronda : " << aP[ronda] << " pts**" << endl;
    cout << " ***************************" << endl;
    cout << endl;
}

void mostrarMsjCambioJugador(string jugador)
{

    cout << "Cambio el turno...  " << jugador << " presiona una tecla si estas listo!!!" << endl;
    rlutil::anykey();
    rlutil::cls();
    cout << endl;
    cout << "           *   *   *                   "<<endl;
    cout << endl;
    cout << "   -----------------------------" << endl;
    cout << "       ES EL TURNO DE " << jugador << "!" << endl;
    cout << endl;
    cout << "           BUENA SUERTE!"<< endl;
    cout << "   -----------------------------" << endl;
    cout << endl;
    rlutil::msleep(750);
    rlutil::cls();
}

void mostrarMsjSumaCero()
{
    cout << endl;
    cout << endl;
    Beep(880, 150);
    Sleep(100);
    cout << "|:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(|" << endl;
    cout << "Todos tus dados fueron bloqueados!! Sumas : 0pts." << endl;
    cout << "|:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(|" << endl;
    cout << endl;
    cout << endl;

}

void mostrarMsjFinRondas(string jugador, int ronda, int aP[])
{
    cout <<"* "<< "En la ronda " << ronda+1 <<" "<< jugador << " consiguio : "<< aP[ronda] <<"pts." <<endl;
    cout << endl;
    cout << endl;
    cout << "                *    *    *" << endl;
}


void mostrarTotalPtsAmbosJugadores(string jugador1, string jugador2,int acumuladoPuntajeTotalJugador1,int acumuladoPuntajeTotalJugador2)
{
    cout << endl;
    cout << "        === Resultados Finales ===" << endl;
    cout << "            *******************" << endl;
    cout << endl;
    cout << "       Puntaje total de " << jugador1 << " : " << acumuladoPuntajeTotalJugador1 << "pts" << endl;
    cout << endl;
    cout << "       Puntaje total de " << jugador2 << " : " << acumuladoPuntajeTotalJugador2 << "pts" << endl;
    cout << endl;
}

void imprimirPatronAlternado(int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            // Condición para alternar espacios y asteriscos
            if ((i + j) % 2 == 0)
            {
                cout << " *";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void mostrarGanador(string jugador)
{
    cout << endl;
    cout << "EL JUGADOR QUE CONSIGUIO EL MEJOR PUNTAJE FUE : ..." << endl;
    cout << endl;
    rlutil::msleep(2000);
    imprimirPatronAlternado(26);
    rlutil::msleep(2000);
    cout << endl;
    cout << endl;
    cout << "               ** " <<  jugador << "!!! **" << endl;
    cout << endl;
    cout << endl;
    cout << " ********************************************" << endl;
    cout << endl;
    cout <<"    "<< jugador << " #GANASTE! #FELICITACIONES!!!" << endl;
    cout << endl;
    cout << " ********************************************" << endl;
    cout << endl;
}

void mostrarMsjFinalJuego()
{
    cout << endl;
    cout << "                *    *    *" << endl;
    cout << endl;
    cout << "           EL JUEGO HA FINALIZADO"<<endl;
    cout << endl;
    cout << "                *    *    *" << endl;
    cout << endl;
    cout << "            GRACIAS POR JUGAR!!!" << endl;
    cout << endl;
    cout << "                *    *    *" << endl;
    cout << endl;
}


void mostrarBarraDivisora()
{
    cout << endl;
    cout << "==================================="<< endl;

    cout << endl;
}

void mostrarBarraDivisoraLarga()
{
    cout << endl;
    cout << "======================================================================"<< endl;

    cout << endl;
}

///Creditos
void mostrarCreditos()
{
    cout << "******************************************" << endl;
    cout << "*                Creditos                *" << endl;
    cout << "******************************************" << endl;
    cout << "* Wolfman Entertainments                 *" << endl;
    cout << "* Juego desarrollado por:                *" << endl;
    cout << "* - Gabriel Emiliano Facio(Legajo: 32015)*" << endl;
    cout << "* - Raul Oscar Luppini (Legajo: 30439)   *" << endl;
    cout << "*                                        *" << endl;
    cout << "* Inspiracion:                           *" << endl;
    cout << "* Basado en el juego 'Greed' y en juegos *" << endl;
    cout << "* 'Push your luck' de Bob Lancaster, como*" << endl;
    cout << "* el original 'Push Your Luck'.          *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << endl;

    rlutil::anykey();
    rlutil::cls();
}

///Funciones colores

void mostrarGanadorColor(string jugador)
{
    int posicionC=2;
    int posicionF=2;
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::setBackgroundColor(rlutil::YELLOW);

    rlutil::locate(posicionC,posicionF);
    cout << " EL JUGADOR QUE CONSIGUIO EL MEJOR PUNTAJE FUE : ... " << endl;
    //cout << endl;

    imprimirPatronAlternadoColor(1,4);
    for(int x=0; x<10; x++)
    {
        if(x%2==0)
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
            rlutil::setBackgroundColor(rlutil::YELLOW);
            rlutil::locate(posicionC,25);
            cout << "               ** " <<  jugador << "          !!! ** " << endl;
            //cout << endl;
            //cout << endl;
            rlutil::locate(posicionC,26);
            cout << " ********************************************        " << endl;
            //cout << endl;
            rlutil::locate(posicionC,27);
            cout <<"    "<< jugador << " #GANASTE! #     FELICITACIONES!!!" << endl;
            //cout << endl;
            rlutil::locate(posicionC,28);
            cout << " ********************************************        " << endl;
            cout << endl;
        }
        else
        {
            rlutil::setColor(rlutil::YELLOW);
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
            //cout << endl;
            //cout << endl;
            rlutil::locate(posicionC,25);
            cout << "               ** " <<  jugador << "          !!! ** " << endl;
            //cout << endl;
            //cout << endl;
            rlutil::locate(posicionC,26);
            cout << " ********************************************        " << endl;
            //cout << endl;
            rlutil::locate(posicionC,27);
            cout <<"    "<< jugador << " #GANASTE! #     FELICITACIONES!!!" << endl;
            //cout << endl;
            rlutil::locate(posicionC,28);
            cout << " ********************************************        " << endl;
            cout << endl;
        }

        cout << endl;

        //imprimirPatronAlternadoColor(20,35);
        rlutil::msleep(200);
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);

}

 main

void mostrarMsjFinalJuegoColor()
{
    int posicionC=80;
    int posicionF=20;

    for(int x=0; x<20; x++)
    {
        if(x%2==0)
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
            rlutil::setBackgroundColor(rlutil::YELLOW);
            rlutil::locate(posicionC,posicionF);

            cout << endl;
            rlutil::locate(posicionC,21);
            cout << "                *    *    *                  " << endl;
            cout << endl;
            rlutil::locate(posicionC,22);
            cout << "           EL JUEGO HA FINALIZADO            "<<endl;
            cout << endl;
            rlutil::locate(posicionC,23);
            cout << "                *    *    *                  " << endl;
            cout << endl;
            rlutil::locate(posicionC,24);
            cout << "            GRACIAS POR JUGAR!!!             " << endl;
            cout << endl;
            rlutil::locate(posicionC,25);
            cout << "                *    *    *                  " << endl;
            cout << endl;
            rlutil::msleep(100);

        }
        else
        {
            rlutil::setColor(rlutil::YELLOW);
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
            rlutil::locate(posicionC,posicionF);

            cout << endl;
            rlutil::locate(posicionC,21);
            cout << "                *    *    *                  " << endl;
            cout << endl;
            rlutil::locate(posicionC,22);
            cout << "           EL JUEGO HA FINALIZADO            "<<endl;
            cout << endl;
            rlutil::locate(posicionC,23);
            cout << "                *    *    *                  " << endl;
            cout << endl;
            rlutil::locate(posicionC,24);
            cout << "            GRACIAS POR JUGAR!!!             " << endl;
            cout << endl;
            rlutil::locate(posicionC,25);
            cout << "                *    *    *                  " << endl;
            cout << endl;
            rlutil::msleep(100);
        }


    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
}
void imprimirPatronAlternadoColor(int posicionC,int posicionF)
{

    int fila=20;
    int columna=70;

    for(int x=0; x<10; x++)
    {
        if(x%2==0)
        {

            rlutil::setColor(rlutil::LIGHTBLUE);
            rlutil::setBackgroundColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::YELLOW);
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);

            rlutil::setColor(rlutil::BLACK);
            rlutil::setBackgroundColor(rlutil::BLACK);
        }
        else
        {
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::BLACK);
main
        }

        rlutil::locate(posicionC,posicionF);
        for (int i = 0; i < fila; i++)
        {

            for (int j = 0; j < columna; j++)
            {
                // Condición para alternar espacios y asteriscos
                if ((i + j) % 2 == 0)
                {

                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        rlutil::msleep(10);
    }
}

void mostrarMsjCambioJugadorColor(string jugador)
{
    int posicionC=5;
    int posicionF=2;
    for(int x=0; x<20; x++)
    {
        if(x%2==0)
        {
            rlutil::setColor(rlutil::YELLOW);
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
            rlutil::setBackgroundColor(rlutil::YELLOW);
        }

        cout << endl;
        rlutil::locate(posicionC,posicionF);
        cout << "            *   *   *                   "<<endl;
        cout << endl;
        rlutil::locate(posicionC,3);
        cout << "   -------------------------------------" << endl;
        rlutil::locate(posicionC,4);
        cout << "       ES EL TURNO DE " << jugador << " !       " << endl;
        cout << endl;
        rlutil::locate(posicionC,5);
        cout << "           BUENA SUERTE!                "<< endl;
        rlutil::locate(posicionC,6);
        cout << "   -------------------------------------" << endl;
        cout << endl;

 
        rlutil::msleep(150);
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::cls();


        rlutil::msleep(50);
    }
}

void mostrarResumenPuntajeColor(int puntaje, int ronda, int aP[])
{
    int f =  34;
    int c = 3;

    sonidoPuntaje();
    for (int i = 0; i < 15; i++)
    {

        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }

        // Muestra el cuadro de puntaje

        rlutil::locate(c, f);
        cout << "   ****************************" << endl;
        rlutil::locate(c, f + 1);
        cout << "   ** Puntos Tirada : " << puntaje << " pts **" << endl;
        rlutil::locate(c, f + 2);
        cout << "   **                        **" << endl;
        rlutil::locate(c, f + 3);
        cout << "   **                        **" << endl;
        rlutil::locate(c, f + 4);
        cout << "   **  Puntos Ronda : " << aP[ronda] << " pts **" << endl;
        rlutil::locate(c, f + 5);
        cout << "   ****************************" << endl;
        cout << endl;


        rlutil::msleep(100);
    }


    rlutil::resetColor();
}

void mostrarMsjSumaCeroColor()
{
    cout << endl;
    cout << endl;
    for (int i = 0; i < 15; i++)
    {

        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }
        Beep(880, 150);
        Sleep(100);
        cout << "|:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(|" << endl;
        cout << "Todos tus dados fueron bloqueados!! Sumas : 0pts." << endl;
        cout << "|:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(|" << endl;
        cout << endl;
        cout << endl;
        Sleep(150);
    }
    rlutil::resetColor();

}


int mostrarMenuColor()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    for (int i = 0; i < 15; i++)
    {

        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }
        rlutil::locate(5,7);
        cout << "   ****************************" << endl;
        rlutil::locate(5,8);
        cout << "   **      Menu Principal    **" << endl;
        rlutil::locate(5,9);
        cout << "   **                        **" << endl;
        rlutil::locate(5,10);
        cout << "   **                        **" << endl;
        rlutil::locate(5,11);
        cout << "   **       Bienvenido       **" << endl;
        rlutil::locate(5,312);
        cout << "   ****************************" << endl;
        Sleep(150);

    }


    cout << endl;
    rlutil::resetColor();
    int selection = 0;
    cout << " Por favor elije una de las siguientes opciones : \n";
    cout << "       1. Modo un jugador.\n";
    cout << "       2. Modo dos jugadores.\n";
    cout << "       3. Estadisticas.\n";
    cout << "       4. Creditos.\n";
    cout << "       5. Salir  .\n";
    cout << "\t";
    cin >> selection;
    rlutil::hidecursor();

    return selection;
}

void mostrarRondaColor(int ronda)
{
    int nroRonda = ronda + 1;
    cout << endl;
    for (int i = 0; i < 15; i++)
    {
         if (i == 1 || i == 10){
        sonidoRonda();
        }
        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }
        rlutil::locate(7,2);
        cout << "       ********************"<< endl;
        rlutil::locate(7,3);
        cout << "       ** Ronda Nro : " << nroRonda << "  **" <<endl;
        Sleep(50);
    }
}

void mostrarNroTiradaColor(int cDtiradas, int ronda)
{

    for (int i = 0; i < 15; i++)
    {
        if (i == 1){
        sonidoRonda();
        }
        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }
        rlutil::locate(7,2);
        cout << "       ********************"<< endl;
        rlutil::locate(7,3);
        cout << "       ** Ronda Nro : " << ronda + 1 << "  **" <<endl;
        rlutil::locate(7,4);
        cout << "       **                **" << endl;
        rlutil::locate(7,5);
        cout << "       ** Tirada Nro : " <<  cDtiradas << " **" <<endl;
        rlutil::locate(7,6);
        cout << "       ********************" << endl;
        cout << endl;
        Sleep(50);
    }
}

void mostrarNroTiradasMasUnoColor(int cDtiradas, int ronda)
{
     for (int i = 0; i < 15; i++)
    {

        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }
        rlutil::locate(7,2);
        cout << "       ********************"<< endl;
        rlutil::locate(7,3);
        cout << "       ** Ronda Nro : " << ronda + 1 << "  **" <<endl;
        rlutil::locate(7,4);
        cout << "       **                **" << endl;
        rlutil::locate(7,5);
        cout << "       ** Tirada Nro : " <<  cDtiradas+1 << " **" <<endl;
        rlutil::locate(7,6);
        cout << "       ********************" << endl;
        cout << endl;
        Sleep(150);
    }
}

void FelitacionesColor(int puntajeTotal )
{
    for (int i = 0; i < 15; i++)
    {

        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
        }
        rlutil::locate(1,1);
        cout << "Felicitaciones!!! Tu puntaje total para las 3 rondas  fue de : " << puntajeTotal << "!!!" << endl;
        Sleep(150);
        rlutil::resetColor();

    }

}

void mostrarPrimerTurnoColor(string jugador1)
{
    for (int i = 0; i < 15; i++)
    {

        if (i % 2 == 0)
        {
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(5,3);
            cout << "           ==================================="<< endl;
            rlutil::locate(5,4);
            cout << "           ||                               ||"<< endl;
            rlutil::locate(5,5);
            cout << "                  Es el Turno de " << jugador1 <<endl;
            rlutil::locate(5,6);
            cout << endl;
            cout << "           ||           A JUGAR!!           ||"<< endl;
            rlutil::locate(5,7);
            cout << "           ||                               ||"<<endl;
            rlutil::locate(5,8);
            cout << "           ==================================="<< endl;
            cout << endl;
            cout << endl;
            cout << endl;
            rlutil::locate(5,11);
            cout << "           Presiona una tecla para comenzar..." << endl;
            Sleep(300);
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTBLUE);
            rlutil::locate(5,3);
            cout << "           ==================================="<< endl;
            rlutil::locate(5,4);
            cout << "           ||                               ||"<< endl;
            rlutil::locate(5,5);
            cout << "                  Es el Turno de " << jugador1 <<endl;
            rlutil::locate(5,6);
            cout << endl;
            cout << "           ||           A JUGAR!!           ||"<< endl;
            rlutil::locate(5,7);
            cout << "           ||                               ||"<<endl;
            rlutil::locate(5,8);
            cout << "           ==================================="<< endl;
            cout << endl;
            cout << endl;
            cout << endl;
            rlutil::locate(5,11);
            cout << "           Presiona una tecla para comenzar..." << endl;
            Sleep(300);
        }


    }

    Sleep(300);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();
}





