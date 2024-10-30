/*#include <iostream>
using namespace std;

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
*/

