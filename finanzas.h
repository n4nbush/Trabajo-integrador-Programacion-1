#ifndef FINANZAS_H
#define FINANZAS_H

#include <string>

void eventos(int mes, float &sobrante_de_plata, float &sueldo, float &alquiler, std::string &evento, std::string &evento_descripcion, float &gastos);

void eventos_aleatorios(float &sobrante_de_plata, float &gastos);

void menu_inversion(float &capital_invertir,float &dolares, float &bitcoin,float &sp500,float &valor_dolar, float &valor_bitcoin,float &valor_sp500);

void distribuir_sobrante(float sobrante_de_plata,float &fondo_emergencia,float &capital_invertir, float &dolares, float &bitcoin, float &sp500,float &valor_dolar,float &valor_bitcoin,float &valor_sp500, float &ahorros);

#endif
