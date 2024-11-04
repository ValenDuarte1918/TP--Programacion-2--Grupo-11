#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "../clases/Producto.h"
#include "../clases/Producto.cpp"

using namespace std;

class archivoProducto {
    private:
        char nombre[50];
    public:
        archivoProducto(const char *n = "producto.dat") { strcpy(nombre, n); }
        void limpiarArchivo();
        void grabarRegistro(Producto obj);
        void modificarRegistro(Producto obj, int pos);
        void listarRegistros();
        int contarRegistros();
        int buscarRegistro(int num);
        Producto leerRegistro(int pos);
};

void archivoProducto::limpiarArchivo() {
    FILE *p = fopen(nombre, "wb");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fclose(p);
}

void archivoProducto::grabarRegistro(Producto obj) {
    FILE *p = fopen(nombre, "ab");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void archivoProducto::modificarRegistro(Producto obj, int pos) {
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl;
        return;
    }
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void archivoProducto::listarRegistros() {
    int cant = contarRegistros();
    Producto obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        if (obj.getEstado() == true){
            obj.mostrarP();
        }
    }
}

int archivoProducto::contarRegistros() {
    FILE *p = fopen(nombre, "rb");
    if (p == NULL) {return -1;}
    fseek(p, 0, 2);
    int cant = ftell(p) / sizeof(Producto);
    fclose(p);
    return cant;
}

int archivoProducto::buscarRegistro(int num) {
    int cant = contarRegistros();
    Producto obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        if (num == obj.getProducto()) {
            return i;
        }
    }
    return -1;
}

Producto archivoProducto::leerRegistro(int pos) {
    FILE *p = fopen(nombre, "rb");
    Producto obj;
    if (p == NULL) {
        cout << "Error de apertura de archivo" << endl;
        return Producto();
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}


#endif // ARCHIVOPRODUCTO_H_INCLUDED
