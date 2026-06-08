#include <iostream>
#include "menu.h"
#include "juego.h"

int main() {
    bool juego = true;
    int opcion;
    std::string nombre_jugador;
    int duracion = 0;
    int tamaño_inversiones = 5;
    float inversiones [tamaño_inversiones];
    float patrimonio = 150000;

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
                std::cout << "Opcion 3" << std::endl;
                break;
            case 0:
                juego = salir_programa();
                break;
        }

    }






    return 0;
}
