#ifndef MENUEMPLEADO_H_INCLUDED
#define MENUEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./funciones/funcionesEmpleado.h"

using namespace std;

void menuEmpleado(){
    while (true) {
        int opc;
        system("cls");
        cout << "Menu de Empleados" << endl;
        cout << "1. Cargar Empleado" << endl;
        cout << "2. Baja Empleado" << endl;
        cout << "3. Modificar Empleado" << endl;
        cout << "4. Listar Empleados" << endl;
        cout << "5. Buscar Empleado por Cargo" << endl;
        cout << "6. Buscar Empleado por DNI" << endl;
        cout << "7. Limpiar Empleados" << endl;
        cout << "0. Volver al Menu" << endl;
        cout << "Ingrese una opción: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                altaEmpleado();
                break;
            case 2:
                bajaEmpleado();
                break;
            case 3:
                modificarEmpleado();
                break;
            case 4:
                listarEmpleado();
                break;
            case 5:
                buscarEmpleadoPorCargo();
                break;
            case 6:
                buscarEmpleado();
                break;
            case 7:
                limpiarArchivo();
                break;
            case 0:
                return;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
        system("pause");
    }
}
#endif // MENUEMPLEADO_H_INCLUDED
