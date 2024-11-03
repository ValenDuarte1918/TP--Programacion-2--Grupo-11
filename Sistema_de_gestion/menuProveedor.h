#ifndef MENUPROVEEDOR_H_INCLUDED
#define MENUPROVEEDOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./funciones/funcionesProveedor.h"

using namespace std;

void menuProveedor(){
    while (true) {
        int opc;
        system("cls");
        cout << "Menu de Proveedores" << endl;
        cout << "1. Cargar proveedor" << endl;
        cout << "2. Baja proveedor" << endl;
        cout << "3. Modificar proveedor" << endl;
        cout << "4. Listar proveedor" << endl;
        cout << "5. Limpiar archivo" << endl;
        cout << "0. Volver al Menu" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                altaProveedor();
                break;
            case 2:
                bajaProveedor();
                break;
            case 3:
                modificarProveedor();
                break;
            case 4:
                listarProveedor();
                break;
            case 5:
                limpiarProveedor();
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
#endif // MENUPROVEEDOR_H_INCLUDED
