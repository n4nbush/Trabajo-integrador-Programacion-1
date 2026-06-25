#include <iostream>
#include "juego.h"
#include "menu.h"
#include "constantes.h"
#include "finanzas.h"
using namespace std;

/// primer funcion para el punto 1
void nuevaPartida(const string meses[]){
    string nombreJugador;
    int rondas = 0;

    limpiar_pantalla();

    cin.ignore(1000, '\n');

    cout << "Ingrese su nombre completo: ";
    getline(cin, nombreJugador);

    while(rondas < 1 || rondas > 12){
        limpiar_pantalla();

        cout << "Bienvenido " << nombreJugador << endl;
        cout << "Cuantas rondas queres jugar (1 minimo y un maximo de 12): ";
        cin >> rondas;

        if(rondas < 1 || rondas > 12){
            cout << "Cantidad invalida. Debe ser entre 1 y 12 meses." << endl;
            cout << "Presione cualquier tecla para continuar...";
            pausar();
        }
    }

    cout << "Perfecto seleccionaste la cantidad de " << rondas << " meses" << endl;
    pausar();

    float alquiler = 180000;
    float servicios = 45000;
    float transporte = 30000;
    float alimentacion = 80000;
    float gastosFijos = 0;
    float sueldo = 500000;
    float sobrante_de_plata = 150000;
    float dolares = 0;
    float bitcoin = 0;
    float sp500 = 0;
    float aguinaldo = 0;
    float fondo_emergencia = 0;
    float capital_invertir = 0;
    float valor_dolar = 1000;
    float valor_bitcoin = 60000;
    float valor_sp500 = 650;
    float max_gastos = 0;
    float max_ahorro = 0;
    float acumulador_inflacion = 1.0;
    int meses_rojo = 0;
    float limite_superior = 150000*1.10;
    float limite_inferior = 150000*0.90;
    float pesos;


    string mes_max_gastos, mes_max_ahorro;

    
    for(int i = 1; i <= rondas; i++){
        limpiar_pantalla();
        
        bool cobrar_aguinaldo = false;
        
        gastosFijos = alquiler + servicios + transporte + alimentacion;
        sobrante_de_plata = (sueldo - gastosFijos)+pesos;
        float gastos = 0, ahorros = 0;
        gastos = gastosFijos;
        ahorros = 0;

        if(i % 6 == 0){
            cobrar_aguinaldo = true;
            aguinaldo = sueldo / 2;
        }

        if(cobrar_aguinaldo){
            sobrante_de_plata += aguinaldo;
        }

        string evento = "";
        string evento_descripcion = "";

        eventos(i, sobrante_de_plata, sueldo, alquiler, evento, evento_descripcion,gastos,valor_bitcoin);

        cout << "=======================================================" << endl;
        cout << i << "/" << rondas << " - " << meses[i-1]
             << "               Jugador: " << nombreJugador << endl;
        cout << "=======================================================" << endl;

        cout << "TENENCIAS ACTUALES: " << endl;
        cout << "Disponible en pesos: $" << int(sobrante_de_plata) << endl;
        cout << "Fondo de emergencia: $" << int(fondo_emergencia) << endl;
        cout << "Dolares: USD " << int(dolares) << " ($" << int(dolares * valor_dolar) << ")" << endl;
        cout << "Bitcoin: " << bitcoin << " BTC ($" << int(bitcoin * valor_bitcoin * valor_dolar) << ")" << endl;
        cout << "S&P 500: " << sp500 << " ETF ($" << int(sp500 * valor_sp500 * valor_dolar) << ")" << endl;
        cout << endl;

        cout << "-------------------------------------------------------" << endl;
        cout << "Sueldo del mes: $" << int(sueldo) << endl;
        cout << "Gastos fijos: $" << int(gastosFijos) << endl;
        cout << "Valor dolar: $" << int(valor_dolar) << endl;
        cout << "Valor Bitcoin: USD " << int(valor_bitcoin) << endl;
        cout << "Valor S&P 500: USD " << int(valor_sp500) << endl;

        if(cobrar_aguinaldo){
            cout << "Este mes cobraste aguinaldo: $" << int(aguinaldo) << endl;
        }

        cout << "=======================================================" << endl;

        cout << "Eventos: " << endl;
        if(evento.length() != 0 && evento_descripcion.length() != 0){
            cout << evento << endl;
            cout << evento_descripcion << endl << endl;
        }
        else{
            cout << "No hubo eventos fijos este mes." << endl << endl;
        }

        eventos_aleatorios(sobrante_de_plata,gastos);

        string texto = "Sobrante actualizado: $" + to_string(int(sobrante_de_plata));
        enmarcar_texto(texto);

        cout << "Presione cualquier tecla para continuar...";
        pausar();
        limpiar_pantalla();

        distribuir_sobrante(
            sobrante_de_plata,
            fondo_emergencia,
            capital_invertir,
            dolares,
            bitcoin,
            sp500,
            valor_dolar,
            valor_bitcoin,
            valor_sp500,
            ahorros
        );

        cout << endl << endl;
        cout << "Fondo de emergencia actual: $" << int(fondo_emergencia) << endl;
        cout << "Capital para invertir acumulado: $" << int(capital_invertir) << endl;

        cout << endl << "Presione cualquier tecla para continuar...";
        pausar();
        limpiar_pantalla();

        servicios *= 1.07;
        transporte *= 1.07;
        alimentacion *= 1.07;

        valor_dolar *= 1.05;
        if (i%2==0){
            valor_bitcoin *= 1.25;
        }else{
            valor_bitcoin *= 0.80;
        }
        valor_sp500 *= 1.01;

        if (meses_rojo==2){
            limpiar_pantalla();
            cout << "=========================" << endl;
            cout << "        GAME OVER        " << endl;
            cout << "=========================" << endl;
            cout << "Tuviste 3 meses seguidos en rojo." << endl;
            pausar();
            i=rondas;
        }else if (sobrante_de_plata<0){
            meses_rojo++;
        }
        
        if (gastos>max_gastos){
            max_gastos = gastos;
            mes_max_gastos = meses[i-1];
        }
        if (ahorros>max_ahorro){
            max_ahorro= ahorros;
            mes_max_ahorro = meses[i-1];
        }
        acumulador_inflacion = acumulador_inflacion*1.07;

        pesos = sobrante_de_plata;

    }

    float inflacion_acumulada;
    inflacion_acumulada = (acumulador_inflacion-1)*100;
    inflacion_acumulada = ((int)(inflacion_acumulada*100))/100.0;
    float patrimonio_real = (sobrante_de_plata + (dolares * valor_dolar) + (bitcoin * valor_bitcoin * valor_dolar) + (sp500 * valor_sp500 * valor_dolar)) / acumulador_inflacion;    
    patrimonio_real = ((int)(patrimonio_real * 100)) / 100.0;
    limpiar_pantalla();
    separador();
    cout << "Pantalla final" << endl;
    separador();
    
    cout << "Capital post partida" << endl;
    cout << "Patrimonio"<< endl;
    separador();
    cout << "Pesos: $ " << sobrante_de_plata << endl;
    cout << "Dolares: USD " << int(dolares) << " ($" << int(dolares * valor_dolar) << ")" << endl;
    cout << "Bitcoin: " << bitcoin << " BTC ($" << int(bitcoin * valor_bitcoin * valor_dolar) << ")" << endl;
    cout << "S&P 500: " << sp500 << " ETF ($" << int(sp500 * valor_sp500 * valor_dolar) << ")" << endl;
    separador();
    cout << "Mes con mas gastos: " << mes_max_gastos << endl;
    cout << "Cantidad gastada: $" << max_gastos << endl;
    separador();
    cout << "Mes con mas ahorros: " << mes_max_ahorro << endl;
    cout << "Cantidad ahorrada: $" << max_ahorro << endl;
    separador();
    cout << "Inflacion acumulada en la partida: %" << inflacion_acumulada << endl;
    separador();
    cout << "Patrimonio real: $" << patrimonio_real << " Pesos"<<endl ;

    if (patrimonio_real >= limite_inferior && patrimonio_real <= limite_superior) {
    cout << "Resultado: Lograste mantener estable tu patrimonio (Empate)." << endl;
    } 
    else if (patrimonio_real > limite_superior) {
        cout << "Resultado: ¡Excelente! Le ganaste a la inflacion." << endl;
    } 
    else {
        cout << "Resultado: La inflacion licuo tus ahorros. Perdiste poder adquisitivo." << endl;
    }

    pausar();
}
