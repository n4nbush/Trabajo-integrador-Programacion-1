#include <iostream>
#include <cstdlib>
#include <ctime>
#include "constantes.h"
#include "juego.h"
#include "menu.h"

using namespace std;

void eventos(int mes, float &sobrante_de_plata, float &sueldo, float &alquiler, string &evento, string &evento_descripcion, float &gastos, float &valor_bitcoin){

    if (mes == 1){
        evento ="Deposito de garantia";
        evento_descripcion = "Se descuentan: $180000";
        sobrante_de_plata -= 180000;
        gastos += 180000;

    }

    if (mes == 4 || mes == 7 || mes == 10){
        evento ="Aumento de sueldo por paritarias";
        evento_descripcion = "Se aumenta el sueldo un 15%";
        sueldo *= 1.15;
    }

    if (mes == 9){
        evento = "Actualizacion del alquiler";
        evento_descripcion = "Sube el alquiler un 40%" ;
        alquiler *= 1.4;
    }

    if (mes == 6 || mes == 11){
        if(rand() % 100 < 50){
            evento = "Suba del historiaca de bitcoin ";
            evento_descripcion = "BTC sube en un +60%";
            valor_bitcoin *= 1.60;
        }else{
            evento = "Caida historiaca de bitcoin ";
            evento_descripcion = "BTC cae en un 50%";
            valor_bitcoin *= 0.50;
        }
    }
    

}


void invocar_evento_aleatorio(int contador_eventos, float &sobrante_de_plata, float &gastos){

    int numero = rand() % CANTIDAD_EVENTOS_ALEATOREOS;

    cout << "Evento aleatorio N°" << contador_eventos << ": "
         << NOMBRES_EVENTOS_ALEATOREOS[numero] << endl;

    cout << "Descripcion: "
         << DESCRIPCION_EVENTOS_ALEATOREOS[numero] << endl;

    cout << "Se van a descontar $"
         << IMPACTO_ECONOMICO_EVENTOS_ALEATOREOS[numero] << endl;

    sobrante_de_plata -= IMPACTO_ECONOMICO_EVENTOS_ALEATOREOS[numero];
    gastos += IMPACTO_ECONOMICO_EVENTOS_ALEATOREOS[numero];

    cout << "Sobrante actualizado: $" << sobrante_de_plata << endl;
    cout << endl;
}

void eventos_aleatorios(float &sobrante_de_plata, float &gastos){

    int contador_eventos = 0;

    if(rand() % 100 < 75){

        contador_eventos++;
        invocar_evento_aleatorio(contador_eventos, sobrante_de_plata,gastos);

        if(rand() % 100 < 15){

            contador_eventos++;
            invocar_evento_aleatorio(contador_eventos, sobrante_de_plata, gastos);

            if(rand() % 100 < 10){

                contador_eventos++;
                invocar_evento_aleatorio(contador_eventos, sobrante_de_plata,gastos);
            }
        }
    }

    if(contador_eventos == 0){
        cout << "Este mes no hubo eventos aleatorios." << endl;
    }
}

void menu_inversion(float &capital_invertir,float &dolares,float &bitcoin,float &sp500,float &valor_dolar,float &valor_bitcoin,float &valor_sp500){
    int opcion;

    while(true)
    {
        limpiar_pantalla();

        enmarcar_texto("MENU DE INVERSION");

        cout << "Monto disponible para invertir: $" << capital_invertir << endl;
        separador();

        cout << "1 - Comprar dolares (USD)" << endl;
        cout << "2 - Comprar Bitcoin (BTC)" << endl;
        cout << "3 - Invertir en S&P 500 (ETF)" << endl;
        cout << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                dolares += capital_invertir / valor_dolar;
                capital_invertir = 0;
                return;

            case 2:
                bitcoin += (capital_invertir / valor_dolar) / valor_bitcoin;
                capital_invertir = 0;
                return;

            case 3:
                sp500 += (capital_invertir / valor_dolar) / valor_sp500;
                capital_invertir = 0;
                return;

            default:
                cout << endl;
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
        }
    }
}

void distribuir_sobrante(float sobrante_de_plata, float &fondo_emergencia, float &capital_invertir, float &dolares, float &bitcoin,float &sp500, float &valor_dolar, float &valor_bitcoin, float &valor_sp500, float &ahorros){
    int decision;

    if(sobrante_de_plata > 0)
    {
        cout << "Como distribuis tu sobrante del mes?" << endl;
        cout << "Tu sueldo sobrante es de: $" << sobrante_de_plata << endl;
        cout << endl;

        cout << "1. 25% inversion - 75% fondo de emergencia" << endl;
        cout << "2. 50% inversion - 50% fondo de emergencia" << endl;
        cout << "3. 75% inversion - 25% fondo de emergencia" << endl;
        cout << "4. 100% inversion - 0% fondo de emergencia" << endl;

        cout << "Ingrese una opcion: ";
        cin >> decision;

        switch(decision)
        {
            case 1:
                capital_invertir += sobrante_de_plata * 0.25;
                fondo_emergencia += sobrante_de_plata * 0.75;
                ahorros = capital_invertir;
                break;

            case 2:
                capital_invertir += sobrante_de_plata * 0.50;
                fondo_emergencia += sobrante_de_plata * 0.50;
                ahorros = capital_invertir;
                break;

            case 3:
                capital_invertir += sobrante_de_plata * 0.75;
                fondo_emergencia += sobrante_de_plata * 0.25;
                ahorros = capital_invertir;
                break;

            case 4:
                capital_invertir += sobrante_de_plata;
                ahorros = capital_invertir;
                break;

            default:
                cout << "Opcion invalida. Todo el sobrante queda disponible." << endl;
                pausar();
                return;
        }

        menu_inversion(capital_invertir,dolares,bitcoin,sp500,valor_dolar,valor_bitcoin,valor_sp500);
    }
    else
    {
        cout << "Este mes tuviste numeros rojos :(" << endl;
    }
}
