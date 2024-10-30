#ifndef FUNCIONESEMPLEADO_H_INCLUDED
#define FUNCIONESEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../archivos/archivoEmpleado.h"


using namespace std;

    

// Función para listar todos los empleados
void listarEmpleado() {
    archivoEmpleado obj1;
    obj1.listarRegistros(); // Llama a la función para listar todos los registros de empleados
}

// Función para modificar un empleado existente
void modificarEmpleado() {
    archivoEmpleado obj1("empleado.dat");
    int num;

    // Solicita el código del empleado a modificar
    cout << "Ingrese el codigo a modificar: ";
    cin >> num;

    // Busca el registro del empleado por el código especificado
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Codigo no encontrado" << endl; // Mensaje si el código no se encuentra
        return;
    }

    // Lee el registro del empleado en la posición especificada
    Empleado obj;
    obj = obj1.leerRegistro(pos);

    // Solicita el nuevo código del empleado
    int codEmp;
    cout << "Ingrese el nuevo codigo de empleado: ";
    cin >> codEmp;

    // Establece el nuevo código del empleado
    obj.setCodEmpleado(codEmp);

    // Modifica el registro del empleado en la posición especificada
    obj1.modificarRegistro(obj, pos);

    // Verifica si el estado del empleado es falso (no modificado)
    if (obj.getEstado() == false) {
        cout << "No se pudo modificar el registro" << endl; // Mensaje si no se pudo modificar el registro
    } else {
        cout << "Registro modificado exitosamente" << endl; // Mensaje si el registro se modificó exitosamente
    }
}

// Función para dar de baja a un empleado
void bajaEmpleado() {
    archivoEmpleado obj1;
    int num;

    // Solicita el número de registro a eliminar
    cout << "Ingrese el numero de Empleado a eliminar: ";
    cin >> num;

    // Busca el registro del empleado por el número especificado
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Empleado no encontrado" << endl; 
        return;
    }

    // Lee el registro del empleado en la posición especificada
    Empleado obj;
    obj = obj1.leerRegistro(pos);

    // Establece el estado del empleado a falso (eliminado)
    obj.setEstado(false);

    // Modifica el registro del empleado en la posición especificada
    obj1.modificarRegistro(obj, pos);

    cout << "Empleado eliminado" << endl; // Mensaje si el registro se eliminó
}

// Función para dar de alta a un nuevo empleado
void altaEmpleado() {
    archivoEmpleado obj1("empleado.dat");
    Empleado obj;

    // Carga los datos del nuevo empleado
    obj.cargar();

    // Verifica si el código del empleado ya existe
    int pos = obj1.buscarRegistro(obj.getCodEmpleado());
    if (pos != -1) {
        cout << "Ese Codigo de empleado ya existe" << endl; // Mensaje si el código de empleado ya existe
        obj.setEstado(false);
    }

    // Si el estado del empleado es verdadero (nuevo), graba el registro
    if (obj.getEstado() == true) {
        obj1.grabarRegistro(obj);
    } else {
        cout << "No se pudo grabar el registro" << endl; // Mensaje si no se pudo grabar el registro
    }
}

// Función para buscar un empleado por su número
void buscarEmpleado() {
    int num;

    // Solicita el número de empleado a buscar
    cout << "Ingrese el numero de empleado a buscar: ";
    cin >> num;

    archivoEmpleado obj1;
    Empleado obj;

    // Busca el registro del empleado por el número especificado
    int pos = obj1.buscarRegistro(num);
    if (pos < 0) {
        cout << "Empleado no encontrado" << endl; // Mensaje si el registro no se encuentra
        return;
    }

    // Lee el registro del empleado en la posición especificada
    obj = obj1.leerRegistro(pos);

    // Limpia la pantalla y muestra los datos del empleado
    system("cls");
    obj.mostrar();
}

// Función para limpiar el archivo de empleados
void limpiarEmpleado() {
    archivoEmpleado obj1;

    // Llama a la función para limpiar el archivo de empleados
    obj1.limpiarArchivo();

    cout << "Archivo de empleados borrado" << endl; // Mensaje si el archivo se borró
}

void buscarEmpleadoPorCargo(){
    archivoEmpleado obj1;
    Empleado obj;
    char cargo[50];
    cout << "Ingrese el cargo a buscar:  Cocinero || Ayudante de cocina || Cajero" << endl;
    cin.ignore();
    cin.getline(cargo, 50);
    int cant = obj1.contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = obj1.leerRegistro(i);
        if (strcmp(obj.getCargo(), cargo) == 0 && obj.getEstado() == true) {
            obj.mostrar();
        }else{
            cout << "No se encontro ningun empleado con ese cargo" << endl;
        }
    }
}

#endif // FUNCIONESEMPLEADO_H_INCLUDED

