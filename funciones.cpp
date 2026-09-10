#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarEImprimir(char *arreglo) {                               //2 problema
    for (char* ptr = arreglo; ptr < arreglo + 200; ptr++) {
        *ptr = 'A' + rand() % 26;
        cout << *ptr;
    }
    cout << endl << endl;
}

void contarLetras(char *arreglo) {
    for (char letra = 'A'; letra <= 'Z'; letra++) {
        int contador = 0;

        for (char* ptr = arreglo; ptr < arreglo + 200; ptr++) {
            if (*ptr == letra) {
                contador++;
            }
        }

        cout << letra << ": " << contador << endl;
    }
}


int convertirNumero(char *cadena){           // 4 problema
    int numero = 0;
    while (*cadena != '\0') {
        numero = numero * 10 + (*cadena - '0');
        cadena++;
    }
    return numero;
}

void convertirMayusculas(char *cadena) {      // 6 problema
    while (*cadena != '\0') {
        if (*cadena >= 'a' && *cadena <= 'z'){
            *cadena = *cadena - ('a' - 'A');
        }
        cadena++;
    }
}

void separar(char *original, char *texto, char *numeros){     // 8 problema
    int i = 0; int j = 0; int k = 0;
    while (*(original + i) != '\0') {
        if (*(original + i) >= '0' && *(original + i) <= '9') {
            *(numeros + j) = *(original + i); j++;
        }
        else {
            *(texto + k) = *(original + i); k++;
        } i++;
    } *(numeros + j) = '\0'; *(texto + k) = '\0';
}

int romanoArabigo(char *romano){              // 10 problema

    int total = 0;

    while (*romano != '\0') {

        int actual;
        int siguiente;

        if (*romano == 'M')
            actual = 1000;
        else if (*romano == 'D')
            actual = 500;
        else if (*romano == 'C')
            actual = 100;
        else if (*romano == 'L')
            actual = 50;
        else if (*romano == 'X')
            actual = 10;
        else if (*romano == 'V')
            actual = 5;
        else
            actual = 1;

        if (*(romano + 1) == 'M')
            siguiente = 1000;
        else if (*(romano + 1) == 'D')
            siguiente = 500;
        else if (*(romano + 1) == 'C')
            siguiente = 100;
        else if (*(romano + 1) == 'L')
            siguiente = 50;
        else if (*(romano + 1) == 'X')
            siguiente = 10;
        else if (*(romano + 1) == 'V')
            siguiente = 5;
        else if (*(romano + 1) == 'I')
            siguiente = 1;
        else
            siguiente = 0;

        if (actual < siguiente)
            total = total - actual;
        else
            total = total + actual;

        romano++;
    }

    return total;
}