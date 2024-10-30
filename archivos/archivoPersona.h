#ifndef ARCHIVOPERSONA_H_INCLUDED
#define ARCHIVOPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "../clases/clsPersona.cpp"

using namespace std;

class archivoPersona {
    private:
        char nombre[50]; 

    public:
        archivoPersona(const char *n = "persona.dat") { strcpy(nombre, n); } // Constructor que inicializa el nombre del archivo
        void limpiarArchivo(); // Metodo para limpiar el archivo
        void grabarRegistro(Persona obj); // Metodo para grabar un registro
        void modificarRegistro(Persona obj, int pos); // Metodo para modificar un registro
        Persona leerRegistro(int pos); // Metodo para leer un registro
        void listarRegistros(); // Metodo para listar todos los registros
        int contarRegistros(); // Metodo para contar el numero de registros
        int buscarRegistro(int num); // Metodo para buscar un registro por DNI
};

// Implementacion de los metodos

// Metodo para limpiar el archivo
void archivoPersona::limpiarArchivo() {
    FILE *p = fopen(nombre, "wb"); // Abre el archivo en modo escritura binaria
    if (p == NULL) { // Verifica si el archivo se abrio correctamente
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fclose(p); // Cierra el archivo
}

// Metodo para grabar un registro en el archivo
void archivoPersona::grabarRegistro(Persona obj) {
    FILE *p = fopen(nombre, "ab"); // Abre el archivo en modo adicion binaria
    if (p == NULL) { // Verifica si el archivo se abrio correctamente
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p); // Escribe el objeto en el archivo
    fclose(p); // Cierra el archivo
}

// Metodo para modificar un registro en el archivo
void archivoPersona::modificarRegistro(Persona obj, int pos) {
    FILE *p = fopen(nombre, "rb+"); // Abre el archivo en modo lectura/escritura binaria
    if (p == NULL) { // Verifica si el archivo se abrio correctamente
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fseek(p, pos * sizeof obj, 0); // Mueve el puntero del archivo a la posicion deseada
    fwrite(&obj, sizeof obj, 1, p); // Escribe el objeto en la posicion especificada
    fclose(p); // Cierra el archivo
}

// Metodo para listar todos los registros del archivo
void archivoPersona::listarRegistros() {
    int cant = contarRegistros(); // Obtiene la cantidad de registros en el archivo
    Persona obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i); // Lee el registro en la posicion i
        obj.mostrar(); // Muestra el registro
        if (obj.getEstado() == true) { // Verifica el estado del registro
            cout << "Estado: Activo" << endl;
        } else {
            cout << "Estado: Inactivo" << endl;
        }
        cout << "<----------------------------------->" << endl;
    }
}

// Metodo para contar el numero de registros en el archivo
int archivoPersona::contarRegistros() {
    FILE *p = fopen(nombre, "rb"); // Abre el archivo en modo lectura binaria
    if (p == NULL) { return -1; } // Verifica si el archivo se abrio correctamente
    fseek(p, 0, 2); // Mueve el puntero del archivo al final
    int cantBytes = ftell(p); // Obtiene la cantidad de bytes en el archivo
    fclose(p); // Cierra el archivo
    return cantBytes / sizeof(Persona); // Calcula y retorna la cantidad de registros
}

// Metodo para buscar un registro por DNI
int archivoPersona::buscarRegistro(int num) {
    int cant = contarRegistros(); // Obtiene la cantidad de registros en el archivo
    Persona obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i); // Lee el registro en la posicion i
        if (num == obj.getDni()) { // Compara el DNI del registro con el numero buscado
            return i; // Retorna la posicion si encuentra el registro
        }
    }
    return -1; // Retorna -1 si no encuentra el registro
}

// Metodo para leer un registro en una posicion especifica
Persona archivoPersona::leerRegistro(int pos) {
    Persona obj;
    obj.setDni(-1); // Inicializa el DNI del objeto a -1
    FILE *p = fopen(nombre, "rb"); // Abre el archivo en modo lectura binaria
    if (p == NULL) { // Verifica si el archivo se abrio correctamente
        obj.setDni(-2); // Establece el DNI del objeto a -2 si hay un error
        return obj;
    }
    fseek(p, pos * sizeof obj, 0); // Mueve el puntero del archivo a la posicion deseada
    fread(&obj, sizeof obj, 1, p); // Lee el objeto desde el archivo
    fclose(p); // Cierra el archivo
    return obj; // Retorna el objeto
}

#endif // ARCHIVOPERSONA_H_INCLUDED