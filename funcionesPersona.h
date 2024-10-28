#ifndef FUNCIONESPERSONA_H_INCLUDED
#define FUNCIONESPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "archivoPersona.h"

using namespace std;

void listarRegistros(){
    archivoPersona obj1;
    obj1.listarRegistros();
}

void modificarRegistro(){
    archivoPersona obj1 ("persona.dat");
    int num;
    cout << "Ingrese el numero de DNI a modificar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num);
    if(pos<0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj= obj1.leerRegistro(pos);
    int dni;
    cout << "Ingrese el nuevo DNI: ";
    cin >> dni;
    obj.setDni(dni);
    obj1.modificarRegistro(obj, pos);
    if (obj.getEstado()== false){
        cout << "No se pudo modificar el registro" << endl;
    }
    else{
        cout << "Registro modificado exitosamente." << endl;
    }
}

void bajaRegistro(){
    archivoPersona obj1;
    int num;
    cout << "Ingrese el numero de DNI a eliminar: ";
    cin >> num;
    int pos = obj1.buscarRegistro(num);
    if(pos < 0){
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj = obj1.leerRegistro(pos);
    obj.setEstado(false);
    obj1.modificarRegistro(obj, pos);
    cout << "Registro eliminado" << endl;
}

void altaRegistro(){
    archivoPersona obj1("persona.dat");
    Persona obj;
    obj.cargar();
    int pos= obj1.buscarRegistro(obj.getDni());
    if(pos!= -1){
        cout << "Ese DNI ya existe" << endl;
        obj.setEstado(false);
    }
    if (obj.getEstado()== true){
        obj1.grabarRegistro(obj);
        cout << "Registro grabado" << endl;
    }else{
        cout << "No se pudo grabar el registro" << endl;
    }
}

void buscarRegistro(){
    int num;
    cout << "Ingrese el numero de DNI a buscar: ";
    cin >> num;
    archivoPersona obj1;
    Persona obj;
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
    archivoPersona obj1;
    obj1.limpiarArchivo();
    cout << "Archivo limpiado" << endl;
}

#endif // FUNCIONESPERSONA_H_INCLUDED