#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

const std::string MESES[12] = {
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
};


// =============== Eventos Inprovistos ===========

const int CANTIDAD_EVENTOS_ALEATOREOS = 12;

const std::string NOMBRES_EVENTOS_ALEATOREOS[CANTIDAD_EVENTOS_ALEATOREOS]{
    "Se rompe el lavarropas",
    "Visita médica inesperada",
    "Multa de tránsito",
    "Técnico de internet",
    "Regalo de cumpleanios obligado",
    "Rompiste un vidrio del gimnasio",
    "Cena o salida social ineludible",
    "Se rompe la pantalla del celular",
    "Sube la expensa del edificio",
    "Mini escapada de último momento",
    "Black Friday - una oferta irresistible",
    "Regalos de fin de año",
};

const std::string DESCRIPCION_EVENTOS_ALEATOREOS[CANTIDAD_EVENTOS_ALEATOREOS]{
    "Reparacion urgente de electrodomestico",
    "Consulta + medicamentos",
    "Infraccion de transito",
    "Se cortó el servicio, hay que llamar al técnico",
    "Ese amigo que siempre se acuerda del tuyo",
    "Te toca hacerte cargo",
    "Evento social al que no podes faltar",
    "Reparación que no puede esperar",
    "Ajuste por inflación en el edificio",
    "Esas vacaciones que salieron baratas",
    "Decisión optativa: compras o lo dejas pasar",
    "Navidad y año nuevo juntos",
};

const int IMPACTO_ECONOMICO_EVENTOS_ALEATOREOS[CANTIDAD_EVENTOS_ALEATOREOS]{
    70000,
    45000,
    30000,
    25000,
    35000,
    55000,
    50000,
    80000,
    20000,
    90000,
    60000,
    55000,
};

// =============== Glosario Financiero ===========

const int CANTIDAD_TITULOS_GLOSARIO = 12;

const std::string GLOSARIO_TITULOS[CANTIDAD_TITULOS_GLOSARIO]{
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

const std::string GLOSARIO_DEFINICIONES[CANTIDAD_TITULOS_GLOSARIO]{
    "Aumento generalizado y sostenido de los precios de bienes y servicios. Hace que el dinero valga menos con el tiempo.",
    "Cantidad de bienes y servicios que se pueden comprar con una suma de dinero. Disminuye cuando hay inflación.",
    "El salario nominal es el número en el recibo de sueldo. El salario real mide cuánto se puede comprar con ese dinero. Si la inflación supera al aumento del sueldo, el salario real cae.",
    "Reserva de dinero en efectivo o cuenta disponible para cubrir gastos imprevistos sin necesidad de endeudarse ni vender inversiones.",
    "Estrategia de distribuir el dinero entre distintos instrumentos para reducir el riesgo total. No poner todos los huevos en la misma canasta.",
    "El valor de la mejor alternativa que se resigna al tomar una decisión. Guardar plata en pesos tiene el costo de oportunidad de no invertirla.",
    "Medida de cuánto varía el precio de un activo. Un instrumento muy volátil como el Bitcoin puede subir o bajar mucho en poco tiempo.",
    "Facilidad con la que un activo se puede convertir en dinero disponible. El efectivo es el activo más líquido; los inmuebles, el menos.",
    "Mecanismo por el cual el valor de un contrato como un alquiler se ajusta periódicamente según un índice de precios para mantener el valor real.",
    "Fondo de inversión que cotiza en bolsa y replica el comportamiento de un índice como el S&P 500. Permite invertir en muchas empresas a la vez con bajo costo.",
    "Saldo disponible en pesos + fondo de emergencia + inversiones pesificadas al momento de calcular el patrimonio real.",
    "Dinero con el que se comienza el juego."
};

#endif
