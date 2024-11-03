#ifndef MENUPERSONA_H_INCLUDED
#define MENUPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./funciones/funcionesPersona.h"

using namespace std;

void menuPersona(){
    while (true) {
        int opc;
        system("cls");
        cout << "Menu de personas" << endl;
        cout << "1. Cargar persona" << endl;
        cout << "2. Baja persona" << endl;
        cout << "3. Modificar persona" << endl;
        cout << "4. Listar personas" << endl;
        cout << "5. Limpiar archivo" << endl;
        cout << "0. Volver al Menu" << endl;
        cout << "Ingrese una opción: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                altaRegistro();
                break;
            case 2:
                bajaRegistro();
                break;
            case 3:
                modificarRegistro();
                break;
            case 4:
                listarRegistros();
                break;
            case 5:
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
#endif // MENUPERSONA_H_INCLUDED
