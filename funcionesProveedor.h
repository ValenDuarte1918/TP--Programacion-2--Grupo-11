#ifndef FUNCIONESPROVEEDOR_H_INCLUDED
#define FUNCIONESPROVEEDOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "archivoProveedor.h"

using namespace std;

void listarRegistros(){
    archivoProveedor obj1;
    obj1.listarRegistros();
}

void modificarRegistro(){
    archivoProveedor obj1 ("proveedor.dat");
    int num;
    cout << "Ingrese el numero de registro a modificar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
}

void bajaRegistro(){
    archivoProveedor obj1;
    int num;
    cout << "Ingrese el numero de registro a eliminar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Proveedor obj;
    obj= obj1.leerRegistro(pos);
    obj.setEstado(false);
    obj1.modificarRegistro(obj, pos);
}

void altaRegistro(){
    archivoProveedor obj1("proveedor.dat");
    Proveedor obj;
    obj.cargar();
    int pos= obj1.buscarRegistro(obj.getCodProveedor());
    if(pos>=0){
        cout << "Ese DNI ya existe" << endl;
        obj.setEstado(false);
    }
    obj1.grabarRegistro(obj);
}

void buscarRegistro(){
    archivoProveedor obj1;
    int num;
    cout << "Ingrese el numero de registro a buscar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Proveedor obj;
    obj= obj1.leerRegistro(pos);
    system("cls");
    obj.mostrar();
}

void limpiarArchivo(){
    archivoProveedor obj1;
    obj1.limpiarArchivo();
    cout << "Archivo borrado" << endl;
}

#endif // FUNCIONESPROVEEDOR_H_INCLUDED