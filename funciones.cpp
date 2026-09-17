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
        cout << "direccion" << &cadena <<endl;
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

void leerMatriz(int *matriz, int n) {                  // ejercisio 12

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << "Ingrese [" << i << "][" << j << "]: ";
            cin >> *(matriz + i * n + j);
        }
    }
}


void imprimirMatriz(int *matriz, int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << *(matriz + i * n + j) << "\t";
        }

        cout << endl;
    }
}


bool esMagico(int *matriz, int n) {

    int constante = 0;

    // Suma de la primera fila
    for (int j = 0; j < n; j++) {
        constante = constante + *(matriz + j);
    }


    // Comprobar las filas
    for (int i = 0; i < n; i++) {

        int suma = 0;

        for (int j = 0; j < n; j++) {
            suma = suma + *(matriz + i * n + j);
        }

        if (suma != constante) {
            return false;
        }
    }


    // Comprobar las columnas
    for (int j = 0; j < n; j++) {

        int suma = 0;

        for (int i = 0; i < n; i++) {
            suma = suma + *(matriz + i * n + j);
        }

        if (suma != constante) {
            return false;
        }
    }


    // Diagonal principal
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma = suma + *(matriz + i * n + i);
    }

    if (suma != constante) {
        return false;
    }


    // Diagonal secundaria
    suma = 0;

    for (int i = 0; i < n; i++) {
        suma = suma + *(matriz + i * n + (n - 1 - i));
    }

    if (suma != constante) {
        return false;
    }

    return true;
}


void llenarMatriz(int *matriz) {                  // ejercisio 14

    int numero = 1;

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            *(matriz + i * 5 + j) = numero;

            numero++;
        }
    }
}


void imprimirMatriz(int *matriz) {

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            cout << *(matriz + i * 5 + j) << "\t";
        }

        cout << endl;
    }
}


void rotarMatriz(int *original, int *rotada, int grados) {

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if (grados == 90) {

                *(rotada + i * 5 + j) =
                    *(original + (4 - j) * 5 + i);
            }

            else if (grados == 180) {

                *(rotada + i * 5 + j) =
                    *(original + (4 - i) * 5 + (4 - j));
            }

            else if (grados == 270) {

                *(rotada + i * 5 + j) =
                    *(original + j * 5 + (4 - i));
            }
        }
    }
}

long long factorial(int *numero)                   // Ejercisio 16
{
    long long resultado = 1;

    for (int i = 1; i <= *numero; i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}

long long calcularCaminos(int *n)
{
    int total = 2 * (*n);

    long long factTotal = factorial(&total);
    long long factN = factorial(n);

    long long caminos = factTotal / (factN * factN);

    return caminos;
}


void inicializar(int *numeros, int *tamano)
{
    for (int i = 0; i < *tamano; i++)
    {
        *(numeros + i) = i;
    }
}

long long factorial_2(int *numero)
{
    long long resultado = 1;

    for (int i = 1; i <= *numero; i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}

void encontrarPermutacion(long long *n, int *numeros, int *tamano, int *resultado)
{
    long long posicion = *n - 1;

    for (int i = 0; i < *tamano; i++){

        int restante = *tamano - i - 1;
        long long cantidad = factorial_2(&restante);
        int posicionNumero = posicion / cantidad;
        posicion = posicion % cantidad;

        *(resultado + i) = *(numeros + posicionNumero);

        for (int j = posicionNumero; j < *tamano - i - 1; j++) {
            *(numeros + j) = *(numeros + j + 1);
        }
    }
}





