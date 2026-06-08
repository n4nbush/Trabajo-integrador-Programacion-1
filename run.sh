#!/bin/bash

# Este script compila el proyecto y luego ejecuta el programa resultante. # borrar al usar en Codeblocks
# Mensaje iniciando compilar 

echo "Compilando el proyecto ..."

if g++ *.cpp -o programa;then
    echo "Compilacion exitosa"

    # Lanza el programa
    ./programa

    #Borra el programa
    rm programa

else 
    echo "❌ Error de compilación. Corrige los errores antes de ejecutar."
fi

