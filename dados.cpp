#include<iostream>
#include "rlutil.h"
#include "dados.h"
#include <cstdlib>
#include <ctime>
using namespace std;



void dibujarDado(int numero, int columna, int fila)
{
    dibujarCuadrado(columna,fila);
    dibujarPuntos(numero,columna,fila);
    dibujarSombra(columna,fila);

}
///dados color
void dibujarDadoColor(int numero, int columna, int fila, int color, int colorPoint)
{
    rlutil::setColor(color);
    dibujarCuadradoColor(columna,fila);
    rlutil::setColor(colorPoint);
    rlutil::setBackgroundColor(color);
    dibujarPuntosColor(numero,columna,fila);
    rlutil::setColor(rlutil::GREY);
    rlutil::setBackgroundColor(rlutil::BLACK);
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
        if(rand()%2){
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        }else
        {
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;

        }
        break;
    case 3:
        if(rand()%2){
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        }else{
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        }
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
        if(rand()%2){
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
        }else{
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+1,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+5,fila+1);
        cout<< (char) 254;
        }
        break;

    }

}

void dibujarPuntosColor(int numero, int columna, int fila){
    switch(numero)
    {
    case 1:
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        break;
    case 2:
        if(rand()%2){
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        }else
        {
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;

        }
        break;
    case 3:
        if(rand()%2){
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        }else{
        rlutil::locate(columna+3,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        }
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
        if(rand()%2){
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
        }else{
        rlutil::locate(columna+1,fila);
        cout<< (char) 220;
        rlutil::locate(columna+5,fila);
        cout<< (char) 220;
        rlutil::locate(columna+1,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+5,fila+2);
        cout<< (char) 223;
        rlutil::locate(columna+1,fila+1);
        cout<< (char) 254;
        rlutil::locate(columna+5,fila+1);
        cout<< (char) 254;
        }
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

void dibujarCuadradoColor(int columna, int fila)
{
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

 void dibujarBloqueadores(int vD[])
{

    dibujarDadoColor(vD[0],80,8,12,15);
    dibujarDadoColor(vD[1],90,9,12,15);
}
