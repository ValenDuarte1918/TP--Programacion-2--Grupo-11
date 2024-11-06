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
    cout<<"\n Ingreso de Codigo Producto: \n";
    cin>>_codProd;
    cout<<"\n Ingreso de Nombre: \n";
    cin.ignore();
    cin.getline(_nombre, 20);

    // lista de categorias predefinidas
    const char* categorias[] = {"Papeleria", "Salsa", "Fritos", "Bebidas", "Carnes","Panes"};
    int numCategorias = sizeof(categorias) / sizeof(categorias[0]);
    // Mostrar opciones de categorias
    cout << "Seleccione la categoria:\n";
    for (int i = 0; i < numCategorias; ++i) {
        cout << i + 1 << ". " << categorias[i] << endl;
    }
    int opcion;
    cout<<"\n Ingrese Categoria de producto: \n";
    cin>>opcion;
    cin.ignore();
    // validar la opcion ingresada
    if (opcion < 1 || opcion > numCategorias) {
        cout << "Opcion invalida. Categoria no asignada." << endl;
        strcpy(_categoria, "Sin asignar");
    } else {
        strcpy(_categoria, categorias[opcion - 1]);
    }
    cout<<"\n Ingreso de Precio: \n";
    cin>>_precio;
    cout<<"\n Ingreso de Estado: \n" ;
    cin>>_estado;
}

void Producto::mostrarP(){
    cout<<"\n Codigo Producto: "<<_codProd;
    cout<<"\n Nombre: "<<_nombre;
    cout<<"\n Categoria: "<<_categoria;
    cout<<"\n Precio: "<<_precio << endl;
}
