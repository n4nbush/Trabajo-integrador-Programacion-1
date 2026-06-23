#include <iostream>
#include "menu.h"
#include "juego.h"
#include "constantes.h"
#include "highscore.h"
#include "rlutil.h"

#ifdef _WIN32
#include <windows.h>
#endif


using namespace std;

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);


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
            case 0:
                    nuevaPartida(MESES);
                break;
            case 1:
                 mostrarHighscore(); // Llama a la funcion del archivo .cpp

                break;
            case 2:
                glosario();
                break;
            case 3:
                juego = salir_programa();
                break;
        }

    }

    return 0;
}
