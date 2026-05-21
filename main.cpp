#include <iostream>
#include <string>
#include "libreria.h"
using namespace std;

void mostrarMenu() {
    cout << "\n==============" << endl;
    cout << "   Menu" << endl;
    cout << "==============" << endl;
    cout << "  1. Lista"  << endl;
    cout << "  2. Cola" << endl;
    cout << "  3. Pila"        << endl;
    cout << "  4. Salir"                                    << endl;
    cout << "------------------------------------------"   << endl;
}

int main()
{
	int op;
	do
	{
		mostrarMenu();
		op = validNum("Ingrese una opcion : ");
		switch(op)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				cout<<"\nCerrando programa\n";
				break;
			default:
				break;
		}
	}while(op!=4);
	return 0;
}
