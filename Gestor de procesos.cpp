#include <iostream>
#include <string>
using namespace std;

struct NodoProceso {
    int id;
    string nombre;
    int prioridad;
    NodoProceso* siguiente;
    
    NodoProceso(int _id, string _nombre, int _prioridad) {
        id = _id;
        nombre = _nombre;
        prioridad = _prioridad;
        siguiente = NULL;
    }
};

class GestorProcesos {
private:
    NodoProceso* cabeza;
    
    bool idExiste(int id) {
        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            if(actual->id == id) return true;
            actual = actual->siguiente;
        }
        return false;
    }
    
public:
    GestorProcesos() {
        cabeza = NULL;
    }
    
    void insertarProceso(int id, string nombre, int prioridad) {
        if(prioridad < 1 || prioridad > 10) {
            cout << " La prioridad debe estar entre 1 y 10." << endl;
            return;
        }
        
        if(idExiste(id)) {
            cout << " Ya existe un proceso con este ID " << id << "." << endl;
            return;
        }
        
        if(nombre.empty()) {
            cout << " El nombre no puede estar vacio." << endl;
            return;
        }
        
        NodoProceso* nuevo = new NodoProceso(id, nombre, prioridad);
        
        if(cabeza == NULL) {
            cabeza = nuevo;
        } else {
            NodoProceso* actual = cabeza;
            while(actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        
        cout << " Proceso insertado " << endl;
        cout << "     ID: " << id << " --- Nombre: " << nombre << " --- Prioridad: " << prioridad << endl;
    }
    
    void eliminarProceso(int id) {
        if(cabeza == NULL) {
            cout << " No hay procesos registrados." << endl;
            return;
        }
        
        if(cabeza->id == id) {
            NodoProceso* temp = cabeza;
            cabeza = cabeza->siguiente;
            cout << " Proceso eliminado: " << temp->nombre << " (ID: " << id << ")" << endl;
            delete temp;
            return;
        }
        
        NodoProceso* actual = cabeza;
        while(actual->siguiente != NULL && actual->siguiente->id != id) {
            actual = actual->siguiente;
        }
        
        if(actual->siguiente == NULL) {
            cout << " No se encontro un proceso con ID " << id << "." << endl;
        } else {
            NodoProceso* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            cout << " Proceso eliminado: " << temp->nombre << " (ID: " << id << ")" << endl;
            delete temp;
        }
    }
    
    void buscarPorID(int id) {
        if(cabeza == NULL) {
            cout << " No hay procesos registrados." << endl;
            return;
        }
        
        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            if(actual->id == id) {
                cout << "proceso encontrado" << endl;
                cout << "  ID: " << actual->id << " --- Nombre: " << actual->nombre << " --- Prioridad: " << actual->prioridad << endl;
                return;
            }
            actual = actual->siguiente;
        }
        
        cout << " No se encontro un proceso con ID " << id << "." << endl;
    }
    
    void modificarPrioridad(int id, int nuevaPrioridad) {
        if(cabeza == NULL) {
            cout << " No hay procesos registrados." << endl;
            return;
        }
        
        if(nuevaPrioridad < 1 || nuevaPrioridad > 10) {
            cout << " La prioridad debe estar entre 1 y 10." << endl;
            return;
        }
        
        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            if(actual->id == id) {
                cout << " Prioridad modificada." << endl;
                cout << "  Proceso: " << actual->nombre << endl;
                cout << " Prioridad anterior: " << actual->prioridad << endl;
                cout << "  Nueva prioridad: " << nuevaPrioridad << endl;
                actual->prioridad = nuevaPrioridad;
                return;
            }
            actual = actual->siguiente;
        }
        
        cout << " No se encontro un proceso con ID " << id << "." << endl;
    }
    
    void mostrarTodos() {
        if(cabeza == NULL) {
            cout << " Lista de procesos VACIA." << endl;
            return;
        }
        
        cout << "LISTA DE PROCESOS" << endl;
        
        NodoProceso* actual = cabeza;
        int contador = 1;
        
        while(actual != NULL) {
            cout << contador++ << ". ID: " << actual->id 
                 << "  Nombre: " << actual->nombre 
                 << "  Prioridad: " << actual->prioridad;
            
            if(actual->prioridad >= 7) cout << " [ALTA]";
            else if(actual->prioridad <= 3) cout << " [BAJA]";
            
            cout << endl;
            actual = actual->siguiente;
        }
        
        cout << "Total de procesos: " << contador - 1 << endl;
        
        actual = cabeza;
        int sumaPrioridades = 0;
        while(actual != NULL) {
            sumaPrioridades += actual->prioridad;
            actual = actual->siguiente;
        }
        cout << "Prioridad promedio: " << (float)sumaPrioridades / (contador - 1) << endl;
    }
    
    ~GestorProcesos() {
        NodoProceso* actual = cabeza;
        while(actual != NULL) {
            NodoProceso* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

int main() {
    GestorProcesos gp;
    int opcion, id, prioridad, nuevaPrioridad;
    string nombre;
    
    do {
        system("cls");
        cout << " GESTOR DE PROCESOS" << endl;
        cout << "1. Insertar proceso" << endl;
        cout << "2. Eliminar proceso" << endl;
        cout << "3. Buscar por ID" << endl;
        cout << "4. Modificar prioridad" << endl;
        cout << "5. Mostrar todos los procesos" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Prioridad (1-10): "; cin >> prioridad;
                gp.insertarProceso(id, nombre, prioridad);
                system("pause");
                break;
                
            case 2:
                cout << "ID del proceso a eliminar: "; cin >> id;
                gp.eliminarProceso(id);
                system("pause");
                break;
                
            case 3:
                cout << "ID a buscar: "; cin >> id;
                gp.buscarPorID(id);
                system("pause");
                break;
                
            case 4:
                cout << "ID del proceso: "; cin >> id;
                cout << "Nueva prioridad (1-10): "; cin >> nuevaPrioridad;
                gp.modificarPrioridad(id, nuevaPrioridad);
                system("pause");
                break;
                
            case 5:
                gp.mostrarTodos();
                system("pause");
                break;
                
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
                
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
                break;
        }
        
    } while(opcion != 6);
    
    return 0;
}
