#include <iostream>
#include "juego.h"
#include "menu.h"
#include "constantes.h"

void configurar_juego(std::string &nombre_jugador, int &duracion, float &patrimonio, float inversiones[]){

    
    int respuesta = 2;
    bool datos_validos = false;

    while(!datos_validos){

        // ENTRADA DE NOMBRE

        limpiar_pantalla();
        enmarcar_texto("CONFIGURANDO PARTIDA");
        std::cout << "Ingrese su nombre: ";
        std::cin >> nombre_jugador;
        limpiar_pantalla();
        
        // ENTRADA DE DURACION 
        while (duracion<1 || duracion>12){
            enmarcar_texto("CONFIGURANDO PARTIDA");
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
        enmarcar_texto("DETALLES DE LA PARTIDA");

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

    
    float alquiler = 180000;
    float servicios = 45000;
    float transporte = 30000;
    float alimentacion = 80000;
    float gastosFijos = 0;
    float sueldo=500000;
    float sobrante_de_plata=150000;
    float dolares=0;
    float bitcoin=0;
    float sp500=0;
    float valor_dolar=1000;
    float aguinaldo=0;
    
    for(int i=1; i <= duracion; i++){
        
        limpiar_pantalla();
        bool cobrar_aguinaldo=false;

        gastosFijos = alquiler + servicios + transporte + alimentacion;

        if(i == 9){
        alquiler *= 1.4;
        }

        if(i%6==0){
                cobrar_aguinaldo=true;
                aguinaldo=sueldo/2;
        }

        if(cobrar_aguinaldo){
                sobrante_de_plata+=aguinaldo;
        }

        std::string texto_info = "MES " + std::to_string(i) + "/" + std::to_string(duracion) + " - " + meses[i-1] + " Jugador: " + nombre_jugador;
        
        enmarcar_texto(texto_info);

        texto_centrado("TENENCIAS ACTUALES");
        separador();
        
        std::cout << "Disponible en pesos:$ "<< sobrante_de_plata << std::endl;
        std::cout << "Dolares:$ " << dolares <<std::endl;
        std::cout << "Bitcoin:$ "<< bitcoin <<std::endl;
        std::cout << "S&P 500:$ "<< sp500 <<std::endl;

        separador();

        std::cout << "Sueldo del mes:$ " << sueldo << std::endl;
        std::cout << "Gastos fijos:$ " << gastosFijos << std::endl;
        if(cobrar_aguinaldo){
            std::cout << "Este mes cobraste aguinaldo $ " << aguinaldo<< std::endl;
        }
        separador();
        std::cin.ignore();
        limpiar_pantalla();

        std::cout << "Como distribuis tu sobrante del mes? " <<std::endl;
        std::cout << "Tu sueldo sobrante es de:$ " << sobrante_de_plata << std::endl;
        std::cout << std::endl;
        std::cout << "1. 25% inversion -  75% fondo de emergencia " <<std::endl;
        std::cout << "2. 50% inversion -  50% fondo de emergencia " <<std::endl;
        std::cout << "3. 75% inversion -  25% fondo de emergencia " <<std::endl;
        std::cout << "4. 100% inversion -  0% fondo de emergencia " <<std::endl;
        std::cin.ignore();
        limpiar_pantalla();

        if(i%3==0){
            sueldo*=1.15;
             }
        servicios *= 1.07;
        transporte *= 1.07;
        alimentacion *= 1.07;
        valor_dolar *=1.05;

    }

    std::cin.ignore();
}
