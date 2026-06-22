#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED

#include <string>

                // Variables globales de la sesion compartidas entre modulos (extern)//
extern int sesion_cantidad_partidas;
extern float sesion_mejor_patrimonio;
extern std::string sesion_mejor_jugador;

           // Inicializa los valores de la sesion al arrancar el programa//
void inicializarHighscore();

           // Muestra la pantalla del Highscore de la sesion (Opcion 2 del Menu)//
void mostrarHighscore();

          // Evalua si el resultado de una partida supera el record actual y lo actualiza//
void evaluarYActualizarHighscore(std::string nombreJugador, float patrimonioFinal);





#endif // HIGHSCORE_H_INCLUDED
