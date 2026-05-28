#include <iostream>
#include <string>
#include "libreria.h"
using namespace std;


/*Gestor de memoria*/


int ProcesoId = 1;
int OperacionId = 1;

struct Operacion
{
	int OperacionId;
	int Espacio;
	string Nombre;	
};

struct Proceso
{
	int ProcesoId;
	string Nombre;
	Operacion Ope[100];
	int CantOpe;
	int EspacioTotal;
	Proceso* sge;
	
	Proceso()
	{
		sge = NULL;
	}
	
	Proceso(Proceso &pr)
	{
		ProcesoId = pr.ProcesoId;
		Nombre = pr.Nombre;
		CantOpe = pr.CantOpe;
		EspacioTotal = pr.EspacioTotal;
		for(int i = 0; i < CantOpe; i++)
        {
            Ope[i] = pr.Ope[i];
        }
        sge = NULL;
	}
};

struct Pila
{
	Proceso* Inicio;
	Proceso* Final;
	int Tamano;
};

bool verificarPila(Pila& p) {
    return p.Inicio == NULL;
}

void asignarMemoria(Pila& p)
{
	cout<<"\n=========================\n";
	cout<<"==Creando nuevo proceso==";
	cout<<"\n=========================\n";
	
    Proceso pr;
    pr.Nombre = leerCadena("Ingrese el nombre del proceso : ");
    
    int can;
    float total =0;
    can = leerEntero("Ingrese la cantidad de operaciones : ");
    for(int i=0;i<can;i++){
        cout<<"\t\nOperacion ["<<i+1<<"]\n";
        /*cin.ignore();*/
        pr.Ope[i].Nombre = leerCadena("Ingrese el nombre de la operacion : ");
        pr.Ope[i].Espacio = leerEntero("Ingrese la cantidad de espacio : ");
        pr.Ope[i].OperacionId = OperacionId++;
        total += pr.Ope[i].Espacio;
    }
	pr.CantOpe = can;
    pr.ProcesoId = ProcesoId++;
    pr.EspacioTotal = total;
    
    Proceso* nuevoNodo = new Proceso(pr);
	
	if(verificarPila(p))
	{
		p.Inicio = nuevoNodo;
		p.Final = nuevoNodo;
	}else{
		p.Final->sge = nuevoNodo;
		p.Final = nuevoNodo;
		p.Tamano++;
	}
}

void mostrarEstadoMemoria(Pila& p)
{
	if (verificarPila(p)) {
        cout <<"[Pila vacia]\n";
        return;
    }
    Proceso* temp = p.Inicio;
    
    while(temp != NULL)
    {
        cout<<"\n=================\n== Proceso N ["<<temp->ProcesoId<<"]== \n=================\n";
        cout<<"Nombre : "<<temp->Nombre<<"\n";
        cout<<"\nLista de operaciones\n";
        for(int i=0;i<temp->CantOpe;i++)
        {
        	cout<<"\tOperacion Id : "<<temp->Ope[i].OperacionId<<"\n";    
            cout<<"\tNombre : "<<temp->Ope[i].Nombre<<"\n";    
            cout<<"\tEspacio : "<<temp->Ope[i].Espacio<<"\n";  
            cout<<"\n";
        }
        cout<<"Espacio total : "<<temp->EspacioTotal<<"\n";
        if(temp == p.Final)
    	{
    		cout<<"\n===================";
    		cout<<"\n==Cima de la pila==\n";
    		cout<<"===================\n";
		}
        temp = temp->sge;
    }
    cout<<"\n";
}

void liberarProceso(Pila& p)
{
	if (verificarPila(p)) {
        cout <<"[Pila vacia]\n";
        return;
    }
    
	if(p.Inicio == p.Final)
	{
		cout<"\n";
		cout<<"Proceso "<<p.Inicio->Nombre<<" eliminado correctamente\n";
		cout<<"Se libero correctamente "<<p.Inicio->EspacioTotal<<" bytes\n";
		delete p.Final;
		p.Inicio = NULL;
		p.Final = NULL;
	}else
	{
		Proceso* pro = p.Inicio;
		while(pro->sge != p.Final)
		{
			p.Inicio = p.Inicio->sge;
		}
		delete p.Final;
		pro->sge = NULL;
		p.Final = pro;
	}
}

void buscarProceso(Pila& p)
{
	if (verificarPila(p)) {
        cout <<"[Pila vacia]\n";
        return;
    }
    
    int id;
    id = leerEntero("Ingrese el Id del proceos : ");
    Proceso* pro = p.Inicio;
    Pila temp;
    temp.Inicio = NULL;
    while(pro != NULL)
    {
    	if(pro->ProcesoId == id)
    	{
    		temp.Inicio = pro;
		}
    	pro = pro->sge;
	}
    
    if(temp.Inicio == NULL)
    {
    	cout<<"No se encontro ese proceso\n";
	}else
	{
		mostrarEstadoMemoria(temp);
	}
}

void liberarTodo(Pila& p)
{
	if (verificarPila(p)) {
        cout <<"[Pila vacia]\n";
        return;
    }
    while(verificarPila(p))
    {
    	liberarProceso(p);
	}
	cout<<"Proceso los procesos fueron eliminados correctamente\n";
}

void inicializar(Pila& p) {
    p.Inicio = NULL;
    p.Final = NULL;
    p.Tamano = 0;
}

void mostrarMenu() {
    cout<<"\n==============\n";
    cout<<"Menu";
    cout<<"\n==============\n";
    cout<<"1. Lista\n";
    cout<<"2. Cola\n";
    cout<<"3. Gestor de memoria para procesos de un sistema operativo\n";
    cout<<"4. Salir\n";
    cout<<"------------------------------------------\n";
}

void mostrarSubMenu3()
{
	cout<<"\n==============\n";
    cout<<"SubMenu Nº03";
    cout<<"\n==============\n";
    cout<<"1. Asignar proceso\n";
    cout<<"2. Buscar proceso\n";
    cout<<"3. Liberar proceso\n";
    cout<<"4. Mostrar los proceso\n";
    cout<<"5. Liberar todos los proceso\n";
    cout<<"6. Salir\n";
    cout<<"------------------------------------------\n";
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
				break;
			case 2:
				break;
			case 3:
				Pila pl;
				inicializar(pl);
				int op3;
				do
				{
					mostrarSubMenu3();
					op3 = leerEntero("Ingrese una opcion : ");
					switch(op3)
					{
						case 1:
							asignarMemoria(pl);
							break;
						case 2:
							buscarProceso(pl);
							break;
						case 3:
							liberarProceso(pl);
							break;
						case 4:
							mostrarEstadoMemoria(pl);
							break;
						case 5:
							liberarTodo(pl);
							break;
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
