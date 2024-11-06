# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>

using namespace std;
#include "Producto.h"

Producto::Producto(int cp, int tp, const char *n, const char *c, float p, bool e){
    _codProd=cp;
    _tipoProducto=tp;
    strcpy(_nombre, n);
    strcpy(_categoria, c);
    _precio=p;
    _estado=e;
}

void Producto::cargarP(){
    cout<<"Ingreso de Codigo Producto: "<<endl;
    cin>>_codProd;
    cout<<"Ingreso de Nombre: "<<endl;
    cin.ignore();
    cin.getline(_nombre, 20);

    // lista de categorias predefinidas
    const char* categorias[] = {"Papeleria", "Salsa", "Fritos", "Bebidas", "Carnes","Panes"};
    int numCategorias = sizeof(categorias) / sizeof(categorias[0]);
    // Mostrar opciones de categorias
    cout << "Seleccione la categoria:"<<endl;
    for (int i = 0; i < numCategorias; ++i) {
        cout << i + 1 << ". " << categorias[i] << endl;
    }
    int opcion;
    cout<<"Ingrese Categoria de producto: "<<endl;
    cin>>opcion;
    cin.ignore();
    // validar la opcion ingresada
    if (opcion < 1 || opcion > numCategorias) {
        cout << "Opcion invalida. Categoria no asignada." << endl;
        strcpy(_categoria, "Sin asignar");
    } else {
        strcpy(_categoria, categorias[opcion - 1]);
    }
    cout<<"Ingreso de Precio: "<<endl;
    cin>>_precio;
    _estado=true;
}

void Producto::mostrarP(){
    cout<<"Codigo Producto: "<<_codProd;
    cout<<"Nombre: "<<_nombre;
    cout<<"Categoria: "<<_categoria;
    cout<<"Precio: "<<_precio;
    cout<<"Estado: "<<_estado << endl;
    cout<<"<--------------------------------------->"<<endl;
}
