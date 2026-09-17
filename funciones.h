#ifndef FUNCIONES_H
#define FUNCIONES_H

void generarEImprimir(char *arreglo);
void contarLetras(char *arreglo);

int convertirNumero(char *cadena);

void convertirMayusculas(char *cadena);

void separar(char *original, char *texto, char *numeros);

int romanoArabigo(char *romano);

void leerMatriz(int *matriz, int n);
void imprimirMatriz(int *matriz, int n);
bool esMagico(int *matriz, int n);


void llenarMatriz(int *matriz);
void imprimirMatriz(int *matriz);
void rotarMatriz(int *original, int *rotada, int grados);

long long factorial(int *numero);
long long calcularCaminos(int *n);

#endif
