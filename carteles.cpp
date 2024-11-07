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

void sonidoEleccion(){
Beep(1175, 50); Sleep(4);
Beep(1046, 50); Sleep(3);
}


void sonidoRonda(){
                     Beep(1568, 100); Sleep(8);
					 Beep(1175, 50); Sleep(4);
					 Beep(1046, 50); Sleep(3);
					 Beep(988, 60); Sleep(2);
					 Beep(880, 150); Sleep(11);
					 }

void mostrarmostrarGreed() {
int c = 15;
int f = 12;
    for(int x=0; x<2; x++)
    {
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

        cout<< endl;
        rlutil::locate(c,f);
        cout << "  GGGGG    RRRRR    EEEEE   EEEEE   DDDDD  \n";
        Beep(1568, 100); Sleep(8);
        rlutil::locate(c,f+1);
        cout << " G        R    R   E       E       D    D  \n";
        Beep(1175, 50); Sleep(4);
        rlutil::locate(c,f+2);
        cout << " G  GGG   RRRRR    EEEE    EEEE    D    D  \n";
        Beep(1046, 50); Sleep(3);
        rlutil::locate(c,f+3);
        cout << " G    G   R  R     E       E       D    D  \n";
        Beep(988, 60); Sleep(2);
        rlutil::locate(c,f+4);
        cout << "  GGGGG   R   R    EEEEE   EEEEE   DDDDD   \n";
        Beep(880, 150); Sleep(20);
        cout << endl;
        rlutil::msleep(37);
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

}

void pedirNombre(string& jugador1, string& jugador2){
  rlutil::locate(20,10);
cout   << " Ingresar nombre del jugador nro1 :  "<< endl;
rlutil::locate(20,11);
cin >> jugador1;
rlutil::locate(20,12);
cout   << " Ingresar nombre del jugador nro2 :  "<< endl;
rlutil::locate(20,13);
cin >> jugador2;
}

 int mostrarMenu(){
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

void procesarSelection(int selection){

 switch (selection) {
        case 1:
            sonidoEleccion();
            mostrarBarraDivisoraLarga();
            cout << "Has seleccionado la opcion 1 (Modo un jugador)" << endl;
            mostrarBarraDivisoraLarga();
            rlutil::msleep(1000);
            rlutil::cls();
            modoUnJugador();
            break;
        case 2:
            sonidoEleccion();
            mostrarBarraDivisoraLarga();
            cout << "Has seleccionado la opcion 2 (Modo dos jugadores)" << endl;
            mostrarBarraDivisoraLarga();
            rlutil::msleep(1000);
            rlutil::cls();
            modoDosJugadores();
            break;
        case 3:
            sonidoEleccion();
            mostrarBarraDivisoraLarga();
            cout << "Has seleccionado la opcion 3 (Estadísticas)" << endl;
            mostrarBarraDivisoraLarga();
            rlutil::msleep(1000);
            rlutil::cls();
            menuEstadisticas();
            break;
        case 4:
            sonidoEleccion();
            mostrarBarraDivisoraLarga();
            cout << "Has seleccionado la opcion 4 (Créditos)" << endl;
            mostrarBarraDivisoraLarga();
            ///Créditos: Deberá mostrar el nombre del equipo (inventar uno)
            //junto con sus respectivos legajos, apellidos y nombres.
            // mostrarCreditos();
            break;
        case 5:
            sonidoEleccion();
            mostrarBarraDivisoraLarga();
            cout << "Gracias por jugar GreedX, espero verte pronto nuevamente!" << endl;
            mostrarBarraDivisoraLarga();
            break;
        default:
            mostrarBarraDivisoraLarga();
            cout << "Opcion no valida" << endl;
            mostrarBarraDivisoraLarga();
            break;

}
}

void mostrarPrimerTurno(string jugador1){
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

void mostrarTituloDadosBloqueadores(){
                    cout << endl;
                    cout << "Dados bloqueadores:" << endl;
                    cout << "==================================="<<endl;
                    }

void mostrarRonda(int ronda){
        cout << endl;
        cout << "       ********************"<< endl;
        cout << "       ** Ronda Nro : " << ronda + 1 << "  **" <<endl;
}

void mostrarNroTirada(int cDtiradas) {
        cout <<"       **                **" << endl;
        cout << "       ** Tirada Nro : " <<  cDtiradas << " **" <<endl;
        cout << "       ********************" << endl;
        cout << endl;
}

void mostrarNroTiradasMasUno(int cDtiradas){
        cout <<"       **                **" << endl;
        cout << "       ** Tirada Nro : " <<  cDtiradas+1 << " **" <<endl;
        cout << "       ********************" << endl;
        cout << endl;
}

void mostrarTituloTiradaDados(){

    cout << endl;
    cout << "===================================" << endl;
    cout << "Tirada de Dados " << endl;
    cout << "===================================" << endl;

}


void mostrarEspacioPDados(){
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

void mostrarTituloDadosQSuman(){
    cout << endl;
    cout << "==================================="<< endl;
    cout << "Dados que suman : " << endl;
    cout << "==================================="<< endl;
    cout << endl;
}

void mostrarDuplicaONo(bool duplicar){
    if(duplicar == true){
        cout << endl;
        cout << "*Duplica puntos: Los dados son iguales." << endl;
        cout << "**Siguiente tirada automatica." << endl;
        cout << "Presione una tecla para continuar." << endl;
        rlutil::anykey();
            }else{
                cout << endl;
                cout << "*No duplica: Uno o mas dados distintos." << endl;
                    }
         cout << endl;
         }

void mostrarResumenPuntaje(int puntaje, int ronda, int aP[]) {
    cout << "   ****************************" << endl;
    cout << "   ** Puntos Tirada : " << puntaje << " pts **" << endl;
    cout << "   **                        **" << endl;
    cout << "   **                        **" << endl;
    cout << "   **  Puntos Ronda : " << aP[ronda] << " pts **" << endl;
    cout << "   ****************************" << endl;
    cout << endl;
}

char preguntaContinuarTirando(char pregunta){
    cout << " ¿Deseas continuar tirando (S/N)?" << endl;
    cin >> pregunta;
    cout << endl;

    return pregunta;
    }



void mostrarPuntajeTirada(int puntaje){
    cout << " **************************" << endl;
    cout << " ** Puntos Tirada : " << puntaje << " pts **" << endl;
    cout << " **                       **" << endl;

}

void mostrarPuntajeRonda(int ronda, int aP[]){
    cout << " **                       **" << endl;
    cout << " **  Puntos Ronda : " << aP[ronda] << " pts**" << endl;
    cout << " ***************************" << endl;
    cout << endl;
    }

void mostrarMsjCambioJugador(string jugador){

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
                rlutil::msleep(1750);
                rlutil::cls();
                }

void mostrarMsjSumaCero(){
                    cout << endl;
                    cout << endl;
                     Beep(880, 150); Sleep(200);
                    cout << "|:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(|" << endl;
                    cout << "Todos tus dados fueron bloqueados!! Sumas : 0pts." << endl;
                    cout << "|:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(||:(|" << endl;
                    cout << endl;
                    cout << endl;

                }

void mostrarMsjFinRondas(string jugador, int ronda, int aP[]){
    cout <<"* "<< "En la ronda " << ronda+1 <<" "<< jugador << " consiguio : "<< aP[ronda] <<"pts." <<endl;
    cout << endl;
    cout << endl;
    cout << "                *    *    *" << endl;
}


void mostrarTotalPtsAmbosJugadores(string jugador1, string jugador2,int acumuladoPuntajeTotalJugador1,int acumuladoPuntajeTotalJugador2){
    cout << endl;
    cout << "        === Resultados Finales ===" << endl;
    cout << "            *******************" << endl;
    cout << endl;
    cout << "       Puntaje total de " << jugador1 << " : " << acumuladoPuntajeTotalJugador1 << "pts" << endl;
    cout << endl;
    cout << "       Puntaje total de " << jugador2 << " : " << acumuladoPuntajeTotalJugador2 << "pts" << endl;
    cout << endl;
    }

void imprimirPatronAlternado(int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            // Condición para alternar espacios y asteriscos
            if ((i + j) % 2 == 0) {
                cout << " *";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void mostrarGanador(string jugador){
        cout << endl;
        cout << "EL JUGADOR QUE CONSIGUIO EL MEJOR PUNTAJE FUE : ..." << endl;
        cout << endl;
        rlutil::msleep(3000);
        imprimirPatronAlternado(26);
        rlutil::msleep(3000);
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

void mostrarMsjFinalJuego(){
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


void mostrarBarraDivisora(){
    cout << endl;
    cout << "==================================="<< endl;

    cout << endl;
}

void mostrarBarraDivisoraLarga(){
    cout << endl;
    cout << "======================================================================"<< endl;

    cout << endl;
}


