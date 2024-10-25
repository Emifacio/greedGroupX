#include <iostream>
#define FUNCIONES_H
#include <string>
#include "funciones.h"
//#include "ranking.h"
using namespace std;


// Esta función genera los "dados bloqueadores" que son 2 dados aleatorios.
void tiradaBloqueadores(int v[],int t)
{
    t=2;
    int x,dado;
    cout<<"Dados bloqueadores "<<endl;
    cout<<"==================================="<<endl;
    for(x=0; x<2; x++)
    {
        dado=tirarDado();
        v[x]=dado;

    }
}


int tirarDado(){
    return rand() % 6 + 1;
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
        vD[x] = tirarDado(); // Genera un número aleatorio entre 1 y 6 para cada dado
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

// Esta función filtra los dados que coinciden con los bloqueadores y devuelve cuántos dados quedan disponibles.
int dadosNuevos(int vD[], int t, int vB[2])
{
    t;  // `t` es el número de dados (5), `cD` es el contador de dados que quedan
    vD[t] = {};
    int x, cD = 0;
    for(x = 0; x<t; x++) { // Itera sobre los 5 dados
            // Si el dado actual coincide con alguno de los dados bloqueadores, lo elimina (lo convierte en 0)
        if(vD[x] == vB[0] || vD[x] == vB[1]) {
            vD[x] = 0;
        }
    } for(x = 0; x<t; x++) { // Esta segunda iteración filtra los dados que no han sido bloqueados (es decir, los que no son 0)
        if(vD[x] != 0) { // Si el dado no es 0, lo mueve al principio del vector
            vD[cD] = vD[x]; // Reorganiza los dados para eliminar espacios vacíos (0)
            cD++; // Incrementa el contador de dados disponibles
        }
    }
   return cD; // Devuelve cuántos dados no fueron bloqueados
}

// Esta función muestra los dados actuales después de haber sido filtrados.
void mostrarDados(int vD[], int tam)
{
    int x;
    for(x = 0; x<tam; x++)// Muestra los dados disponibles después de filtrar los bloqueados
    {
        cout << "Dado : " << vD[x] << endl;
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





