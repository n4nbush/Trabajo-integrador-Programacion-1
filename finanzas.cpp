#include<iostream>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para time()


void eventos(int mes, int sobrante_de_plata, int sueldo, int alquiler){


    if (mes == 1){
        std::cout << "Deposito de garantia"<< std::endl;
        sobrante_de_plata = sobrante_de_plata - 180000;

    }
    else if (mes==3 || mes == 6 || mes == 9){
        std::cout << "Aumento de sueldo por paritarias" << std::endl;
        sueldo*=1.15;
    }
    else if (mes == 9){
        std::cout << "Actualización del alquiler" << std::endl;
        alquiler *= 1.4;

    }

}


void eventos_aleatorios(){
    srand(time(0)); 

    if (rand() % 100 < 70) {
        std::cout << "¡Éxito! (70% de probabilidad)" << std::endl;
    } else {
        std::cout << "Fallo (30% de probabilidad)" << std::endl;
    }
}





