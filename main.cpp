#include <iostream>
#include "menu.h"
#include "juego.h"
#include "constantes.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif



    srand(time(0));
    bool juego = true;
    int opcion;
    string nombre_jugador;
    int duracion = 0;
    const int tamaño_inversiones = 3;
    float inversiones [tamaño_inversiones];
    float patrimonio = 150000;
    float gastos_fijos[4] = {

    };

    while(juego){

        // Inicia el menu

        opcion = menu();

        switch(opcion){
            case 1:
                    nuevaPartida(MESES);
                break;
            case 2:
                cout << "Opcion 2" << endl;
                break;
            case 3:
                glosario();
                break;
            case 0:
                juego = salir_programa();
                break;
        }

    }

    return 0;
}
