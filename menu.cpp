#include <iostream>
#include <string>
#include "libreria.h"
using namespace std;

// MENUS DE NAVEGACION

void mostrarMenu() {
    cout << "\n==========================================\n";
    cout << "    SISTEMA OPERATIVO SIMULADO (GRUPO 9)  ";
    cout << "\n==========================================\n";
    cout << "1. Gestor de Procesos (Lista Enlazada)\n";
    cout << "2. Planificador de CPU (Cola de Prioridad)\n";
    cout << "3. Gestor de Memoria (Pila Dinamica)\n";
    cout << "4. Salir del Sistema\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu1() {
    cout << "\n====================================\n";
    cout << "  SUB-MENU 01: GESTOR DE PROCESOS  ";
    cout << "\n====================================\n";
    cout << "1. Insertar proceso\n";
    cout << "2. Eliminar proceso\n";
    cout << "3. Buscar por ID\n";
    cout << "4. Modificar prioridad\n";
    cout << "5. Mostrar todos los procesos\n";
    cout << "6. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu2() {
    cout << "\n====================================\n";
    cout << "   SUB-MENU 02: PLANIFICADOR CPU   ";
    cout << "\n====================================\n";
    cout << "1. Encolar proceso (Por Prioridad)\n";
    cout << "2. Desencolar proceso (Ejecutar siguiente)\n";
    cout << "3. Mostrar cola actual de ejecucion\n";
    cout << "4. Ejecutar rafaga (Todos los procesos)\n";
    cout << "5. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

void mostrarSubMenu3() {
    cout << "\n====================================\n";
    cout << "   SUB-MENU 03: GESTOR DE MEMORIA  ";
    cout << "\n====================================\n";
    cout << "1. Asignar memoria a proceso\n";
    cout << "2. Buscar proceso en memoria\n";
    cout << "3. Liberar ultimo proceso (LIFO)\n";
    cout << "4. Mostrar mapa de memoria\n";
    cout << "5. Liberar toda la memoria\n";
    cout << "6. Volver al Menu Principal\n";
    cout << "------------------------------------------\n";
}

int main()
{
	int op;
	do
	{
		mostrarMenu();
		op = leerEntero("Ingrese una opcion : ");
		switch(op)
		{
			case 1:
				int op1;
				do
				{
					mostrarSubMenu1();
					op1 = leerEntero("Ingrese una opcion : ");
					switch(op1)
					{
						case 6:
							cout<<"\nSaliendo del SubMenu Nº03\n";
							break;
						default:
							cout<<"\nOpcion no valida, ingrese otra\n";
							break;
					}
				}while(op1 !=6);
				break;
			case 2:
				int op2;
				do
				{
					mostrarSubMenu2();
					op2 = leerEntero("Ingrese una opcion : ");
					switch(op2)
					{
						case 6:
							cout<<"\nSaliendo del SubMenu Nº03\n";
							break;
						default:
							cout<<"\nOpcion no valida, ingrese otra\n";
							break;
					}
				}while(op2 !=5);
				break;
			case 3:
			
				int op3;
				do
				{
					mostrarSubMenu3();
					op3 = leerEntero("Ingrese una opcion : ");
					switch(op3)
					{
						case 6:
							cout<<"\nSaliendo del SubMenu Nº03\n";
							break;
						default:
							cout<<"\nOpcion no valida, ingrese otra\n";
							break;
					}
				}while(op3 !=6);
				break;
			case 4:
				cout<<"\nCerrando programa\n";
				break;
			default:
				cout<<"\nOpcion no valida, ingrese otra\n";
				break;
		}
	}while(op!=4);
	return 0;
}
