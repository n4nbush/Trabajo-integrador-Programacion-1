#include <iostream>
#include "menu.h"
#include "juego.h"

int main() {
    bool juego = true;
    int opcion;

    while(juego){

        // Inicia el menu

        opcion = menu();

        switch(opcion){
            case 1:
                    iniciar_nuevo_juego();
                break;
            case 2:
                std::cout << "Opcion 1" << std::endl;
                break;
            case 3:
                std::cout << "Opcion 1" << std::endl;
                break;
            case 0:
                juego = salir_programa();
                break;
        }

    }






    return 0;
}
