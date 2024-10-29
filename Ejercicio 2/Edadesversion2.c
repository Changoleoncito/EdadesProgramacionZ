// Paso 1: Agregamos las bibliotecas necesarias
#include <stdio.h>
#include <stdlib.h>  //convertiremos cadenas a enteros atoi Ejemplo 129 (texto) a 123(numero) para ello ATOI
#include <string.h>  // para manejar cadenas como strcpy (función que copia texto de un lugar a otro) y strtok (para dividir un texto en partes)

// Paso 2: Definimos la estructura para cada persona
typedef struct {
    char nombre[50];                                    // Cadena para el nombre, con un máximo de 50 caracteres.
    int edad;                                           // Número entero para la edad.
    int puntos;                                         // Número entero para la puntuación.
} Persona;                                              // Le damos el nombre "Persona" a nuestra estructura
//Paso 3 debemos crear las funciones que hagan las operaciones
// PROMEDIO
float calcularEdadPromedio(Persona personas[], int numPersonas) {                             // float para manejar decimales
    int sumaEdades = 0; 
    for (int i = 0; i < numPersonas; i++) {                                                  //Inicializa para acumular, después recorre todas las personas, suma y obtiene el promedio
        sumaEdades += personas[i].edad;                                                     
    }
    return (float)sumaEdades / numPersonas;                                                 
}
//PUNTUACIÓN PROMEDIO
// Función para calcular la puntuación promedio
float calcularPuntuacionPromedio(Persona personas[], int numPersonas) {
    int sumaPuntos = 0;                                                             // Utilizamos el mismo proceso
    for (int i = 0; i < numPersonas; i++) {                            
        sumaPuntos += personas[i].puntos;                                      
    }
    return (float)sumaPuntos / numPersonas; 
}
//Función para encontrar la persona mas alta 
// Función para encontrar la persona con la puntuación más alta                           
Persona* encontrarMayorPuntuacion(Persona personas[], int numPersonas) {                   //Uso de Punteros: Asumimos que la primera persona es mayor entonces ahora estará comparando
    Persona* mayor = &personas[0];                                                         // apunta al primer elemento con persona*mayor                                                                                 
    for (int i = 1; i < numPersonas; i++) { 
        if (personas[i].puntos > mayor->puntos) { 
            mayor = &personas[i]; 
        }
    }
    return mayor; 
}
// funcion para encontrar persona con menor puntuación
// Función para encontrar la persona con la puntuación más baja
Persona* buscarPuntuacionBaja(Persona personas[], int numPersonas) {
    Persona* menor = &personas[0];                                                 // Inicialmente asumimos que la primera persona tiene la puntuación más baja
    for (int i = 1; i < numPersonas; i++) {                                       // Bucle para recorrer todas las personas desde la segunda
        if (personas[i].puntos < menor->puntos) {                                 // Compara la puntuación actual con la menor registrada
            menor = &personas[i];                                                 
        }
    }
    return menor; // Retorna un puntero a la persona con la puntuación más baja
}



// Paso 4: Leer el archivo CSV y almacenar los datos
// Creamos una función para leer el archivo
int leerArchivo(char* archivoNombre, Persona personas[], int maxPersonas) {
    // lo abrimos en modo lectura
    FILE* archivo = fopen(archivoNombre, "r");
    if (!archivo) {                                                      // Verifica si el archivo se abrió correctamente
        perror("No se pudo abrir el archivo, hubo un error");            //La función perror en C se utiliza para imprimir un mensaje de error en la salida estándar ("mensaje de error claro y útil")
        return -1;                                                       // Al devolver -1, se señala que la función no pudo completar su tarea de manera exitosa. Esto permite al llamador de la función saber que ocurrió un problema.
    }

    // Espacio para una línea del archivo CSV, puede almacenar hasta 256 caracteres
    char linea[256]; 
    
    // Contador para el número de registros leídos
    int cuenta = 0; 
    
    // Lee el archivo línea por línea
    while (fgets(linea, sizeof(linea), archivo) && cuenta < maxPersonas) {
        Persona persona; // Declara una variable de tipo Persona para almacenar los datos de la línea actual
        char* token = strtok(linea, ","); // Divide la línea en partes usando la coma como separador
        strcpy(persona.nombre, token); // Copia el primer token (nombre) al campo nombre de la estructura Persona
        token = strtok(NULL, ","); // Obtiene el siguiente token (edad)
        persona.edad = atoi(token); // Convierte el token de edad a entero y lo almacena en el campo edad
        token = strtok(NULL, ","); // Obtiene el siguiente token (puntos)
        persona.puntos = atoi(token); // Convierte el token de puntos a entero y lo almacena en el campo puntos

        personas[cuenta++] = persona; // Almacena la estructura Persona en el array y aumenta el contador
    }

    fclose(archivo); // Cerramos nuestro archivito después de haber leído todos los datos
    return cuenta; // Retorna el número de registros leídos
}
int main();

