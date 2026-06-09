#include <iostream>
#include "menu.h"
#include "rlutil.h"
#include "constantes.h"

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
    std::cout <<"1. Nueva Partida"<<std::endl;
    std::cout <<"2. Highscore de la sesión"<<std::endl;
    std::cout <<"3. Glosario Financiero"<<std::endl;
    std::cout <<"0. Salir "<<std::endl;
    separador();
    std::cout <<"Ingrese una opcion: ";
    std::cin >> opmenu;

    return (opmenu);
    }

void limpiar_pantalla(){
    rlutil::cls();
}

bool salir_programa(){
    bool valor;
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
                rlutil::anykey();
                valor = false;
                break;
            case 2:
                limpiar_pantalla();
                std::cout << "Volviendo a menu principal" << std::endl;
                std::cout << "Presione Enter para continuar...";
                rlutil::anykey();
                valor = true;
                break;
        }
    }
    return (valor);
}

void texto_largo(std::string text) {
    int i = 0;
    if (text.length()>50){
        for (char x : text){
            std::cout << x;
            i++;

            if (i==49){
                std::cout << "\n";
                i = 0;
            }
        }
    }
    std::cout << std::endl;
}



void glosario(){
    bool ejecutar_glosario = true;
    while(ejecutar_glosario){
        int opcion = -1;
        while (opcion<1 || opcion>12){
            limpiar_pantalla();
            separador();
            texto_centrado("GLOSARIO FINANCIERO");
            separador();

            for (int i = 1; i <= CANTIDAD_TITULOS_GLOSARIO; i++){
                std::cout << i << " - " << GLOSARIO_TITULOS[i-1] << std::endl;
            }

            std::cout << "Ingrese una opcion para saber mas sobre la misma: ";
            std::cin >> opcion;

            if (opcion<1 || opcion>12){
                limpiar_pantalla();
                std::cout <<"Ingrese un numero que corresponda a algun titulo" << std::endl;
                std::cout << "Precione cualquier tecla para continuar...";
                std::cin.ignore();
                std::cin.get();
                continue;
            }

            limpiar_pantalla();

            separador();
            std::cout << GLOSARIO_TITULOS[opcion-1] << std::endl ;
            separador();
            texto_centrado("Descripcion");
            separador();

            texto_largo(GLOSARIO_DEFINICIONES[1]);

            separador();
            texto_centrado("¿QUÉ DESEÁS HACER AHORA?");
            separador();
            std::cout << "[1] Volver al Glosario (Buscar otro término)" << std::endl;
            std::cout << "[2] Salir al Menú Principal" << std::endl;
            separador();

            int op = -1;

            std::cin >> op;

            salir_programa();
        }
    }
}




