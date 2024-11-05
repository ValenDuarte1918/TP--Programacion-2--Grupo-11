#ifndef FUNCIONES_CONFIGURACION_H
#define FUNCIONES_CONFIGURACION_H
#include "./archivos/archivoVentas.h"
#include "./archivos/archivoEmpleado.h"
#include "./archivos/archivoProducto.h"
#include <iostream>

using namespace std;

void copiaSeguridadVentas(){
    archivoVenta obj1("Venta.dat");
    archivoVenta obj2("Venta.bkp");
    Venta obj;
    obj2.limpiarArchivo();
    int cant = obj1.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj1.leerRegistro(i);
        obj2.grabarRegistro(obj);
    }
}

void restaurarCopiaSeguridadVentas(){
    archivoVenta obj1("Venta.dat");
    archivoVenta obj2("Venta.bkp");
    Venta obj;
    obj1.limpiarArchivo();
    int cant = obj2.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj2.leerRegistro(i);
        obj1.grabarRegistro(obj);
    }
}

void copiaDeSeguridadEmpleados(){
    archivoEmpleado obj1("Empleado.dat");
    archivoEmpleado obj2("Empleado.bkp");
    Empleado obj;
    obj2.limpiarArchivo();
    int cant = obj1.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj1.leerRegistro(i);
        obj2.grabarRegistro(obj);
    }
}

void restaurarCopiaDeSeguridadEmpleados(){
    archivoEmpleado obj1("Empleado.dat");
    archivoEmpleado obj2("Empleado.bkp");
    Empleado obj;
    obj1.limpiarArchivo();
    int cant = obj2.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj2.leerRegistro(i);
        obj1.grabarRegistro(obj);
    }
}

void copiaDeSeguridadProductos(){
    archivoProducto obj1("Producto.dat");
    archivoProducto obj2("Producto.bkp");
    Producto obj;
    obj2.limpiarArchivo();
    int cant = obj1.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj1.leerRegistro(i);
        obj2.grabarRegistro(obj);
    }
}

void restaurarCopiaDeSeguridadProductos(){
    archivoProducto obj1("Producto.dat");
    archivoProducto obj2("Producto.bkp");
    Producto obj;
    obj1.limpiarArchivo();
    int cant = obj2.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj2.leerRegistro(i);
        obj1.grabarRegistro(obj);
    }
}

















#endif // FUNCIONES_CONFIGURACION_H