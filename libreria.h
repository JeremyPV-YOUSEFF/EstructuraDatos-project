#include<iostream>
#include <string>
#include <sstream>

using namespace std;

int leerEntero(string text,int v1 = 0, int v2 = 0) {
    string input;//Declaramaos la variable input tipo string
    int num;//Declaramaos la variable num tipo int
	
	cout<<text;
	
    while (true) { //Realizamos un bucle while
        getline(cin, input);//Leer toda la linea que escribe el usuario, y almacenarlo en la variable input
        stringstream ss(input);//Convierte el input en un flujo de datos

        // ? valida que sea número entero y nada más
        if (ss >> num && ss.eof()) { //ss >> num, sirve para convetir nuestro input en int, y si falla, nos devuelve el error, y si es correcto no regresa el numero y termina el bucle
        //ss.eof, sirve para indidar la culminacion del flujo de datos
        	
        	//Verificar que v2 sea diferente
        	if(v2 != 0)
        	{
        		if(num > v1 && num < v2)//Validar que el numero sea mayor a v1 y menor que v2
				{
					
					return num; // termina el bucle y regresa el num
				}else
				{
					cout << "Error: ingrese un numero mayor "<<v1<<" y menor  "<<v2<<" : ";
				}
			}else 
			{
				if(num > v1 )//Validar que el numero sea mayor a v1 
				{
					
					return num; // termina el bucle y regresa el num
				}else
				{
					cout << "Error: ingrese un numero mayor a"<<v1<<" : ";
				}
			}
            
        } else {
        	//Si ocurre un error al convertir en input en int, me mandara aca y mostrara el error, ejecutandose el bucle nuevamente
            cout << "Error: ingrese un numero entero valido: ";//Mensaje de error
        }
    }
}

//Definimos un funcion, que devuelva un tipo string
string leerCadena(string text) {
    string input;//Declaramaos la variable input tipo string
	
	cout<<text;
	
    while (true) {//Realizamos un bucle while
        getline(cin, input);//Leer toda la linea que escribe el usuario, y almacenarlo en la variable input

        bool valido = true;
		
		//Realizamos un bucle for, para revisar cala letra de la palbra, y revisar que no haya un numero
        for (int i = 0; i < input.length(); i++) {
        	//Comenzamos con la validacion
        	//isalpha, es para revisar que sea una letra, y la otra valiacion es para aceptar espacios en blanco
            if (!(isalpha(input[i]) || input[i] == ' ')) {
                valido = false;//Si hay un error marca la cadena como invalida, y rompe el bucle
                break;
            }
        }

        if (valido && input.length() > 0) {
        	//Verificamos que valido sea true, y que el input sea mayor que 1
            return input;//regresamos el input y terminamos el bucle
        } else {
        		//Si ocurre un error al convertir en input en string, me mandara aca y mostrara el error, ejecutandose el bucle nuevamente
            cout << "Error: ingrese solo letras (sin numeros): ";//Mensaje de error
        }
    }
}

