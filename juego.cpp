#include <iostream>
#include "juego.h"
#include "menu.h"

void iniciar_nuevo_juego(){


    std::string nombre;
    int duracion = 0;
    int patrimonio = 150000;

    limpiar_pantalla();
    separador();
    texto_centrado("CONFIGURANDO PARTIDA");
    separador();
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;

    while(duracion<1 || duracion>12){
        limpiar_pantalla();

        separador();
        texto_centrado("CONFIGURANDO PARTIDA");
        separador();
        std::cout << "Bienvenido " << nombre << std::endl;
        std::cout << "Cuantos meses va a durar la partida: ";
        std::cin >> duracion;

        if (duracion<1 || duracion>12){
            std::cout << "Duracion invalida. Debe ser un valor entre 1 y 12 meses";
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }


    limpiar_pantalla();
    std::cout << "Detalles de partida: " << std::endl;
    std::cout << "Nombre del jugador: " << nombre << std::endl;
    std::cout << "Duracion: " << duracion << " meses" << std::endl;
    std::cin.ignore();

}
