#ifndef ARCHIVOPROVEEDOR_H_INCLUDED
#define ARCHIVOPROVEEDOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "../clases/clsProveedor.cpp"

using namespace std;

// Clase para manejar el archivo de proveedores
class archivoProveedor {
    private:
        char nombre[50]; // Nombre del archivo
    public:
        // Constructor que inicializa el nombre del archivo
        archivoProveedor(const char *n= "proveedor.dat") {strcpy(nombre, n);}

        // Métodos para manejar el archivo
        void limpiarArchivo(); // Limpia el archivo
        void grabarRegistro(Proveedor obj); // Graba un registro en el archivo
        void modificarRegistro(Proveedor obj, int pos); // Modifica un registro en una posición específica
        void listarRegistros(); // Lista todos los registros del archivo
        int contarRegistros(); // Cuenta el número de registros en el archivo
        int buscarRegistro(int num); // Busca un registro por su número
        Proveedor leerRegistro(int pos); // Lee un registro en una posición específica
};

// Implementación del método para limpiar el archivo
void archivoProveedor::limpiarArchivo() {
    FILE *p= fopen(nombre, "wb");
    if(p==NULL) {
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fclose(p);
}

// Implementación del método para grabar un registro en el archivo
void archivoProveedor::grabarRegistro(Proveedor obj) {
    FILE *p= fopen(nombre, "ab");
    if(p==NULL) {
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

// Implementación del método para modificar un registro en una posición específica
void archivoProveedor::modificarRegistro(Proveedor obj, int pos) {
    FILE *p= fopen(nombre, "rb+");
    if(p==NULL) {
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fseek(p, pos*sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

// Implementación del método para listar todos los registros del archivo
void archivoProveedor::listarRegistros() {
    int cant= contarRegistros();
    Proveedor obj;
    for (int i=0; i<cant; i++) {
        obj= leerRegistro(i);
        obj.mostrar();
    if (obj.getEstado() == true) { // Verifica el estado del registro
            cout << "Estado: Activo" << endl;
        } else {
            cout << "Estado: Inactivo" << endl;
        }
        cout << "<----------------------------------->" << endl;
        
    }
}

// Implementación del método para contar el número de registros en el archivo
int archivoProveedor::contarRegistros() {
    FILE *p= fopen(nombre, "rb");
    if(p==NULL) {return -1;}
    fseek(p, 0, 2);
    int cant= ftell(p)/sizeof(Proveedor);
    fclose(p);
    return cant;
}

// Implementación del método para buscar un registro por su número
int archivoProveedor::buscarRegistro(int num) {
    Proveedor obj;
    int cant= contarRegistros();
    for (int i=0; i<cant; i++) {
        obj= leerRegistro(i);
        if(num == obj.getCodProveedor()) {
            return i;
        }
    }
    return -1;
}

// Implementación del método para leer un registro en una posición específica
Proveedor archivoProveedor::leerRegistro(int pos) {
    Proveedor obj;
    obj.setCodProveedor(-1);
    FILE *p= fopen(nombre, "rb");
    if(p==NULL) {
        obj.setCodProveedor(-2);
        return Proveedor();
    }
    fseek(p, pos*sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

#endif // ARCHIVOPROVEEDOR_H_INCLUDED