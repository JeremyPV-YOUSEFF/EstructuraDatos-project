// INTEGRANTE: Cosme Carlos Jefry
// MODULO: Planificador del CPU (Cola de Prioridad)
// FUNCION: Mostrar estado actual de la cola
// DESCRIPCION: Recorre toda la cola y muestra
//              cada proceso con su posicion,
//              nombre y prioridad. Indica cual
//              es el siguiente a ejecutarse.

Proceso MostrarCola
	
	// Declaracion de variables
	Definir pos Como Entero
	Definir nombre Como Cadena
	Definir prioridad, id Como Entero
	Definir colaVacia Como Logico
	
	// Iniciar posicion en 1
	pos <- 1
	
	Escribir "============================="
	Escribir "== PLANIFICADOR DEL CPU =="
	Escribir "== Estado actual de la Cola =="
	Escribir "============================="
	
	// Verificar si la cola tiene procesos
	Si colaVacia = Verdadero Entonces
		Escribir "La cola esta vacia. No hay procesos."
	SiNo
		// Recorrer todos los procesos de la cola
		Mientras pos <= 5 Hacer // Recorre hasta el final
			Escribir "---------------------------"
			Escribir "Posicion  : ", pos
			Escribir "ID        : ", id
			Escribir "Nombre    : ", nombre
			Escribir "Prioridad : ", prioridad, " (1=Maximo)"
			
			// Marcar el primero como siguiente a ejecutar
			Si pos = 1 Entonces
				Escribir ">>> SIGUIENTE A EJECUTAR <<<"
			FinSi
			
			// Avanzar al siguiente nodo
			pos <- pos + 1
		FinMientras
		
		// Mostrar total de procesos en cola
		Escribir "============================="
		Escribir "Total procesos en cola: ", pos - 1
		Escribir "============================="
	FinSi
	
FinProceso