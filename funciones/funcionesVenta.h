#ifndef FUNCIONESVENTA_H_INCLUDED
#define FUNCIONESVENTA_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../archivos/archivoVentas.h"
#include "../clases/Venta.cpp"

using namespace std;


void listarVenta() {
    archivoVenta obj1;
    obj1.listarRegistros();
}

void modificarVenta() {
    archivoVenta obj1("Venta.dat");
    int num;
    cout << "Ingrese el codigo a modificar: ";
    cin >> num;
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Codigo no encontrado" << endl;
        return;
    }
    Venta obj;
    obj = obj1.leerRegistro(pos);
    int codVen;
    cout << "Ingrese el nuevo codigo de Venta: ";
    cin >> codVen;
    obj.setCodVenta(codVen);
    obj1.modificarRegistro(obj, pos);
    if (obj.getEstado() == false) {
        cout << "No se pudo modificar el registro" << endl;
    } else {
        cout << "Registro modificado exitosamente" << endl;
    }
}

void bajaVenta() {
    archivoVenta obj1;
    int num;
    cout << "Ingrese el numero de Venta a eliminar: ";
    cin >> num;
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Venta no encontrado" << endl;
        return;
    }
    Venta obj;
    obj = obj1.leerRegistro(pos);
    obj.setEstado(false);
    obj1.modificarRegistro(obj, pos);
    cout << "Venta eliminado" << endl;
}

void altaVenta() {
    archivoVenta obj1("Venta.dat");
    Venta obj;
    obj.cargar();
    int pos = obj1.buscarRegistro(obj.getCodVenta());
    if (pos != -1) {
        cout << "Ese Codigo de Venta ya existe" << endl;
        obj.setEstado(false);
    }
    if (obj.getEstado() == true) {
        obj1.grabarRegistro(obj);
    } else {
        cout << "No se pudo grabar el registro" << endl;
    }
}

void buscarVenta() {
    int num;
    cout << "Ingrese el numero de Venta a buscar: ";
    cin >> num;
    archivoVenta obj1;
    Venta obj;
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Venta no encontrada" << endl;
        return;
    }
    obj = obj1.leerRegistro(pos);
    system("cls");
    obj.mostrar();
}

void limpiarVenta() {
    archivoVenta obj1;
    obj1.limpiarArchivo();
    cout << "Archivo de Venta borrado" << endl;
}

#endif // FUNCIONESVENTA_H_INCLUDED
