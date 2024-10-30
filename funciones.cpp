#include <iostream>
#include "rlutil.h"
#define FUNCIONES_H
#include <string>
#include "funciones.h"
//#include "ranking.h"
using namespace std;



// Esta funci�n genera los "dados bloqueadores" que son 2 dados aleatorios.
void tiradaBloqueadores(int v[], int t){
    t=2;
    int x, dado;
    cout << "==================================="<<endl;
    cout << "Dados bloqueadores " << endl;
    cout << "==================================="<<endl;
    for(x=0; x<2; x++){
        dado = tirarDado(); // Genera un n�mero aleatorio entre 1 y 6
        v[x] = dado; // Guarda el dado generado en el vector `v`
        cout << "Dado " << x + 1 << " = " << v[x] << endl; // Muestra el valor de cada dado bloqueador
        }
    }

int tirarDado(){
    return rand() % 6 + 1;
}


// Esta funci�n genera los 5 dados que va a tirar el jugador.
void tiradaDeDados(int vD[], int tam){
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

        cout << "Dado : " << vD[x] << endl;
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


void dibujarCuadrado(int columna, int fila){
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
int tirarDadoRlutil(int columna, int fila){
int dado=tirarDado();

for(int x=0;x<20;x++){
    dibujarDado(rand()%6+1,columna,fila);
    rlutil::msleep(10);
}
dibujarDado(dado,columna,fila);


return dado;
}










