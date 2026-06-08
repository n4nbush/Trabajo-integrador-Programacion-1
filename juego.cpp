#include <iostream>
#include "juego.h"
#include "menu.h"

void configurar_juego(std::string &nombre_jugador, int &duracion, float &patrimonio, float inversiones[]){

    
    int respuesta = 2;
    bool datos_validos = false;

    while(!datos_validos){

        // ENTRADA DE NOMBRE

        limpiar_pantalla();
        separador();
        texto_centrado("CONFIGURANDO PARTIDA");
        separador();
        std::cout << "Ingrese su nombre: ";
        std::cin >> nombre_jugador;
        limpiar_pantalla();
        
        // ENTRADA DE DURACION 
        while (duracion<1 || duracion>12){
            separador();
            texto_centrado("CONFIGURANDO PARTIDA");
            separador();
            std::cout << "Bienvenido " << nombre_jugador << std::endl;
            std::cout << "Cuantos meses va a durar la partida: ";
            std::cin >> duracion;


            // VALIDAMOS DURACION
            if (duracion<1 || duracion>12){
                std::cout << "Duracion invalida. Debe ser un valor entre 1 y 12 meses";
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                continue;
            }
        }
        
        // ENTREGA DE DATOS
        limpiar_pantalla();
        separador();
        texto_centrado("DETALLES DE LA PARTIDA");
        separador();
        std::cout << "Nombre del jugador: " << nombre_jugador << std::endl;
        std::cout << "Duracion: " << duracion << " meses" << std::endl;
        std::cout << "Patrimonia inicial: " << "$" << patrimonio << std::endl;
        std::cout << "Inversiones: " << "$" << inversiones << std::endl;
        std::cout << std::endl;
        
        // SOLICITAMOS CONFIRMACION AL USUARIO
        std::cout << "Los datos son correctos?" << std::endl;
        std::cout << "1. Si" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cout <<"Ingrese una opcion: ";
        std::cin >> respuesta;
        
        switch (respuesta)
        {
        case 1:
            limpiar_pantalla();
            std::cout << "Iniciando juego..." << std::endl;
            std::cout << "Preciones una tecla para iniciar el juego" << std::endl;
            std::cin.ignore();
            std::cin.get();
            datos_validos = true;
            break;
        case 2:
            limpiar_pantalla();
            std::cout << "Regresando a los ajustes..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            duracion = 0;
            break;
        default:
            limpiar_pantalla();
            std::cout << "Ingrese una respuesta correcta";
            std::cin.ignore();
            std::cin.get();
            break;
        }
    }
}

void partida(std::string &nombre_jugador, int &duracion, float &patrimonio, float inversiones[]){
    
    std::string meses[12] = {"ENERO", "FEBRERO","MARZO", "ABRIL", "MAYO", "JUNIO","JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

    limpiar_pantalla();
    
    for(int i=1; i <= duracion; i++){
        separador();
        std::cout << "MES " << i << "/" << duracion << " - " << meses[i-1] << " Jugador: " << nombre_jugador << std::endl;
        separador();

        texto_centrado("TENENCIAS ACTUALES");
        std::cout << "Disponible en pesos: $" << patrimonio << std::endl;
        std::cout << "Fondo de emergencia: $" << inversiones[1];
    }

    std::cin.ignore();
}
