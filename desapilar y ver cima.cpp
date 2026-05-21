#include <iostream>
#include <string>
using namespace std;

//nodo
struct Nodo {
    string dato;  // URL de la pagina visitada
    Nodo* sge;    // puntero al siguiente nodo
};

// -pila
struct Pila {
    Nodo* inicio; // apunta al primer nodo
    Nodo* cima;   // apunta al ultimo nodo (tope de la pila)
    int   tam;
};

//  Inicializar pila vacia 
void inicializar(Pila& p) {
    p.inicio = NULL;
    p.cima   = NULL;
    p.tam    = 0;
}

// Verificar si la pila esta vacia 
bool estaVacia(Pila& p) {
    return p.inicio == NULL;
}

//  Insertar elemento en la parte superior - APILAR (push) ----

void apilar(Pila& p, string url) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = url;
    nuevo->sge  = NULL;

    if (estaVacia(p)) {
        p.inicio = nuevo;
        p.cima   = nuevo;
    } else {
        p.cima->sge = nuevo; // el antiguo ultimo apunta al nuevo
        p.cima      = nuevo; // la cima ahora es el nuevo nodo
    }
    p.tam++;
    cout << "  >> Visitaste: " << url << endl;
}

//  Ver elemento superior (peek) sin eliminar
string verCima(Pila& p) {
    if (estaVacia(p)) return "(pila vacia)";
    return p.cima->dato;
}

//  Eliminar elemento de la parte superior - DESAPILAR (pop) ----
// Se elimina el ULTIMO nodo (la cima)
string desapilar(Pila& p) {
    if (estaVacia(p)) {
        cout << "  [!] No hay paginas en el historial." << endl;
        return "";
    }

    string paginaSaliente;
     //condicionales para convalidar
    // En el de Caso: solo  si hay un nodo
    if (p.inicio == p.cima) {
        paginaSaliente = p.cima->dato;
        delete p.cima;
        p.inicio = NULL;
        p.cima   = NULL;
    } else {
        // Recorrer hasta el penultimo nodo
        Nodo* actual = p.inicio;
        while (actual->sge != p.cima) {
            actual = actual->sge;
        }
        paginaSaliente  = p.cima->dato;
        delete p.cima;
        actual->sge = NULL;
        p.cima      = actual; // la nueva cima es el penultimo
    }
    p.tam--;
    return paginaSaliente;
}

/
