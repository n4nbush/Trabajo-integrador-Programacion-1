#ifndef CONSTANTES_H 
#define CONSTANTES_H

#include <string>

// ========== VALORES INICIALES DEL JUEGO ==========

const float PATRIMONIO_INICIA = 150000.00;
const int CANTIDAD_INVERSIONES = 4;
const int CANTIDAD_GASTOS = 4;

// ========== Gastos fijos ==========

const float GASTOS_INICIALES[CANTIDAD_GASTOS] = {
    180000,  // Alquiler
    45000,   // Servicios
    30000,   // Transporte
    80000    // Alimentación
};

// =============== Glosario Financiero ===========

const int CANTIDAD_TITULOS_GLOSARIO = 12;

const std::string GLOSARIO_TITULOS [CANTIDAD_TITULOS_GLOSARIO]{
    "Inflación",
    "Poder adquisitivo",
    "Salario real vs. salario nominal",
    "Fondo de emergencia",
    "Diversificación",
    "Costo de oportunidad",
    "Volatilidad",
    "Liquidez",
    "Indexación",
    "ETF (Exchange-Traded Fund)",
    "Patrimonio real",
    "Patrimonio inicial"
};

const std::string GLOSARIO_DEFINICIONES [CANTIDAD_TITULOS_GLOSARIO]{
    "Aumento generalizado y sostenido de los precios de bienes y servicios. Hace que el dinero valga menos con el tiempo.",
    "Cantidad de bienes y servicios que se pueden comprar con una suma de dinero. Disminuye cuando hay inflación.",
    "El salario nominal es el número en el recibo de sueldo. El salario real mide cuánto se puede comprar con ese dinero. Si la inflación supera al aumento del sueldo, el salario real cae.",
    "Reserva de dinero en efectivo o cuenta disponible para cubrir gastos imprevistos sin necesidad de endeudarse ni vender inversiones.",
    "Estrategia de distribuir el dinero entre distintos instrumentos para reducir el riesgo total. 'No poner todos los huevos en la misma canasta.",
    "El valor de la mejor alternativa que se resigna al tomar una decisión. Guardar plata en pesos tiene el costo de oportunidad de no invertirla.",
    "Medida de cuánto varía el precio de un activo. Un instrumento muy volátil (como el Bitcoin) puede subir o bajar mucho en poco tiempo",
    "Facilidad con la que un activo se puede convertir en dinero disponible. El efectivo es el activo más líquido; los inmuebles, el menos.",
    "Mecanismo por el cual el valor de un contrato (como un alquiler) se ajusta periódicamente según un índice de precios, para mantener el valor real.",
    "Fondo de inversión que cotiza en bolsa y replica el comportamiento de un índice, como el S&P 500. Permite invertir en muchas empresas a la vez con bajo costo.",
    "Saldo disponible en pesos + Fondo de emergencia + Inversiones (pesificadas al momento de calcular el patrimonio real).",
    "Dinero con el que se comienza el juego."
};

#endif