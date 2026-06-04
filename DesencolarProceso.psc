
// INTEGRANTE: Cosme Carlos Jefry
// MODULO: Planificador del CPU (Cola de Prioridad)
// FUNCION: Desencolar proceso (simular ejecucion)
// DESCRIPCION: Extrae el proceso del frente de la
//              cola y simula su ejecucion en el CPU.
//              Siempre ejecuta el de mayor prioridad.

Proceso DesencolarProceso
	
	// Declaracion de variables
	Definir nombre Como Cadena
	Definir prioridad, id Como Entero
	Definir colaVacia Como Logico
	
	Escribir "============================="
	Escribir "== PLANIFICADOR DEL CPU =="
	Escribir "== Ejecutando proceso =="
	Escribir "============================="
	
	// Verificar si hay procesos en la cola
	Si colaVacia = Verdadero Entonces
		// No se puede desencolar si esta vacia
		Escribir "ERROR: La cola esta vacia."
		Escribir "No hay procesos para ejecutar."
	SiNo
		// Tomar el proceso del frente (mayor prioridad)
		Escribir "Tomando proceso del frente de la cola..."
		Escribir "================================"
		Escribir "Ejecutando en CPU: ", nombre
		Escribir "ID del proceso   : ", id
		Escribir "Prioridad        : ", prioridad
		Escribir "================================"
		
		// Mover el frente al siguiente proceso
		Escribir "Avanzando frente de la cola..."
		
		// Confirmar que el proceso fue ejecutado
		Escribir "Proceso ejecutado y liberado del CPU correctamente."
	FinSi
	
FinProceso