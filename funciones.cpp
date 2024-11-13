#include <iostream>
#include "rlutil.h"
#define FUNCIONES_H
#include <string>
#include "funciones.h"
//#include "ranking.h"
#include "dados.h"
using namespace std;




    ///funcion tirada bloqueadores
void tiradaBloqueadores(int v[], int t)
{

    int x,c=0,columna=70,fila=11;
    for(x=0; x<t; x++)
    {
        v[x] = tirarDadito();// Guarda el dado generado en el vector v
        //cout << "Dado " << x + 1 << " = " << v[x] << endl; // Muestra el valor de cada dado bloqueador
    }
    for(x=0; x<t; x++)
    {
        dibujarBloqueadores(v);
        columna+=10;
        if(x%2==0)
        {
            fila++;
        }
        else
        {
            fila--;
        }
    }
    rlutil::msleep(1000);

}


int tirarDadito(){
    return rand() % 6 + 1;
}

void tiradaDeDados(int vD[], int tam)
{

    int x,c=0,columna=60,fila=20;

    for (x = 0; x < tam; x++) // Itera cinco veces para generar cinco dados
    {
        vD[x] = (rand() % 6 + 1); // Genera un n�mero aleatorio entre 1 y 6 para cada dado
        /// cout << "Dado " << x + 1 << " = " << vD[x] << endl; // Muestra el valor de cada dado
    }
    for(x=0; x<tam; x++)
    {

        dibujarDado(vD[c++],columna,fila);
        columna+=10;
        if(x%2==0)
        {
            fila++;
        }
        else
        {
            fila--;
        }
    }
    rlutil::msleep(1000);
}



bool dadosIguales(int vD[], int t){
    int x, referencia, c = 0;
    referencia = vD[0];
    for(x=0; x<t; x++){
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
void mostrarDados(int vD[], int tam){
    int x;
    // Muestra los dados disponibles despu�s de filtrar los bloqueados
    for(x = 0; x<tam; x++){

        cout << "Dado = " << vD[x] << endl;
    }

}

int sumarDados(int vD[], int t){
    int x, aP = 0; // `aP` acumula los puntos

     // Itera sobre los dados no bloqueados
    for (x = 0; x < t; x++){
        aP += vD[x]; // Suma el valor de cada dado
    }
    return aP; // Devuelve la suma total de los puntos
}
