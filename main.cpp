#include <iostream>
#include <string>
#include "libreria.h" // Nuestra librería auxiliar

using namespace std;

// Globales para autoincrementar IDs y evitar que se repitan
int ProcesoIdMemoria = 1;
int OperacionId = 1;
int ProcesoIdCPU = 100; // Los de CPU empiezan en 100 para diferenciarlos

// ==========================================
// ESTRUCTURAS DE TU COMPAÑERO: GESTOR DE MEMORIA (PILA)
// ==========================================
struct Operacion {
    int OperacionId;
    int Espacio;
    string Nombre;    
};

struct Proceso {
    int ProcesoId;
    string Nombre;
    Operacion Ope[100];
    int CantOpe;
    int EspacioTotal;
    Proceso* sge;
    
    Proceso() { sge = NULL; }
    
    Proceso(Proceso &pr) {
        ProcesoId = pr.ProcesoId;
        Nombre = pr.Nombre;
        CantOpe = pr.CantOpe;
        EspacioTotal = pr.EspacioTotal;
        for(int i = 0; i < CantOpe; i++) {
            Ope[i] = pr.Ope[i];
        }
        sge = NULL;
    }
};

struct Pila {
    Proceso* Inicio;
    Proceso* Final;
    int Tamano;
};

bool verificarPila(Pila& p) { return p.Inicio == NULL; }

void inicializarPila(Pila& p) {
    p.Inicio = NULL;
    p.Final = NULL;
    p.Tamano = 0;
}

void asignarMemoria(Pila& p) {
    cout<<"\n=========================\n==Creando nuevo proceso==\n=========================\n";
    Proceso pr;
    pr.Nombre = leerCadena("Ingrese el nombre del proceso : ");
    
    int can = leerEntero("Ingrese la cantidad de operaciones : ");
    float total = 0;
    for(int i=0; i<can; i++){
        cout<<"\t\nOperacion ["<<i+1<<"]\n";
        pr.Ope[i].Nombre = leerCadena("Ingrese el nombre de la operacion : ");
        pr.Ope[i].Espacio = leerEntero("Ingrese la cantidad de espacio (bytes) : ");
        pr.Ope[i].OperacionId = OperacionId++;
        total += pr.Ope[i].Espacio;
    }
    pr.CantOpe = can;
    pr.ProcesoId = ProcesoIdMemoria++;
    pr.EspacioTotal = total;
    
    Proceso* nuevoNodo = new Proceso(pr);
    
    if(verificarPila(p)) {
        p.Inicio = nuevoNodo;
        p.Final = nuevoNodo;
    } else {
        p.Final->sge = nuevoNodo;
        p.Final = nuevoNodo;
        p.Tamano++;
    }
    cout << "\nProceso asignado a la memoria (cima de la pila).\n";
}

void mostrarEstadoMemoria(Pila& p) {
    if (verificarPila(p)) { cout <<"[Pila vacia]\n"; return; }
    Proceso* temp = p.Inicio;
    while(temp != NULL) {
        cout<<"\n=================\n== Proceso N ["<<temp->ProcesoId<<"]== \n=================\n";
        cout<<"Nombre : "<<temp->Nombre<<"\n";
        cout<<"\nLista de operaciones\n";
        for(int i=0; i<temp->CantOpe; i++) {
            cout<<"\tOperacion Id : "<<temp->Ope[i].OperacionId<<"\n";    
            cout<<"\tNombre : "<<temp->Ope[i].Nombre<<"\n";    
            cout<<"\tEspacio : "<<temp->Ope[i].Espacio<<"\n\n";  
        }
        cout<<"Espacio total : "<<temp->EspacioTotal<<"\n";
        if(temp == p.Final) cout<<"\n===================\n==Cima de la pila==\n===================\n";
        temp = temp->sge;
    }
}

void liberarProceso(Pila& p) {
    if (verificarPila(p)) { cout <<"[Pila vacia]\n"; return; }
    if(p.Inicio == p.Final) {
        cout<<"\nProceso "<<p.Inicio->Nombre<<" eliminado correctamente\n";
        cout<<"Se libero correctamente "<<p.Inicio->EspacioTotal<<" bytes\n";
        delete p.Final;
        p.Inicio = NULL; p.Final = NULL;
    } else {
        Proceso* pro = p.Inicio;
        while(pro->sge != p.Final) { pro = pro->sge; }
        cout<<"\nProceso "<<p.Final->Nombre<<" eliminado correctamente\n";
        cout<<"Se libero correctamente "<<p.Final->EspacioTotal<<" bytes\n";
        delete p.Final;
        pro->sge = NULL;
        p.Final = pro;
    }
}

void buscarProceso(Pila& p) {
    if (verificarPila(p)) { cout <<"[Pila vacia]\n"; return; }
    int id = leerEntero("Ingrese el Id del proceso a buscar : ");
    Proceso* pro = p.Inicio;
    Pila temp; inicializarPila(temp);
    while(pro != NULL) {
        if(pro->ProcesoId == id) { temp.Inicio = pro; temp.Final = pro; }
        pro = pro->sge;
    }
    if(temp.Inicio == NULL) cout<<"No se encontro ese proceso\n";
    else mostrarEstadoMemoria(temp);
}

void liberarTodo(Pila& p) {
    if (verificarPila(p)) { cout <<"[Pila vacia]\n"; return; }
    while(!verificarPila(p)) { liberarProceso(p); }
    cout<<"Todos los procesos de la memoria fueron eliminados.\n";
}


// ==========================================
// TÚ MÓDULO: PLANIFICADOR DE CPU (COLA DE PRIORIDAD)
// ==========================================
struct NodoCola {
    int ProcesoId;
    string Nombre;
    int Prioridad;   // Menor número = mayor prioridad (1 es más urgente que 5)
    NodoCola* sge;

    NodoCola() { sge = NULL; }
};

struct Cola {
    NodoCola* Frente;
    NodoCola* Final;
    int Tamano;
};

void inicializarCola(Cola& c) {
    c.Frente = NULL;
    c.Final = NULL;
    c.Tamano = 0;
}

bool verificarCola(Cola& c) { return c.Frente == NULL; }

void encolarProceso(Cola& c) {
    cout << "\n===========================\n== Encolando nuevo proceso ==\n===========================\n";
    NodoCola* nuevo = new NodoCola();
    nuevo->Nombre    = leerCadena("Ingrese el nombre del proceso para CPU: ");
    nuevo->Prioridad = leerEntero("Ingrese la prioridad (1=alta, 5=baja): ");
    nuevo->ProcesoId = ProcesoIdCPU++; 
    nuevo->sge = NULL;

    if (verificarCola(c)) {
        c.Frente = nuevo; c.Final  = nuevo; c.Tamano++;
        cout << "\nProceso encolado correctamente como unico elemento.\n";
        return;
    }

    if (nuevo->Prioridad < c.Frente->Prioridad) {
        nuevo->sge = c.Frente; c.Frente   = nuevo; c.Tamano++;
        cout << "\nProceso encolado al frente por tener maxima prioridad.\n";
        return;
    }

    NodoCola* temp = c.Frente;
    while (temp->sge != NULL && temp->sge->Prioridad <= nuevo->Prioridad) {
        temp = temp->sge;
    }

    nuevo->sge = temp->sge;
    temp->sge  = nuevo;

    if (nuevo->sge == NULL) { c.Final = nuevo; }
    c.Tamano++;
    cout << "\nProceso encolado respetando su rango de prioridad.\n";
}

void desencolarProceso(Cola& c) {
    if (verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    NodoCola* temp = c.Frente;
    cout << "\n================================\n";
    cout << "Ejecutando en CPU: " << temp->Nombre << "\n";
    cout << "ID del Proceso    : " << temp->ProcesoId << "\n";
    cout << "Prioridad          : " << temp->Prioridad << "\n";
    cout << "================================\n";

    c.Frente = c.Frente->sge;
    if (c.Frente == NULL) { c.Final = NULL; }

    delete temp;
    c.Tamano--;
    cout << "Proceso ejecutado y liberado de la CPU.\n";
}

void mostrarCola(Cola& c) {
    if (verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    NodoCola* temp = c.Frente;
    int pos = 1;
    cout << "\n=== Estado actual del Planificador (Cola) ===\n";
    while (temp != NULL) {
        cout << "\n---------------------------\n";
        cout << "Posicion  : " << pos << "\n";
        cout << "ID        : " << temp->ProcesoId << "\n";
        cout << "Nombre    : " << temp->Nombre << "\n";
        cout << "Prioridad : " << temp->Prioridad << " (1=Maximo)\n";
        if (temp == c.Frente) cout << ">>> SIGUIENTE A EJECUTAR (FRENTE) <<<\n";
        temp = temp->sge;
        pos++;
    }
    cout << "\nTotal procesos en cola de CPU: " << c.Tamano << "\n";
}

void ejecutarTodos(Cola& c) {
    if (verificarCola(c)) { cout << "\n[Cola vacia]\n"; return; }
    cout << "\n=== Ejecutando ráfaga completa de procesos ===\n";
    while (!verificarCola(c)) { desencolarProceso(c); }
    cout << "\nTodos los procesos de la CPU fueron completados.\n";
}


// ==========================================
// MENÚS DE NAVEGACIÓN EN CONSOLA
// ==========================================
void mostrarMenu() {
    cout<<"\n==========================================\n";
    cout<<"      SISTEMA OPERATIVO SIMULADO (GRUPO 9)  ";
    cout<<"\n==========================================\n";
    cout<<"1. Gestor de Procesos (Lista Enlazada)\n";
    cout<<"2. Planificador de CPU (Cola de Prioridad)\n";
    cout<<"3. Gestor de Memoria (Pila Dinamica)\n";
    cout<<"4. Salir del Sistema\n";
    cout<<"------------------------------------------\n";
}

void mostrarSubMenu2() {
    cout << "\n====================================\n";
    cout << "    SUB-MENU 02: PLANIFICADOR CPU   ";
    cout << "\n====================================\n";
    cout << "1. Encolar proceso (Por Prioridad)\n";
    cout << "2. Desencolar proceso (Ejecutar siguiente)\n";
    cout << "3. Mostrar cola actual de ejecucion\n";
    cout << "4. Ejecutar ráfaga (Todos los procesos)\n";
    cout << "5. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu3() {
    cout<<"\n====================================\n";
    cout<<"    SUB-MENU 03: GESTOR DE MEMORIA  ";
    cout<<"\n====================================\n";
    cout<<"1. Asignar memoria a proceso\n";
    cout<<"2. Buscar proceso en memoria\n";
    cout<<"3. Liberar ultimo proceso (LIFO)\n";
    cout<<"4. Mostrar mapa de memoria\n";
    cout<<"5. Liberar toda la memoria\n";
    cout<<"6. Volver al Menu Principal\n";
    cout<<"------------------------------------------\n";
}


// ==========================================
// FUNCIÓN PRINCIPAL (MAIN)
// ==========================================
int main() {
    // Inicializamos las estructuras una única vez al arrancar
    Pila memoriaSO;
    inicializarPila(memoriaSO);
    
    Cola cpuSO;
    inicializarCola(cpuSO);
    
    int op;
    do {
        mostrarMenu();
        op = leerEntero("Seleccione un modulo del sistema: ");
        switch(op) {
            case 1:
                cout << "\n[Modulo en desarrollo] Proximamente: Lista Enlazada Simple.\n";
                break;
                
            case 2: { // MODULO DE COLAS (TÚ CODIGO)
                int op2;
                do {
                    mostrarSubMenu2();
                    op2 = leerEntero("Ingrese una opcion : ");
                    switch(op2) {
                        case 1: encolarProceso(cpuSO); break;
                        case 2: desencolarProceso(cpuSO); break;
                        case 3: mostrarCola(cpuSO); break;
                        case 4: ejecutarTodos(cpuSO); break;
                        case 5: cout << "\nRegresando al Menu Principal...\n"; break;
                        default: cout << "\nOpcion invalida.\n"; break;
                    }
                } while(op2 != 5);
                break;
            }
                
            case 3: { // MODULO DE PILAS (TU COMPAÑERO)
                int op3;
                do {
                    mostrarSubMenu3();
                    op3 = leerEntero("Ingrese una opcion : ");
                    switch(op3) {
                        case 1: asignarMemoria(memoriaSO); break;
                        case 2: buscarProceso(memoriaSO); break;
                        case 3: liberarProceso(memoriaSO); break;
                        case 4: mostrarEstadoMemoria(memoriaSO); break;
                        case 5: liberarTodo(memoriaSO); break;
                        case 6: cout<<"\nRegresando al Menu Principal...\n"; break;
                        default: cout<<"\nOpcion invalida.\n"; break;
                    }
                } while(op3 != 6);
                break;
            }
            case 4:
                cout<<"\nApagando sistema operativo simulado. ¡Adios!\n";
                break;
            default:
                cout<<"\nOpcion no valida, intente otra vez.\n";
                break;
        }
    } while(op != 4);
    
    return 0;
}
