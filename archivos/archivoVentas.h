#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED
#include <iostream>
#include <cstring>
#include "../clases/Venta.cpp"

using namespace std;

class archivoVenta
{
private:
  char nombre[50];
public:
  archivoVenta(const char* n="Venta.dat") { strcpy(nombre,n); }
  void limpiarArchivo();
  void grabarRegistro(Venta obj);
  void modificarRegistro(Venta obj, int pos);
  Venta leerRegistro(int pos);
  void listarRegistros();
  int contarRegistros();
  int buscarRegistro(int num);
};

void archivoVenta::limpiarArchivo(){
    FILE *p = fopen(nombre, "wb");
    if (p == NULL){ cout << "Error de apertura de archivo" << endl;
        return;}
    fclose(p);
}

void archivoVenta::grabarRegistro(Venta obj){
    FILE *p = fopen(nombre, "ab");
    if (p == NULL){ cout << "Error de apertura de archivo" << endl;
        return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void archivoVenta::modificarRegistro(Venta obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){ cout << "Error de apertura de archivo" << endl;
        return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void archivoVenta::listarRegistros(){
    int cant = contarRegistros();
    Venta obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        obj.mostrar();
        if (obj.getEstado() == true) { cout << "Estado: Activo" << endl;
        }else { cout << "Estado: Inactivo" << endl; }
      cout << "<----------------------------------->" << endl;
    }
}

int archivoVenta::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if (p == NULL) { return -1; }
    fseek(p, 0, 2);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes / sizeof(Venta);
}

int archivoVenta::buscarRegistro(int num){
    int cant = contarRegistros();
    Venta obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        if (num == obj.getCodVenta()) return i;
    }
    return -1;
}

Venta archivoVenta::leerRegistro(int pos){
    Venta obj;
    obj.setCodVenta(-1);
    FILE *p = fopen(nombre, "rb");
    if (p == NULL) { obj.setCodVenta(-2);
        return obj; }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

#endif // ARCHIVOVENTAS_H_INCLUDED
