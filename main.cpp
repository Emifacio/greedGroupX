#include<iostream>
#include<ctime>
#include "funciones.h"
using namespace std;


int main()
{
        int seleccion = mostrarMenu();

        procesarSeleccion(seleccion);


    // Inicializa la semilla para generar números aleatorios con base en el tiempo actual
    srand(time(0));

    // Variables para los tamaños de los dados y arrays.
    int x, tam = 2, t = 5, vB[2] = {}, vD[t] = {}, nT = 0, vDn[t] = {}, cD = 0, puntaje = 0;
    char pregunta = 'S'; // Variable para la decisión del usuario de continuar o no

    // Llama a la función para generar los dados bloqueadores y mostrar su valor
    tiradaBloqueadores(vB, tam);
    cout << "===================================" << endl;

    // Llama a la función para generar los dados del jugador
    tiradaDeDados(vD, t);
    cout << "===================================" << endl;

    // Llama a la función para filtrar los dados bloqueados y devuelve cuántos quedan
    cD = dadosNuevos(vD, vB);

    // Muestra los dados disponibles después de filtrar los bloqueados
    mostrarDados(vD, cD);
    cout << endl;

    // Suma los puntos de los dados disponibles
    puntaje = sumarDados(vD, cD);
    cout << "puntaje " << puntaje << endl;

    // Bucle para permitir al usuario decidir si continuar o no con la tirada de dados
    do
    {
        cout << "Desea continuar tirando (S para seguir o N para sumar los puntos acumulados):" << endl;
        cin >> pregunta; // Recibe la respuesta del usuario
    }
    while (pregunta != 'N'); // Repite mientras el usuario no quiera detenerse (es decir, si la respuesta es diferente de 'N')

    return 0;
}

