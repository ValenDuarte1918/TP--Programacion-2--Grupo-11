#ifndef FUNCIONESEMPLEADO_H_INCLUDED
#define FUNCIONESEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../archivos/archivoVentas.h"

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
    cout << "Ingrese el numero de Empleado a eliminar: ";
    cin >> num;
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Empleado no encontrado" << endl;
        return;
    }
    Venta obj;
    obj = obj1.leerRegistro(pos);
    obj.setEstado(false);
    obj1.modificarRegistro(obj, pos);
    cout << "Empleado eliminado" << endl;
}

void altaVenta() {
    archivoVenta obj1("Venta.dat");
    Venta obj;
    obj.cargarV();
    int pos = obj1.buscarRegistro(obj.getCodEmpleado());
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
        cout << "Empleado no encontrado" << endl;
        return;
    }
    obj = obj1.leerRegistro(pos);
    system("cls");
    obj.mostrarV();
}

void limpiarVenta() {
    archivoVenta obj1;
    obj1.limpiarArchivo();
    cout << "Archivo de empleados borrado" << endl;
}

///void buscarVentaPorTipo(){
///    archivoVenta obj1;
///    Venta obj;
///    char tipo[50];
///    cout << "Ingrese el tipo a buscar:  Cocinero || Ayudante de cocina || Cajero" << endl;
///    cin.ignore();
///    cin.getline(tipo, 50);
///    int cant = obj1.contarRegistros();
///    for (int i = 0; i < cant; i++) {
///        obj = obj1.leerRegistro(i);
///        if (strcmp(obj.getCodVenta(), tipo) == 0 && obj.getEstado() == true) {
///            obj.mostrarV();
///        }else{
///            cout << "No se encontro ningun Venta con ese tipo" << endl;
///        }
///    }
///}

#endif // FUNCIONESEMPLEADO_H_INCLUDED

