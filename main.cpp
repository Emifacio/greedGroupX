#include<iostream>
#include<ctime>
using namespace std;

// Esta función genera los "dados bloqueadores" que son 2 dados aleatorios.
void tiradaBloqueadores(int v[], int t)
{
    t = 2; // Inicializa la cantidad de dados bloqueadores (2)
    int x, dado;
    cout << "Dados bloqueadores " << endl;
    cout << "===================================" << endl;
    for (x = 0; x < 2; x++) // Itera dos veces para generar dos dados bloqueadores
    {
        dado = (rand() % 6 + 1); // Genera un número aleatorio entre 1 y 6
        v[x] = dado; // Guarda el dado generado en el vector `v`
        cout << "Dado " << x + 1 << " = " << v[x] << endl; // Muestra el valor de cada dado bloqueador
    }
}

// Esta función genera los 5 dados que va a tirar el jugador.
void tiradaDeDados(int vD[], int tam)
{
    tam = 5; // Define que el jugador lanza 5 dados
    int x;
    cout << "Dados " << endl;
    cout << "===================================" << endl;
    for (x = 0; x < 5; x++) // Itera cinco veces para generar cinco dados
    {
        vD[x] = (rand() % 6 + 1); // Genera un número aleatorio entre 1 y 6 para cada dado
        cout << "Dado " << x + 1 << " = " << vD[x] << endl; // Muestra el valor de cada dado
    }
}

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
    // Esta segunda iteración filtra los dados que no han sido bloqueados (es decir, los que no son 0);
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

// Esta función suma los valores de los dados que no han sido bloqueados.
int sumarDados(int vD[], int t)
{
    int x, aP = 0; // `aP` acumula los puntos
    for (x = 0; x < t; x++) // Itera sobre los dados no bloqueados
    {
        aP += vD[x]; // Suma el valor de cada dado
    }
    return aP; // Devuelve la suma total de los puntos
}

// Función principal del programa donde se realiza la lógica del juego.
int main()
{
    srand(time(0)); // Inicializa la semilla para generar números aleatorios con base en el tiempo actual

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

