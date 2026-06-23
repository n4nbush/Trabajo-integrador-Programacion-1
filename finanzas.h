#ifndef FINANZAS_H
#define FINANZAS_H

void eventos(int mes, float &sobrante_de_plata, float &sueldo, float &alquiler, std::string &evento, std::string &evento_descripcion);
void eventos_aleatorios(float &sobrante_de_plata);
void distribuir_sobrante(float sobrante_de_plata, float &fondo_emergencia, float &capital_invertir, float &dolares, float &bitcoin, float &sp500);
void menu_inversion(float capital_invertir, float sobrante_de_plata, float dolares, float bitcoin, float sp500);
#endif
