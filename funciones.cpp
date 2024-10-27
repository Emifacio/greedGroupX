#include <iostream>
#include "rlutil.h"
#define FUNCIONES_H
#include <string>
#include "funciones.h"
//#include "ranking.h"
using namespace std;

void pedirNombre(string jugador1, string jugador2){
cout   << "Jugador 1, Ingrese su nombre:  /n"<< endl;
cin >> jugador1;
cout   << "Jugador 2, Ingrese su nombre:  /n"<< endl;
cin >> jugador2;
}


void acumularPuntaje(puntajeJ1, puntajeJ2, puntajeRonda[]){

for (puntajeRonda = 0 ;  puntajeRonda < 3 ; i++ ){
    puntajeJ1++
    puntajeJ2++
    }
}



void mostrarCartelGreed() {
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




procesarSeleccion(int selection) {
    switch (selection) {
        case 1:
            cout << "Has seleccionado la opci�n 1 (Modo un jugador)" << endl;
            //juegaModo1Jugador();
            break;
        case 2:
            cout << "Has seleccionado la opci�n 2 (Modo dos jugadores)" << endl;
            break;
            // JuegaModo2Jugadores();
        case 3:
            cout << "Has seleccionado la opci�n 3 (Estad�sticas)" << endl;
            break;
            // mostrarEstadisticas();
        case 4:
            cout << "Has seleccionado la opci�n 4 (Cr�ditos)" << endl;

void procesarSeleccion(int selection) {
    switch (selection) {
        case 1:
            cout << "Has seleccionado la opci�n 1 (Modo un jugador)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //juegaModo1Jugador();
            break;
        case 2:
            cout << "Has seleccionado la opci�n 2 (Modo dos jugadores)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //JuegaModo2Jugadores();
            break;
        case 3:
            cout << "Has seleccionado la opci�n 3 (Estad�sticas)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            break;
            // mostrarEstadisticas();
        case 4:
            cout << "Has seleccionado la opci�n 4 (Cr�ditos)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;

            break;
            // mostrarCreditos();
        case 5:
            cout << "Gracias por jugar GreedX, espero verte pronto nuevamente!" << endl;
           // mostrarRecord();
            break;
        default:

            cout << "Opci�n no v�lida" << endl;

            cout << "Opci�n no v�lida" << endl;

            break;
    }
}




// Esta funci�n genera los "dados bloqueadores" que son 2 dados aleatorios.
void tiradaBloqueadores(int v[], int t)

void JuegaModo2Jugadores(string &jugador1,
    string &jugador2,
    int &ronda,
    int aP[3],
    int aP2[3],
    int &aPt,
    int &aPt2,
    bool &duplicar,
    char &pregunta){

    }



// Esta funci�n genera los "dados bloqueadores" que son 2 dados aleatorios.

// Esta funci�n genera los "dados bloqueadores" que son 2 dados aleatorios.

void tiradaBloqueadores(int v[],int t)

{
    t=2;
    int x,dado;
    cout<<"Dados bloqueadores "<<endl;
    cout<<"==================================="<<endl;
    for(x=0; x<2; x++)
    {


        dado = (rand() % 6 + 1); // Genera un n�mero aleatorio entre 1 y 6
        v[x] = dado; // Guarda el dado generado en el vector `v`
        cout << "Dado " << x + 1 << " = " << v[x] << endl; // Muestra el valor de cada dado bloqueador

        dado=(rand()%6+1);

        dado=tirarDado();

        v[x]=dado;



    }
}


int tirarDado(){
    return rand() % 6 + 1;
}



// Esta funci�n genera los 5 dados que va a tirar el jugador.
void tiradaDeDados(int vD[], int tam)
{
    tam = 5; // Define que el jugador lanza 5 dados
    int x;
    cout << "Tirada de Dados " << endl;
    cout << "===================================" << endl;
    for (x = 0; x < tam; x++) // Itera cinco veces para generar cinco dados
    {


        vD[x] = (rand() % 6 + 1); // Genera un n�mero aleatorio entre 1 y 6 para cada dado
        cout << "Dado " << x + 1 << " = " << vD[x] << endl; // Muestra el valor de cada dado
    }
}

///Funcion para saber si los dados son iguales
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

// Esta funci�n filtra los dados que coinciden con los bloqueadores y devuelve cu�ntos dados quedan disponibles.

        vD[x] = (rand() % 6 + 1); // Genera un n�mero aleatorio entre 1 y 6 para cada dado

        vD[x] = tirarDado(); // Genera un n�mero aleatorio entre 1 y 6 para cada dado

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

// Esta funci�n filtra los dados que coinciden con los bloqueadores y devuelve cu�ntos dados quedan disponibles.
int dadosNuevos(int vD[], int t, int vB[2])
{
    t;  // `t` es el n�mero de dados (5), `cD` es el contador de dados que quedan
    vD[t] = {};
    int x, cD = 0;
    for(x = 0; x<t; x++) { // Itera sobre los 5 dados
            // Si el dado actual coincide con alguno de los dados bloqueadores, lo elimina (lo convierte en 0)
        if(vD[x] == vB[0] || vD[x] == vB[1]) {
            vD[x] = 0;
        }
    } for(x = 0; x<t; x++) { // Esta segunda iteraci�n filtra los dados que no han sido bloqueados (es decir, los que no son 0)
        if(vD[x] != 0) { // Si el dado no es 0, lo mueve al principio del vector
            vD[cD] = vD[x]; // Reorganiza los dados para eliminar espacios vac�os (0)
            cD++; // Incrementa el contador de dados disponibles
        }
    }
   return cD; // Devuelve cu�ntos dados no fueron bloqueados
}


// Esta funci�n muestra los dados actuales despu�s de haber sido filtrados.
void mostrarDados(int vD[], int tam)
{
    int x;
    for(x = 0; x<tam; x++)// Muestra los dados disponibles despu�s de filtrar los bloqueados
    {

// Esta funci�n muestra los dados actuales despu�s de haber sido filtrados.
void mostrarDados(int vD[], int tam){
    int x;
    // Muestra los dados disponibles despu�s de filtrar los bloqueados
    for(x = 0; x<tam; x++){

        cout << "Dado : " << vD[x] << endl;
    }
     cout << endl;
}

int sumarDados(int vD[], int t){
    int x, aP = 0; // `aP` acumula los puntos

     // Itera sobre los dados no bloqueados
    for (x = 0; x < t; x++){
        aP += vD[x]; // Suma el valor de cada dado
    }
    return aP; // Devuelve la suma total de los puntos
}

///tiradaDeDadosDibujo
void dibujarDado(int numero, int columna, int fila)
{
    dibujarCuadrado(columna,fila);
    dibujarPuntos(numero,columna,fila);
    dibujarSombra(columna,fila);

}
void dibujarPuntos(int numero, int columna, int fila){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    switch(numero)
    {
    case 1:
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        break;
    case 2:
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        break;
    case 3:
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        break;
    case 4:
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        break;
    case 5:
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        break;
    case 6:
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+3,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+3,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        break;

    }

}

void dibujarSombra( int columna, int fila){
///sombras
    rlutil::setColor(rlutil::GREY);
    rlutil::setBackgroundColor(rlutil::BLACK);

    for(int y=fila; y<=fila+2; y++)
    {
        rlutil::locate(columna+7,y);
        if(y==fila)
        {
            cout<< (char) 220;
        }
        else
        {
            cout<< (char) 219;
        }

    }

    for(int x=columna+1; x<=columna+7; x++)
    {
        rlutil::locate(x,fila+3);
        cout<< (char) 223;
    }


}


void dibujarCuadrado(int columna, int fila)
{
    rlutil::setColor(rlutil::WHITE);
    for(int x=columna; x<=columna+6; x++)
    {
        for(int y=fila; y<=fila+2; y++)
        {
            rlutil::locate(x,y);
            cout<< (char) 219;

        }
    }
}


int tirarDado(int columna, int fila){
int dado=rand()%6+1;

for(int x=0;x<20;x++){
    dibujarDado(rand()%6+1,columna,fila);
    rlutil::msleep(10);
}
dibujarDado(dado,columna,fila);


return dado;
}



/*
// Esta funci�n filtra los dados que coinciden con los bloqueadores y devuelve cu�ntos dados quedan disponibles.

int dadosNuevos(int vD[5], int vB[2])
{
    int x, t = 5, cD = 0; // `t` es el n�mero de dados (5), `cD` es el contador de dados que quedan
    for (x = 0; x < t; x++) // Itera sobre los 5 dados
    {
        // Si el dado actual coincide con alguno de los dados bloqueadores, lo elimina (lo convierte en 0)
        if (vD[x] == vB[0] || vD[x] == vB[1])
        {
            vD[x] = 0;
        }
    }
     // Esta segunda iteraci�n filtra los dados que no han sido bloqueados (es decir, los que no son 0)
    for (x = 0; x < t; x++)
    {
        if (vD[x] != 0) // Si el dado no es 0, lo mueve al principio del vector
        {
            vD[cD] = vD[x]; // Reorganiza los dados para eliminar espacios vac�os (0)
            cD++; // Incrementa el contador de dados disponibles
        }
    }
    return cD; // Devuelve cu�ntos dados no fueron bloqueados
}



// Esta funci�n muestra los dados actuales despu�s de haber sido filtrados.
void mostrarDados(int vD[], int nT)
{
    int x;
    for (x = 0; x < nT; x++) // Muestra los dados disponibles despu�s de filtrar los bloqueados
    {
        cout << "Dado " << vD[x] << " - ";
    }
}
*/


// Esta funci�n suma los valores de los dados que no han sido bloqueados. Es decir, suma CADA TIRADA.


// Esta funci�n suma los valores de los dados que no han sido bloqueados. Es decir, suma CADA TIRADA.
int sumarDados(int vD[], int t)
{
    int x, aP = 0; // `aP` acumula los puntos
    for (x = 0; x < t; x++) // Itera sobre los dados no bloqueados
    {
        aP += vD[x]; // Suma el valor de cada dado
    }
    return aP; // Devuelve la suma total de los puntos
}










