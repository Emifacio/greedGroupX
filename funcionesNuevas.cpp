#include <iostream>
#include <ctime>
using namespace std;

// Declaración de funciones
void iniciarJuego(string& jugador1, string& jugador2);
void procesarTurnoJugador(string nombre, int& puntajeRonda, int rondas[], int tam);
bool realizarTirada(int dados[], int tam, int bloqueadores[], int& puntaje, bool& duplicar);
bool preguntarContinuar(bool duplicar);
void mostrarResultadosFinales(string jugador1, string jugador2, int totalJugador1, int totalJugador2);
void mostrarCartelGanador(string ganador);
void limpiarPantalla();

// Función principal del juego
int main() {
    string jugador1, jugador2;
    int aP[3] = {}, aP2[3] = {};  // Puntos por ronda de cada jugador
    int aPt = 0, aPt2 = 0;  // Puntos totales

    iniciarJuego(jugador1, jugador2);

    // Rondas
    for (int ronda = 0; ronda < 3; ronda++) {
        cout << "=== Ronda " << ronda + 1 << " ===" << endl;
        cout << "Turno de " << jugador1 << endl;
        procesarTurnoJugador(jugador1, aP[ronda], aP, 3);

        cout << "Turno de " << jugador2 << endl;
        procesarTurnoJugador(jugador2, aP2[ronda], aP2, 3);
    }

    // Calcular puntaje total
    for (int i = 0; i < 3; i++) {
        aPt += aP[i];
        aPt2 += aP2[i];
    }

    mostrarResultadosFinales(jugador1, jugador2, aPt, aPt2);

    return 0;
}

// Función para iniciar el juego (pedir nombres y mostrar bienvenida)
void iniciarJuego(string& jugador1, string& jugador2) {
    cout << "Bienvenidos al juego de GREED" << endl;
    cout << "Jugador 1, ingresa tu nombre: ";
    cin >> jugador1;
    cout << "Jugador 2, ingresa tu nombre: ";
    cin >> jugador2;
    limpiarPantalla();
}

// Función para procesar el turno de cada jugador
void procesarTurnoJugador(string nombre, int& puntajeRonda, int rondas[], int tam) {
    int tamDados = 5, tamBloqueadores = 2;
    int dados[tamDados] = {}, bloqueadores[tamBloqueadores] = {};
    int puntaje = 0;
    bool duplicar = false;

    // Tirada inicial con dados bloqueadores
    tiradaBloqueadores(bloqueadores, tamBloqueadores);
    mostrarDados(bloqueadores, tamBloqueadores);

    // Primera tirada
    bool continuar = realizarTirada(dados, tamDados, bloqueadores, puntaje, duplicar);

    while (continuar) {
        continuar = realizarTirada(dados, tamDados, bloqueadores, puntaje, duplicar);
    }

    puntajeRonda = puntaje;
    cout << nombre << " terminó su turno con " << puntajeRonda << " puntos en esta ronda." << endl;
}

// Función que maneja una tirada y devuelve si el jugador puede continuar
bool realizarTirada(int dados[], int tam, int bloqueadores[], int& puntaje, bool& duplicar) {
    tiradaDeDados(dados, tam);
    mostrarDados(dados, tam);
    duplicar = dadosIguales(dados, tam);

    // Actualizar dados según bloqueadores
    int t = dadosNuevos(dados, tam, bloqueadores);
    mostrarDados(dados, t);

    // Sumar puntos
    int puntosTirada = sumarDados(dados, t);
    if (duplicar) {
        puntosTirada *= 2;
    }
    puntaje += puntosTirada;

    cout << "Puntos en esta tirada: " << puntosTirada << endl;
    cout << "Puntaje acumulado: " << puntaje << endl;

    return preguntarContinuar(duplicar);
}

// Función que pregunta si el jugador quiere continuar
bool preguntarContinuar(bool duplicar) {
    char respuesta;
    if (!duplicar) {
        cout << "¿Deseas continuar tirando (S/N)? ";
        cin >> respuesta;
        return (respuesta == 'S' || respuesta == 's');
    }
    return true;
}

// Función para mostrar los resultados finales del juego
void mostrarResultadosFinales(string jugador1, string jugador2, int totalJugador1, int totalJugador2) {
    cout << "=== Resultados Finales ===" << endl;
    cout << jugador1 << ": " << totalJugador1 << " puntos" << endl;
    cout << jugador2 << ": " << totalJugador2 << " puntos" << endl;

    if (totalJugador1 > totalJugador2) {
        mostrarCartelGanador(jugador1);
    } else {
        mostrarCartelGanador(jugador2);
    }
}

// Función para mostrar el cartel del ganador
void mostrarCartelGanador(string ganador) {
    cout << "**************************************" << endl;
    cout << "¡Felicidades " << ganador << "!" << endl;
    cout << "¡Eres el ganador de GREED!" << endl;
    cout << "**************************************" << endl;
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    system("cls");  // En Windows; en Linux/Mac usar "clear"
}
