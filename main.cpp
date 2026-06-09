#include <iostream>
#include "menu.h"
#include "juego.h"
#include "rlutil.h"

int main() {

    //rlutil::setBackgroundColor(rlutil::BLACK);
    //rlutil::setColor(rlutil::WHITE);
    //rlutil::cls();

    bool juego = true;
    int opcion;
    std::string nombre_jugador;
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
                    configurar_juego(nombre_jugador,duracion,patrimonio,inversiones);
                    partida(nombre_jugador,duracion,patrimonio,inversiones);
                break;
            case 2:
                std::cout << "Opcion 2" << std::endl;
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
