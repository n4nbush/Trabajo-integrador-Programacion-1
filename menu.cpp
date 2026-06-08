#include <iostream>
#include "menu.h" // Vinculamos con su cabecera

void separador(){
    int ancho = 50;
    std::string separador(ancho, '=');
    std::cout << separador << std::endl;
}

void texto_centrado(std::string texto){
    int ancho = 50;
    if (texto.length() >= ancho){
        std::cout << texto << std::endl;
    }
    int espacio = (ancho - texto.length())/2;
    std::string margen(espacio,' ');
    std::cout << margen << texto << std::endl;
}
int menu() {

    int opmenu = -1;
    limpiar_pantalla();

    separador();
    texto_centrado("SOBREVIVIR EL AÑO");
    separador();
    std::cout <<"1. Nueva Partida                   	 "<<std::endl;
    std::cout <<"2. Highscore de la sesión          	 "<<std::endl;
    std::cout <<"3. Glosario Financiero             	 "<<std::endl;
    std::cout <<"0. Salir                           	 "<<std::endl;
    separador();
    std::cout <<"Ingrese una opcion: ";
    std::cin >> opmenu;

    return (opmenu);
    }

void limpiar_pantalla(){
    std::cout << "\033[2J\033[H";
}

int salir_programa(){
    limpiar_pantalla();
    int opcion = -1;
    while(opcion<1 || opcion>2){
        separador();
        texto_centrado("DESEA SALIR DEL JUEGO?");
        separador();
        std::cout << "1. Si" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cout <<"Ingrese una opcion: ";
        std::cin >> opcion;

        switch(opcion){
            case 1:
                limpiar_pantalla();
                std::cout << "Cerrando programa" << std::endl;
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                return(false);
                break;
            case 2:
                limpiar_pantalla();
                std::cout << "Volviendo a menu principal" << std::endl;
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                return(true);
        }
    }
}


