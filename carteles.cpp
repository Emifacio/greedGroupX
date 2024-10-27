/// Funciones de mostrares para mostrar durante el programa.
#include <iostream>
#define FUNCIONES_H
#include <string>
#include "funciones.h"
#include "ranking.h"
using namespace std;
//#include "ranking.h"


void mostrarmostrarGreed() {
    cout<< endl;
    cout << "  GGGGG    RRRRR    EEEEE   EEEEE   DDDDD   \n";
    cout << " G        R    R   E       E       D    D  \n";
    cout << " G  GGG   RRRRR    EEEE    EEEE    D    D  \n";
    cout << " G    G   R  R     E       E       D    D  \n";
    cout << "  GGGGG   R   R    EEEEE   EEEEE   DDDDD   \n";
    cout << endl;
}


void pedirNombre(string &jugador1, string &jugador2){
cout   << "Ingresar nombre del jugador nro1 :  "<< endl;
cin >> jugador1;
cout   << "Ingresar nombre del jugador nro2 :  "<< endl;
cin >> jugador2;
}


int mostrarMenu() {

    cout << "Bienvenido al menu principal" << endl;
    cout << endl;
    int selection = 0;
        cout << " Por favor elija una de las siguientes opciones - \n";
        cout << " 1. Modo un jugador.\n";
        cout << " 2. Modo dos jugadores.\n";
        cout << " 3. Estadisticas.\n";
        cout << " 4. Creditos.\n";
        cout << " 5. Salir  .\n";
        cout << "\t";
        cin >> selection;

        return selection;
}



void procesarSeleccion(int selection) {
    switch (selection) {
        case 1:
            cout << "Has seleccionado la opcion 1 (Modo un jugador)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //juegaModo1Jugador();
            break;
        case 2:
            cout << "Has seleccionado la opcion 2 (Modo dos jugadores)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //JuegaModo2Jugadores();
            break;
        case 3:
            cout << "Has seleccionado la opcion 3 (Estadísticas)" << endl;
            /*Estadísticas: Deberá mostrar, si existe, el nombre
            y el puntaje del jugador que haya obtenido el puntaje más alto.
            Tener en cuenta que al cerrar la aplicación el puntaje se restablecerá.*/
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
                   //mostrarRanking();
            break;
        case 4:
            cout << "Has seleccionado la opcion 4 (Créditos)" << endl;
            /*Créditos: Deberá mostrar el nombre del equipo (inventar uno)
            junto con sus respectivos legajos, apellidos y nombres.*/
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            // mostrarCreditos();
            break;
        case 5:
            cout << "Gracias por jugar GreedX, espero verte pronto nuevamente!" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}


void mostrarPrimerTurno(string jugador1){
    cout << endl;
    cout << "    Es el Turno de " << jugador1 <<"." <<endl;
    cout << endl;
    cout << "           A JUGAR!!"<< endl;
    cout << endl;
    cout << "==================================="<< "\n\n";
}

void mostrarTituloDadosBloqueadores(){
                    cout << "==================================="<<endl;
                    cout << "Dados bloqueadores:" << endl;
                    cout << "==================================="<<endl;
                    }

void mostrarRonda(int ronda){
        cout << "       *******************"<< endl;
        cout << "       ** Ronda Nro : " << ronda + 1 << " **" <<endl;
        cout << "       *******************" << "\n\n";

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
            }else{
                cout << endl;
                cout << "*No duplica: Uno o mas dados distintos." << endl;
                    }
         cout << endl;
         }

void mostrarResumenPuntaje(int puntaje, int ronda, int aP[]) {
    cout << "   **************************" << endl;
    cout << "   ** Puntos Tirada : " << puntaje << " pts **" << endl;
    cout << "   **************************" << endl;
    cout << endl;
    cout << "   **************************" << endl;
    cout << "   **  Puntos Ronda : " << aP[ronda] << " pts **" << endl;
    cout << "   **************************" << endl;
    cout << endl;
}

char preguntaContinuarTirando(char pregunta){
    cout << "Desea continuar tirando (S para seguir o N para sumar los puntos acumulados): " << endl;
    cin >> pregunta;
    cout << endl;

    return pregunta;
    }

void mostrarNroTirada(int cDtiradas) {
    cout << "Tirada Nro : " << cDtiradas << "\n\n";
}

void mostrarPuntajeTirada(int puntaje){
    cout << " ****************************" << endl;
    cout << "** Puntos Tirada : " << puntaje << " pts **" << endl;
    cout << " ****************************" << endl;
    cout << endl;
}

void mostrarPuntajeRonda(int ronda, int aP[]){
    cout << " *****************************" << endl;
    cout << "**  Puntos Ronda : " << aP[ronda] << " pts **" << endl;
    cout << " *****************************" << endl;
    cout << endl;
    }

void mostrarMsjCambioJugador(string jugador){
                cout << endl;
                cout << "           *   *   *                   "<<endl;
                cout << endl;
                cout << "   -----------------------------" << endl;
                cout << "       ES EL TURNO DE " << jugador << "!" << endl;
                cout << endl;
                cout << "           BUENA SUERTE!"<< endl;
                cout << "   -----------------------------" << endl;
                cout << endl;
                }

void mostrarMsjSumaCero(){
                    cout << "Todos tus dados fueron bloqueados!! Sumas : 0pts." << endl;
                }

void mostrarMsjFinRondas(string jugador, int ronda, int aP[]){
    cout <<"* "<< "En la ronda " << ronda+1 <<" "<< jugador << " consiguio : "<< aP[ronda] <<"pts." <<endl;
    cout << endl;
    cout << endl;
    cout << "                *    *    *" << endl;
}


void mostrarTotalPtsAmbosJugadores(string jugador1, string jugador2,int acumuladoPuntajeTotalJugador1,int acumuladoPuntajeTotalJugador2){
    cout << endl;
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
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void mostrarGanador(string jugador){
        cout << endl;
        cout << "EL JUGADOR QUE CONSIGUIO EL MEJOR PUNTAJE FUE : ..." << endl;
        cout << endl;
        imprimirPatronAlternado(53);
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
   }
