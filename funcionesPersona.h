#ifndef FUNCIONESPERSONA_H_INCLUDED
#define FUNCIONESPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "archivoPersona.h"

using namespace std;

void listarRegistros(){
    archivoPersona obj1;
    obj1.listarRegistros();
}

void modificarRegistro(){
    archivoPersona obj1 ("persona.dat");
    int num;
    cout << "Ingrese el numero de registro a modificar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj= obj1.leerRegistro(pos);
    char cat[50];
    cout << "Ingrese la nueva categoria: ";
    cin >> cat;
    obj.setNombre(cat);
    obj1.modificarRegistro(obj, pos);
}

void bajaRegistro(){
    archivoPersona obj1;
    int num;
    cout << "Ingrese el numero de DNI a eliminar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj= obj1.leerRegistro(pos);
    obj.setDni(false);
    obj1.modificarRegistro(obj, pos);
}

void altaRegistro(){
    archivoPersona obj1("persona.dat");
    Persona obj;
    obj.cargar();
    int pos= obj1.buscarRegistro(obj.getDni());
    if(pos>=0){
        cout << "Ese DNI ya existe" << endl;
        obj.setDni(false);
    }
    obj1.grabarRegistro(obj);
}

void buscarRegistro(){
    archivoPersona obj1;
    int num;
    cout << "Ingrese el numero de DNI a buscar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj= obj1.leerRegistro(pos);
    obj.mostrar();
}

void limpiarArchivo(){
    archivoPersona obj1;
    obj1.limpiarArchivo();
}

#endif // FUNCIONESPERSONA_H_INCLUDED