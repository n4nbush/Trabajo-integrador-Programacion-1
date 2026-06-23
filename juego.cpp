#include <iostream>
#include "juego.h"
#include "menu.h"
#include "constantes.h"
#include "finanzas.h"
using namespace std;

void configurar_juego(string &nombre_jugador, int &duracion, float &patrimonio, float inversiones[]){


    int respuesta = 2;
    bool datos_validos = false;


    while(!datos_validos){

        // ENTRADA DE NOMBRE

        limpiar_pantalla();
        enmarcar_texto("CONFIGURANDO PARTIDA");
        cout << "Ingrese su nombre: ";
        std::getline(cin, nombre_jugador);
        limpiar_pantalla();

        // ENTRADA DE DURACION
        while (duracion<1 || duracion>12){
            enmarcar_texto("CONFIGURANDO PARTIDA");
            cin.ignore();
            cout << "Bienvenido " << nombre_jugador << endl;
            cin.ignore();
            cout << "Cuantos meses va a durar la partida: ";
            cin >> duracion;


            // VALIDAMOS DURACION
            if (duracion<1 || duracion>12){
                cout << "Duracion invalida. Debe ser un valor entre 1 y 12 meses";
                cout << "Presione Enter para continuar...";
                cin.ignore();
                cin.get();
                continue;
            }
        }

        // ENTREGA DE DATOS
        limpiar_pantalla();
        enmarcar_texto("DETALLES DE LA PARTIDA");

        cout << "Nombre del jugador: " << nombre_jugador << endl;
        cout << "Duracion: " << duracion << " meses" << endl;
        cout << "Patrimonia inicial: " << "$" << patrimonio << endl;
        cout << "Inversiones: " << "$" << inversiones << endl;
        cout << endl;

        // SOLICITAMOS CONFIRMACION AL USUARIO
        cout << "Los datos son correctos?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout <<"Ingrese una opcion: ";
        cin >> respuesta;

        switch (respuesta)
        {
        case 1:
            limpiar_pantalla();
            cout << "Iniciando juego..." << endl;
            cout << "Preciones una tecla para iniciar el juego" << endl;
            cin.ignore();
            cin.get();
            datos_validos = true;
            break;
        case 2:
            limpiar_pantalla();
            cout << "Regresando a los ajustes..." << endl;
            cin.ignore();
            cin.get();
            duracion = 0;
            break;
        default:
            limpiar_pantalla();
            cout << "Ingrese una respuesta correcta";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

/// primer funcion para el punto 1
void nuevaPartida(const string meses[]){
    string nombreJugador;
    int rondas;

    limpiar_pantalla();

    cout << "Ingrese su nombre completo: ";
    getline(cin, nombreJugador);

    limpiar_pantalla();
    cout << "Bienvenido " << nombreJugador << endl;

    cout << "Cuantas rondas queres jugar (1 minimo y un maximo de 12): ";
    cin >> rondas;

    cout << "Perfecto seleccionaste la cantidad de " << rondas << " meses" << endl;
   pausar();

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
            float fondo_emergencia = 0;
            float capital_invertir = 0;


for(int i=1; i<=rondas; i++){
    limpiar_pantalla();

    bool cobrar_aguinaldo = false;

    gastosFijos = alquiler + servicios + transporte + alimentacion;
    sobrante_de_plata = sueldo - gastosFijos;


        if(i%6==0){
            cobrar_aguinaldo = true;
            aguinaldo = sueldo / 2;
        }

        if(cobrar_aguinaldo){
            sobrante_de_plata += aguinaldo;
        }

        string evento ="";
        string evento_descripcion = "";

        eventos(i, sobrante_de_plata, sueldo, alquiler, evento, evento_descripcion);


        cout << "=======================================================" << endl;
        cout << i << "/" << rondas << " - " << meses[i-1] << "               Jugador: " << nombreJugador << endl;
        cout << "=======================================================" << endl;


        cout << "TENDENCIAS ACTUALES: "<< endl;
        cout << "Disponible en pesos:$ "<< sobrante_de_plata << endl;
        cout << "Dolares:$ " << dolares <<endl;
        cout << "Bitcoin:$ "<< bitcoin <<endl;
        cout << "S&P 500:$ "<< sp500 <<endl;
        cout <<endl;

        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "Sueldo del mes:$ " << sueldo << endl;
        cout << "Gastos fijos:$ " << gastosFijos << endl;
        if(cobrar_aguinaldo){
            cout << "Este mes cobraste aguinaldo $ " << aguinaldo<< endl;
        }
        cout << "======================================================="<<endl;

        //if (i == 1){cout << "Deposito de garantia" << endl;}
        cout << "Eventos: " << endl;
        if (evento.length() != 0 && evento_descripcion.length() != 0){
            cout << evento << endl;
            cout << evento_descripcion << endl << endl;
        }

        eventos_aleatorios(sobrante_de_plata);

        string texto = "Sobrante actualizado: $" + to_string(int(sobrante_de_plata));

        enmarcar_texto(texto);

        cout << "Precione cualquier tecla para continuar...";



        pausar();
        limpiar_pantalla();

        distribuir_sobrante(sobrante_de_plata, fondo_emergencia, capital_invertir,dolares,bitcoin,sp500);
        cout << endl << endl;
        cout << "Fondo de emergencia actual: $" << fondo_emergencia << endl;
        cout << "Capital para invertir acumulado: $" << capital_invertir << endl;

        cout << endl << "Precione cualquier tecla para continuar...";

        pausar();
        limpiar_pantalla();



        servicios *= 1.07;
        transporte *= 1.07;
        alimentacion *= 1.07;
        valor_dolar *=1.05;

     /// termina el for
    }

    pausar();
    ///termina la funcion
}