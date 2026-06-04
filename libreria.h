#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Función para leer números enteros de forma segura sin que se rompa la consola
inline int leerEntero(string mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        if (cin >> numero) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero;
        }
        cout << "[Error] Por favor, ingrese un numero valido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Función para leer texto (strings) con espacios incluidos
inline string leerCadena(string mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    return texto;
}

#endif
#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Función para leer números enteros de forma segura sin que se rompa la consola
inline int leerEntero(string mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        if (cin >> numero) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero;
        }
        cout << "[Error] Por favor, ingrese un numero valido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Función para leer texto (strings) con espacios incluidos
inline string leerCadena(string mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    return texto;
}

#endif
