#ifndef MENUPRODUCTOS_H_INCLUDED
#define MENUPRODUCTOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "./funciones/funcionesProducto.h"

using namespace std;

void menuProductos(){
    while (true){
        int opc;
        system("cls");
        cout << "Menu de Productos" << endl;
        cout << "1. Cargar Producto" << endl;
        cout << "2. Baja Producto" << endl;
        cout << "3. Modificar Producto" << endl;
        cout << "4. Listar Productos" << endl;
        cout << "5. Limpiar Productos" << endl;
        cout << "6. Buscar Producto por Categoria" << endl;
        cout << "7. Buscar Producto por Codigo" << endl;
        cout << "8. Buscar Producto por Precio" << endl;
        cout << "0. Volver al Menu" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch (opc){
            case 1:
                altaProducto();
                break;
            case 2:
                bajaProducto();
                break;
            case 3:
                modificarProducto();
                break;
            case 4:
                listarProducto();
                break;
            case 5:
                limpiarProducto();
                break;
            case 6:
                buscarProductoCategoria();
                break;
            case 7:
                buscarProductoCodigo();
                break;
            case 8:
                buscarProductoPrecio();
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

#endif // MENUPRODUCTOS_H_INCLUDED