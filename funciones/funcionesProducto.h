#ifndef FUNCIONESPRODUCTO_H_INCLUDED
#define FUNCIONESPRODUCTO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../archivos/archivoProducto.h"

using namespace std;

// Función para listar todos los productos
void listarProducto() {
    archivoProducto obj1;
    obj1.listarRegistros(); // Llama a la función para listar todos los registros de productos
}

// Función para modificar un producto existente
void modificarProducto() {
    archivoProducto obj1("producto.dat");
    int num;

    // Solicita el código del producto a modificar
    cout << "Ingrese el codigo a modificar: ";
    cin >> num;

    // Busca el registro del producto por el código especificado
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Codigo no encontrado" << endl; // Mensaje si el código no se encuentra
        return;
    }

    // Lee el registro del producto en la posición especificada
    Producto obj;
    obj = obj1.leerRegistro(pos);

    // Solicita el nuevo código del producto
    int codProd;
    cout << "Ingrese el nuevo codigo de producto: ";
    cin >> codProd;

    // Establece el nuevo código del producto
    obj.setCodProducto(codProd);

    // Modifica el registro del producto en la posición especificada
    obj1.modificarRegistro(obj, pos);

    // Verifica si el estado del producto es falso (no modificado)
    if (obj.getEstado() == false) {
        cout << "No se pudo modificar el registro" << endl; // Mensaje si no se pudo modificar el registro
    } else {
        cout << "Registro modificado exitosamente" << endl; // Mensaje si el registro se modificó exitosamente
    }
}

// Función para dar de baja a un producto
void bajaProducto() {
    archivoProducto obj1;
    int num;

    // Solicita el número de producto a dar de baja
    cout << "Ingrese el numero de producto a dar de baja: ";
    cin >> num;

    // Busca el registro del producto por el número especificado
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Producto no encontrado" << endl; // Mensaje si el registro no se encuentra
        return;
    }

    // Lee el registro del producto en la posición especificada
    Producto obj;
    obj = obj1.leerRegistro(pos);

    // Establece el estado del producto a falso (eliminado)
    obj.setEstado(false);

    // Modifica el registro del producto en la posición especificada
    obj1.modificarRegistro(obj, pos);

    cout << "Producto eliminado" << endl; // Mensaje si el registro se eliminó
}

// Función para dar de alta a un nuevo producto
void altaProducto() {
    archivoProducto obj1;
    Producto obj;

    // Carga los datos del nuevo producto
    obj.cargarP();

    // Verifica si el código del producto ya existe
    int codProducto = obj.getCodProducto();
    int pos = obj1.buscarRegistro(codProducto);
    if (pos != -1) {
        cout << "Ese Codigo de producto ya existe" << endl; // Mensaje si el código de producto ya existe
        obj.setEstado(false);
    }

    // Si el estado del producto es verdadero (nuevo), graba el registro
    if (obj.getEstado() == true) {
        obj1.grabarRegistro(obj);
    } else {
        cout << "No se pudo grabar el registro" << endl; // Mensaje si no se pudo grabar el registro
    }
}

// Función para buscar un producto por su código
void buscarProductoCodigo() {
    archivoProducto obj1;
    int num;

    // Solicita el código del producto a buscar
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> num;

    // Busca el registro del producto por el código especificado
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Producto no encontrado" << endl; // Mensaje si el producto no se encuentra
        return;
    }

    // Lee el registro del producto en la posición especificada
    Producto obj;
    obj = obj1.leerRegistro(pos);

    // Muestra los datos del producto
    obj.mostrarP();
}

// Función para buscar un producto por su categoría
void buscarProductoCategoria(){
    archivoProducto obj1;
    Producto obj;
    char categoria[50];
    cout << "Ingrese la categoria del producto a buscar: 1.Papeleria || 2.Salsa || 3.Fritos || 4.Bebidas || 5.Carnes || 6.Panes" << endl;
    cin.ignore();
    cin.getline(categoria, 50);
    int cant = obj1.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj1.leerRegistro(i);
        if (strcmp(obj.getCategoria(), categoria) == 0 && obj.getEstado() == true) {
            obj.mostrarP();
        }
    }
}

// Función para buscar un producto por su precio
void buscarProductoPrecio(){
    archivoProducto obj1;
    Producto obj;
    float precio;
    cout << "Ingrese el precio del producto a buscar: ";
    cin >> precio;
    int cant = obj1.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj1.leerRegistro(i);
        if (obj.getPrecio() == precio && obj.getEstado() == true) {
            obj.mostrarP();
        }else if(obj.getPrecio() != precio){
            cout << "Producto no encontrado" << endl;
        }
    }
}

// Función para limpiar el archivo de productos
void limpiarProducto() {
    archivoProducto obj1;

    // Llama a la función para limpiar el archivo de productos
    obj1.limpiarArchivo();

    cout << "Archivo de productos borrado" << endl; // Mensaje si el archivo se borró
}

// Función para buscar un producto por su código
#endif // FUNCIONESPRODUCTO_H_INCLUDED