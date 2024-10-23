#include <iostream>

#define FUNCIONES_H

#include <string>
#include "funciones.h"
using namespace std;


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



void procesarSeleccion(int selection) {
    switch (selection) {
        case 1:
            cout << "Has seleccionado la opción 1 (Modo un jugador)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //juegaModo1Jugador();
            break;
        case 2:
            cout << "Has seleccionado la opción 2 (Modo dos jugadores)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            //JuegaModo2Jugadores();
            break;
        case 3:
            cout << "Has seleccionado la opción 3 (Estadísticas)" << endl;
            cout << endl;
            cout << "==================================="<< endl;
            cout << endl;
            break;
            // mostrarEstadisticas();
        case 4:
            cout << "Has seleccionado la opción 4 (Créditos)" << endl;
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
            cout << "Opción no válida" << endl;
            break;
    }
}

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



// Esta función genera los "dados bloqueadores" que son 2 dados aleatorios.
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



// Esta función genera los 5 dados que va a tirar el jugador.
void tiradaDeDados(int vD[], int tam)
{
    tam = 5; // Define que el jugador lanza 5 dados
    int x;
    cout << "Tirada de Dados " << endl;
    cout << "===================================" << endl;
    for (x = 0; x < tam; x++) // Itera cinco veces para generar cinco dados
    {
        vD[x] = (rand() % 6 + 1); // Genera un número aleatorio entre 1 y 6 para cada dado
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
int dadosNuevos(int vD[], int t, int vB[2])
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


void mostrarDados(int vD[], int tam)
{
    int x;
    for(x=0; x<tam; x++)
    {
        cout<< "Dado : " << vD[x] << endl;
    }
}

int sumarDados(int vD[], int t)
{
    int x, aP = 0; // `aP` acumula los puntos
    for (x = 0; x < t; x++) // Itera sobre los dados no bloqueados
    {
        aP += vD[x]; // Suma el valor de cada dado
    }
    return aP; // Devuelve la suma total de los puntos
}


/*
// Esta función filtra los dados que coinciden con los bloqueadores y devuelve cuántos dados quedan disponibles.
int dadosNuevos(int vD[5], int vB[2])
{
    int x, t = 5, cD = 0; // `t` es el número de dados (5), `cD` es el contador de dados que quedan
    for (x = 0; x < t; x++) // Itera sobre los 5 dados
    {
        // Si el dado actual coincide con alguno de los dados bloqueadores, lo elimina (lo convierte en 0)
        if (vD[x] == vB[0] || vD[x] == vB[1])
        {
            vD[x] = 0;
        }
    }
     // Esta segunda iteración filtra los dados que no han sido bloqueados (es decir, los que no son 0)
    for (x = 0; x < t; x++)
    {
        if (vD[x] != 0) // Si el dado no es 0, lo mueve al principio del vector
        {
            vD[cD] = vD[x]; // Reorganiza los dados para eliminar espacios vacíos (0)
            cD++; // Incrementa el contador de dados disponibles
        }
    }
    return cD; // Devuelve cuántos dados no fueron bloqueados
}



// Esta función muestra los dados actuales después de haber sido filtrados.
void mostrarDados(int vD[], int nT)
{
    int x;
    for (x = 0; x < nT; x++) // Muestra los dados disponibles después de filtrar los bloqueados
    {
        cout << "Dado " << vD[x] << " - ";
    }
}
*/


// Esta función suma los valores de los dados que no han sido bloqueados. Es decir, suma CADA TIRADA.


