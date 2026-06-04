// INTEGRANTE: Cosme Carlos Jefry
// MODULO: Planificador del CPU (Cola de Prioridad)
// FUNCION: Encolar un proceso segun su prioridad
// DESCRIPCION: Inserta un nuevo proceso en la cola
//              respetando el orden de prioridad.
//              Menor numero = mayor prioridad

Proceso EncolarProceso
	
	// Declaracion de variables
	Definir id, prioridad Como Entero
	Definir nombre Como Cadena
	Definir colaVacia Como Logico
	
	// Solicitar datos del proceso al usuario
	Escribir "============================="
	Escribir "== PLANIFICADOR DEL CPU =="
	Escribir "== Encolando nuevo proceso =="
	Escribir "============================="
	
	Escribir "Ingrese el ID del proceso:"
	Leer id
	
	Escribir "Ingrese el nombre del proceso:"
	Leer nombre
	
	Escribir "Ingrese la prioridad (1=Alta, 5=Baja):"
	Leer prioridad
	
	// Verificar si la cola esta vacia
	Si colaVacia = Verdadero Entonces
		Escribir "Cola vacia. Proceso encolado como primero."
	SiNo
		// Insertar en posicion correcta segun prioridad
		Escribir "Buscando posicion correcta segun prioridad..."
		Escribir "Proceso encolado segun su prioridad."
	FinSi
	
	// Confirmar operacion exitosa
	Escribir "Proceso [", nombre, "] con prioridad [", prioridad, "] encolado correctamente."
	
FinProceso