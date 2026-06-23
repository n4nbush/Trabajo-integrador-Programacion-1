#include <iostream>
#include <string>
#include "menu.h"
#include "constantes.h"
#include "rlutil.h"

using namespace std;

void separador(){
    int ancho = 50;
    for (int i =  0; i < ancho; i++){
        cout << "─";
    }
    cout << endl;
}

/// funcion para pausar
void pausar(){
    //system("pause");
    rlutil::anykey();
}

void texto_centrado(string texto){
    int ancho = 50;
    if (texto.length() >= ancho){
        cout << texto << endl;
    }
    int espacio = (ancho - texto.length())/2;
    string margen(espacio,' ');
    cout << margen << texto << endl;
}


void dibujar_linea(string caracter, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << caracter;
    }
}

void enmarcar_texto(string texto){
    int ancho = 50;

    if (texto.length() > (ancho - 2)) {
        texto = texto.substr(0, ancho - 5) + "...";
    }
    int espacio_disponible = (ancho -2)- texto.length();
    int margen_izquierdo = espacio_disponible / 2;
    int margen_derecho = espacio_disponible - margen_izquierdo ;

    cout << "╔";
    dibujar_linea("═", ancho - 2); // <- Con comillas dobles
    cout << "╗" << endl;

    if (texto.length() >= ancho){
                cout << texto << endl;
    }else{
            cout << "║";
            dibujar_linea(" ", margen_izquierdo);
            cout << texto ;
            dibujar_linea(" ", margen_derecho);

            cout << "║" << endl;
    }

    cout << "╚";
    dibujar_linea("═", ancho - 2); // <- Con comillas dobles
    cout << "╝" << endl;

}


int menu() {

    int opmenu = -1;
    limpiar_pantalla();

    string texto = string("SOBREVIVE EL A") + char(165) + "O";    enmarcar_texto(texto);


    cout <<"1. Nueva Partida"<<endl;
    cout <<"2. Highscore de la sesión"<<endl;
    cout <<"3. Glosario Financiero"<<endl;
    cout <<"0. Salir "<<endl;
    separador();
    cout <<"Ingrese una opcion: ";
    cin >> opmenu;

    return (opmenu);
    }

void limpiar_pantalla(){
    //system("cls");
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
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout <<"Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                limpiar_pantalla();
                cout << "Cerrando programa" << endl;
                cout << "Presione Enter para continuar...";
                pausar();
                valor = false;
                break;
            case 2:
                limpiar_pantalla();
                cout << "Volviendo a menu principal" << endl;
                cout << "Presione Enter para continuar...";
                pausar();
                valor = true;
                break;
        }
    }
    return (valor);
}

void texto_largo(string text) {
    int i = 0;
    if (text.length()>50){
        for (char x : text){
            cout << x;
            i++;

            if (i==49){
                cout << "\n";
                i = 0;
            }
        }
    }
    cout << endl;
}



void glosario(){
    bool ejecutar_glosario = true;
    while(ejecutar_glosario){
        int opcion = -1;
        while (opcion<1 || opcion>12){
            limpiar_pantalla();
            enmarcar_texto("GLOSARIO FINANCIERO");

            for (int i = 1; i <= CANTIDAD_TITULOS_GLOSARIO; i++){
                cout << i << " - " << GLOSARIO_TITULOS[i-1] << endl;
            }

            separador();

            cout << "Ingrese una opcion para saber mas sobre la misma: ";
            cin >> opcion;

            if (opcion<1 || opcion>12){
                limpiar_pantalla();
                cout <<"Ingrese un numero que corresponda a algun titulo" << endl;
                cout << "Precione cualquier tecla para continuar...";
                cin.ignore();
                cin.get();
                continue;
            }

            limpiar_pantalla();

            separador();
            cout << GLOSARIO_TITULOS[opcion-1] << endl ;
            separador();
            texto_centrado("Descripcion");
            separador();

            texto_largo(GLOSARIO_DEFINICIONES[1]);

            separador();
            texto_centrado("¿QUÉ DESEÁS HACER AHORA?");
            separador();
            cout << "[1] Volver al Glosario (Buscar otro término)" << endl;
            cout << "[2] Salir del Glosario" << endl;
            separador();

            int op = -1;

            cin >> op;

            if (op == 1){
                continue;
            }
            else if(op == 2){
                ejecutar_glosario = false;
            }
            else{
                cout << "Ingrese una opcion correcta" << endl;
            }

        }
    }
}




