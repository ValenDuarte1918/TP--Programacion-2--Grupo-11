#ifndef FUNCIONESPERSONA_H_INCLUDED
#define FUNCIONESPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../archivos/archivoPersona.h"

using namespace std;


// Metodo para listar todos los registros
void listarRegistros(){
    archivoPersona obj1; // Crea un objeto de archivoPersona
    obj1.listarRegistros(); // Llama al metodo listarRegistros del objeto
}

// Metodo para modificar un registro
void modificarRegistro(){
    archivoPersona obj1("persona.dat"); // Crea un objeto de archivoPersona con el nombre del archivo
    int num;
    cout << "Ingrese el numero de DNI a modificar: ";
    cin >> num; // Solicita el DNI a modificar
    int pos = obj1.buscarRegistro(num); // Busca el registro por DNI
    if(pos < 0){ // Verifica si el registro fue encontrado
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj = obj1.leerRegistro(pos); // Lee el registro en la posicion encontrada
    int dni;
    cout << "Ingrese el nuevo DNI: ";
    cin >> dni; // Solicita el nuevo DNI
    obj.setDni(dni); // Establece el nuevo DNI en el objeto
    obj1.modificarRegistro(obj, pos); // Modifica el registro en el archivo
    if (obj.getEstado() == false){ // Verifica si el estado del objeto es falso
        cout << "No se pudo modificar el registro" << endl;
    }
    else{
        cout << "Registro modificado exitosamente." << endl;
    }
}

// Metodo para dar de baja un registro
void bajaRegistro(){
    archivoPersona obj1; // Crea un objeto de archivoPersona
    int num;
    cout << "Ingrese el numero de DNI a eliminar: ";
    cin >> num; // Solicita el DNI a eliminar
    int pos = obj1.buscarRegistro(num); // Busca el registro por DNI
    if(pos < 0){ // Verifica si el registro fue encontrado
        cout << "Registro no encontrado" << endl;
        return;
    }
    Persona obj;
    obj = obj1.leerRegistro(pos); // Lee el registro en la posicion encontrada
    obj.setEstado(false); // Establece el estado del objeto a falso
    obj1.modificarRegistro(obj, pos); // Modifica el registro en el archivo
    cout << "Registro eliminado" << endl;
}

// Metodo para dar de alta un registro
void altaRegistro(){
    archivoPersona obj1("persona.dat"); // Crea un objeto de archivoPersona con el nombre del archivo
    Persona obj;
    obj.cargar(); // Carga los datos del objeto
    int pos = obj1.buscarRegistro(obj.getDni()); // Busca el registro por DNI
    if(pos != -1){ // Verifica si el registro ya existe
        cout << "Ese DNI ya existe" << endl;
        obj.setEstado(false); // Establece el estado del objeto a falso
    }
    if (obj.getEstado() == true){ // Verifica si el estado del objeto es verdadero
        obj1.grabarRegistro(obj); // Graba el registro en el archivo
        cout << "Registro grabado" << endl;
    }else{
        cout << "No se pudo grabar el registro" << endl;
    }
}

// Metodo para buscar un registro por DNI
void buscarRegistro(){
    int num;
    cout << "Ingrese el numero de DNI a buscar: ";
    cin >> num; // Solicita el DNI a buscar
    archivoPersona obj1; // Crea un objeto de archivoPersona
    Persona obj;
    int pos = obj1.buscarRegistro(num); // Busca el registro por DNI
    if(pos < 0){ // Verifica si el registro fue encontrado
        cout << "Registro no encontrado" << endl;
        return;
    }
    obj = obj1.leerRegistro(pos); // Lee el registro en la posicion encontrada
    system("cls"); // Limpia la pantalla
    obj.mostrar(); // Muestra el registro
}

// Metodo para limpiar el archivo
void limpiarArchivo(){
    archivoPersona obj1; // Crea un objeto de archivoPersona
    obj1.limpiarArchivo(); // Llama al metodo limpiarArchivo del objeto
    cout << "Archivo limpiado" << endl;
}


#endif // FUNCIONESPERSONA_H_INCLUDED