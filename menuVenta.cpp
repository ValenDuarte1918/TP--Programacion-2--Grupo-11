#include <iostream>
#include <cstring>
#include "./funciones/funcionesVenta.h"

using namespace std;

void menuVenta(){
    while (true) {
        int opc;
        system("cls");
        cout << "Menu de Venta" << endl;
        cout << "1. Cargar Venta" << endl;
        cout << "2. Baja Venta" << endl;
        cout << "3. Modificar Vemta" << endl;
        cout << "4. Listar Venta" << endl;
        cout << "5. Limpiar Venta" << endl;
        cout << "0. Volver al Menu" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                altaVenta();
                break;
            case 2:
                bajaVenta();
                break;
            case 3:
                modificarVenta();
                break;
            case 4:
                listarVenta();
                break;
            case 5:
                limpiarVenta();
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
