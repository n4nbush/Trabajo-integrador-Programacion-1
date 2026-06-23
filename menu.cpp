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

void showitem(const char* text, int posx, int posy, bool selected){
    if (selected){
        rlutil::locate(posx-3,posy);
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        cout << ">> " << text << " <<" ;

    }else{
        rlutil::locate(posx,posy);
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        cout << "" << text << "" ;

    }
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

}



int menu(){
    
    

    int op = 1, y = 0;
    rlutil::hidecursor();
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    do
    {
        limpiar_pantalla();

        
        rlutil::locate(30,10);
        cout <<"Sobrevivir al año";
        
        showitem("Nueva Partida          ",30,12, y == 0);
        showitem("Highscore de la sesión ",30,13, y == 1);
        showitem("Glosario Financiero    ",30,14, y == 2);
        showitem("Salir                  ",30,15, y == 3);


        int key = rlutil::getkey();


        switch (key)
        {
        case 65: //arriba
            if (y>0){
                rlutil::locate(27,10+y);
                cout << " " ;
                rlutil::locate(45,10+y);
                cout << " " ;
                y--;
            }
            break;
        case 66: //abajo
            if (y<3){
                rlutil::locate(27,10+y);
                cout << " " ;
                rlutil::locate(45,10+y);
                cout << " " ;
                y++;
                }
            break;
        case 10://enter
            
            switch (y)
            {
            case 0:
                return(y);
                break;
            case 1:
                return(y);
                break;
            case 2:
                return(y);
                break;
            case 3:          
                return(y);
                break;
            }
        
        }

        op = 1;
    
    } while (op != 0);

    return (op);
    

}

int menu2() {

    int opmenu = -1;
    limpiar_pantalla();

    rlutil::locate(0,10);
    string texto = string("SOBREVIVE EL A") + char(165) + "O";    
    enmarcar_texto(texto);

    rlutil::locate(20,11);
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
    int op = -1, y = 0;
    
    do
    {
        limpiar_pantalla();
        rlutil::locate(0,0);
        separador();
        texto_centrado("DESEA SALIR DEL JUEGO?");
        separador();

        showitem("SI",30,10,y == 0);
        showitem("NO",30,11,y == 1);
        
        int key = rlutil::getkey();


        switch (key)
        {
        case 65: //arriba
            if (y>0){
                rlutil::locate(27,10+y);
                cout << " " ;
                rlutil::locate(45,10+y);
                cout << " " ;
                y--;
            }
            break;
        case 66: //abajo
            if (y<1){
                rlutil::locate(27,10+y);
                cout << " " ;
                rlutil::locate(45,10+y);
                cout << " " ;
                y++;
                }
            break;
        case 10://enter
            
            switch (y)
            {
            case 0:
                return(y);
                break;
            case 1:
                return(y);
                break;
            }
        
        }

        switch(op){
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
    } while (op !=0);
    
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
        int opcion = -1, y = 1;
        do{
            limpiar_pantalla();
            rlutil::locate(30,1);
            cout << endl;
            enmarcar_texto("GLOSARIO FINANCIERO");


            for (int i = 1; i <= CANTIDAD_TITULOS_GLOSARIO-1; i++){
               showitem(GLOSARIO_TITULOS[i],30,5+i,y == i); 
            }
            showitem("SALIR DEL GLOSARIO",30,18,y==13);

            int key = rlutil::getkey();


            switch (key)
            {
                case 65: //arriba
                    if (y>1){
                        rlutil::locate(27,5+y);
                        cout << " " ;
                        rlutil::locate(45,5+y);
                        cout << " " ;
                        if (y==13){
                            y--;
                        }
                        y--;
                    }
                    break;
                case 66: //abajo
                    if (y<13){
                        rlutil::locate(27,5+y);
                        cout << " " ;
                        rlutil::locate(45,5+y);
                        cout << " " ;
                        if (y==11){
                            y++;
                        }
                        y++;
                        }
                    break;
                case 10://enter
                    cout << "Puto";
                    limpiar_pantalla();

                    switch (y)
                    {
                    case 13:
                        ejecutar_glosario=false;
                        opcion = 0;
                        break;
                    
                    default:
                        separador();
                        cout << GLOSARIO_TITULOS[y] << endl ;
                        separador();
                        texto_centrado("Descripcion");
                        separador();
                        texto_largo(GLOSARIO_DEFINICIONES[y]);
                        
                        pausar();
                        break;
                }
            }
        } while (opcion!= 0);
        

        
    }
}




