#include <iostream>
#include "funciones.h"

using namespace std;

int main() {

    int opcion;
    do {

    cout << "Ingrese el numero del problema: ";
    cin >> opcion;

    switch (opcion) {

    case 2: {
        char arreglo[200];

        srand(time(0));

        cout << "Arreglo generado:" << endl;
         generarEImprimir(arreglo);

        contarLetras(arreglo);
        break;
    }


    case 4: {
        char cadena[100];
        cout << "Ingrese una cadena de numeros: ";
        cin >> cadena;

        int resultado = convertirNumero(cadena);
        cout << "El numero es: " << resultado << endl;

        break;
    }

    case 6: {
        char cadena[100];

        cout << "Ingrese una cadena de caracteres: ";
        cin >> cadena;

        cout << "Original: " << cadena << endl;

        convertirMayusculas(cadena);
        cout << "En mayuscula: " << cadena << endl;

        break;
    }

    case 8: {

    char original[100];
    char texto[100];
    char numeros[100];

    cout << "Ingrese una cadena: ";
    cin >> original;

    separar(original, texto, numeros);

    cout << "Original: " << original << "." << endl;
    cout << "Texto: " << texto << "." << endl;
    cout << "Numero: " << numeros << "." << endl;
    break;
    }

    case 10: {
        char romano[100];

        cout << "Ingrese un numero romano: ";
        cin >> romano;

        int resultado = romanoArabigo(romano);

        cout << "El numero ingresado fue: " << romano << endl;
        cout << "Que corresponde a: " << resultado << endl;

        break;

    }

    case 0:{
        cout << "Saliendo del programa" << endl;
        break;
    }

    default:
        cout << "Problema no valido." << endl;
    }
}
    while (opcion!=0);
    return 0;

}


