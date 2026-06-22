#include "highscore.h"
#include <iostream>
#include <limits> // limpia el buffer correctamente//

using namespace std;

           // Definicion e inicializacion real de las variables de sesion en memoria//

int sesion_cantidad_partidas = 0;
float sesion_mejor_patrimonio = 0.0f;
string sesion_mejor_jugador = "Ninguno";

void inicializarHighscore() {
    sesion_cantidad_partidas = 0;
    sesion_mejor_patrimonio = 0.0f;
    sesion_mejor_jugador = "Ninguno";
}

void mostrarHighscore() {
    // Limpieza de pantalla universal///

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    cout << "♥======================================♥" << endl;
    cout << "        HIGHSCORE DE LA SESION          " << endl;
    cout << "♥=======================================♥" << endl;
    cout << " Total de partidas jugadas: " << sesion_cantidad_partidas << endl;
    cout << "----------------------------------------" << endl;
    cout << " RECORD ACTUAL:" << endl;
    cout << " Jugador: " << sesion_mejor_jugador << endl;
    cout << " Mejor Patrimonio Real: $" << sesion_mejor_patrimonio << endl;
    cout << "========================================" << endl;
    cout << " Presione ENTER para volver al menu principal... ";

                 // Solucion especifica para congelar la pantalla pero sin saltos// (esto se puede usar ??)//
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void evaluarYActualizarHighscore(string nombreJugador, float patrimonioFinal) {
    sesion_cantidad_partidas++;

    if (sesion_cantidad_partidas == 1 || patrimonioFinal > sesion_mejor_patrimonio) {
        sesion_mejor_patrimonio = patrimonioFinal;
        sesion_mejor_jugador = nombreJugador;

        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << " 🏆 ¡NUEVO RECORD DE LA SESION! 🏆" << endl;
        cout << " ♥Te convertiste en el mejor administrador♥ " << endl;
        cout << "----------------------------------------" << endl;
    }
}

