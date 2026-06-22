#ifndef FINANZAS_H
#define FINANZAS_H

void eventos(int mes, float &sobrante_de_plata, float &sueldo, float &alquiler);
void eventos_aleatorios(float &sobrante_de_plata);
void distribuir_sobrante(float sobrante_de_plata, float &fondo_emergencia, float &capital_invertir);
#endif
