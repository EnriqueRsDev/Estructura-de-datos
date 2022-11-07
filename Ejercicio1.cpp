#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 3;
    int VALORES[n];
    int indice;
    int valor_nuevo;

    //Ingresando datos
    for (size_t i = 0; i < n; i++)
    {
        printf("Ingresa un numero entero: ");
        cin >> VALORES[i];
    }

    //Imprimiendo datos
    printf("Valores ingresados: \n");

    for (size_t i = 0; i < n; i++)
    {
        printf("%d - %d \n", i + 1, VALORES[i]);
    }
    
    //Seleccionando el dato a cambiar
    printf("Escribe el indice del valor que deseas cambiar: ");
    cin >> indice;
    
    printf("Ingresa el nuevo valor: ");
    cin >> valor_nuevo;

    //Cambiando el valor seleccionado ppor el nuevo valor ingresado
    VALORES[indice - 1] = valor_nuevo;

    for (size_t i = 0; i < n; i++)
    {
        printf("%d - %d \n", i + 1, VALORES[i]);
    }

    return 0;
}

