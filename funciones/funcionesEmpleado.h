#ifndef FUNCIONESEMPLEADO_H_INCLUDED
#define FUNCIONESEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "archivoEmpleado.h"


using namespace std;

void listarRegistros(){
    archivoEmpleado obj1;
    obj1.listarRegistros();
}

void modificarRegistro(){
    archivoEmpleado obj1 ("empleado.dat");
    int num;
    cout << "Ingrese el numero de registro a modificar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }

Empleado obj;
obj= obj1.leerRegistro(pos);
 char cat[50];
cout << "Ingrese la nueva categoria: ";
cin >> cat;
obj.setNombre(cat);
obj1.modificarRegistro(obj, pos);

}

void bajaRegistro(){
    archivoEmpleado obj1;
    int num;
    cout << "Ingrese el numero de registro a eliminar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
Empleado obj;
obj= obj1.leerRegistro(pos);
obj.setEstado(false);
obj1.modificarRegistro(obj, pos);

}

void altaRegistro(){
    archivoEmpleado obj1("empleado.dat");
    Empleado obj;
    obj.cargar();
    int pos= obj1.buscarRegistro(obj.getCodEmpleado());
    if(pos>=0){
        cout << "Ese DNI ya existe" << endl;
        obj.setEstado(false);
    }
    if (obj.getEstado()==true){
        obj1.grabarRegistro(obj);
    }else{
        cout << "No se pudo grabar el registro" << endl;
    }
}

void buscarRegistro(){
    int num;
    cout << "Ingrese el numero de registro a buscar: ";
    cin >> num;
    archivoEmpleado obj1;
    Empleado obj;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    obj= obj1.leerRegistro(pos);
    system("cls");
    obj.mostrar();
}

void limpiarArchivo(){
    archivoEmpleado obj1;
    obj1.limpiarArchivo();
    cout << "Archivo borrado" << endl;
}

#endif // FUNCIONES_H_INCLUDED

