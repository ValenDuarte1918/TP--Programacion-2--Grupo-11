#ifndef ARCHIVOEMPLEADO_H_INCLUDED
#define ARCHIVOEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "../clases/clsEmpleado.cpp"

using namespace std;

// Definición de la clase archivoEmpleado para manejar operaciones de archivo relacionadas con empleados
class archivoEmpleado {
    private:
        char nombre[50]; 
    public:
        // Constructor que inicializa el nombre del archivo
        archivoEmpleado(const char *n = "empleado.dat") { strcpy(nombre, n); }

        // Declaración de métodos para operaciones de archivo
        void limpiarArchivo();
        void grabarRegistro(Empleado obj);
        void modificarRegistro(Empleado obj, int pos);
        void listarRegistros();
        int contarRegistros();
        int buscarRegistro(int num);
        Empleado leerRegistro(int pos);
};

// Implementación del método para limpiar el archivo
void archivoEmpleado::limpiarArchivo() {
    // Abre el archivo en modo escritura binaria (wb) para limpiarlo
    FILE *p = fopen(nombre, "wb");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl; 
        return;
    }
    fclose(p); // Cierra el archivo
}

// Implementación del método para grabar un registro de empleado en el archivo
void archivoEmpleado::grabarRegistro(Empleado obj) {
    // Abre el archivo en modo añadir binario (ab) para agregar un nuevo registro
    FILE *p = fopen(nombre, "ab");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl; 
        return;
    }
    fwrite(&obj, sizeof obj, 1, p); // Escribe el objeto empleado en el archivo
    fclose(p); // Cierra el archivo
}

// Implementación del método para modificar un registro de empleado en una posición específica
void archivoEmpleado::modificarRegistro(Empleado obj, int pos) {
    // Abre el archivo en modo lectura/escritura binaria (rb+)
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl; 
        return;
    }
    fseek(p, pos * sizeof obj, 0); // Mueve el puntero del archivo a la posición especificada
    fwrite(&obj, sizeof obj, 1, p); // Escribe el objeto empleado en la posición especificada
    fclose(p); // Cierra el archivo
}

// Implementación del método para listar todos los registros de empleados
void archivoEmpleado::listarRegistros() {
    int cant = contarRegistros(); // Obtiene la cantidad de registros en el archivo
    Empleado obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i); // Lee el registro en la posición i
        obj.mostrar(); // Muestra los datos del empleado
        if (obj.getEstado() == true) { // Verifica el estado del registro
            cout << "Estado: Activo" << endl;
        } else {
            cout << "Estado: Inactivo" << endl;
        }
        cout << "<----------------------------------->" << endl;
    }
}

// Implementación del método para contar la cantidad de registros en el archivo
int archivoEmpleado::contarRegistros() {
    // Abre el archivo en modo lectura binaria (rb)
    FILE *p = fopen(nombre, "rb");
    if (p == NULL) { return -1; } // Retorna -1 si no se puede abrir el archivo
    fseek(p, 0, 2); // Mueve el puntero del archivo al final
    int cant = ftell(p) / sizeof(Empleado); // Calcula la cantidad de registros
    fclose(p); // Cierra el archivo
    return cant; // Retorna la cantidad de registros
}

// Implementación del método para leer un registro de empleado en una posición específica
Empleado archivoEmpleado::leerRegistro(int pos) {
    // Abre el archivo en modo lectura binaria (rb)
    FILE *p = fopen(nombre, "rb");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl; 
        return Empleado(); // Retorna un objeto Empleado vacío
    }
    Empleado obj;
    fseek(p, pos * sizeof obj, 0); // Mueve el puntero del archivo a la posición especificada
    fread(&obj, sizeof obj, 1, p); // Lee el objeto empleado en la posición especificada
    fclose(p); // Cierra el archivo
    return obj; // Retorna el objeto empleado leído
}

// Implementación del método para buscar un registro de empleado por su código
int archivoEmpleado::buscarRegistro(int num) {
    int cant = contarRegistros(); // Obtiene la cantidad de registros en el archivo
    Empleado obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i); // Lee el registro en la posición i
        if (num == obj.getDni()) {
            return i; // Retorna la posición si el código del empleado coincide
        }
    }
    return -1; // Retorna -1 si no se encuentra el registro
}

#endif // ARCHIVOEMPLEADO_H_INCLUDED