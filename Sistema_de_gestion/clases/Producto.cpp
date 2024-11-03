# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>

using namespace std;
#include "Producto.h"

Producto::Producto(int cp, int tp, const char *n, const char *c, float p, bool e){
    _codProducto=cp;
    _tipoProducto=tp;
    strcpy(_nombre, n);
    strcpy(_categoria, c);
    _precio=p;
    _estado=e;
}

void Producto::cargarP(){
    cout<<"\n Ingreso de Codigo Producto: \n";
    cin>>_codProducto;
    cout<<"\n Ingreso de Tipo Producto: \n";
    cin>>_tipoProducto;
    cout<<"\n Ingreso de Nombre: \n";
    cin.ignore();
    gets(_nombre);
    cout<<"\n Ingreso de Categoria: \n";
    gets(_categoria);
    cout<<"\n Ingreso de Precio: \n";
    cin>>_precio;
    cout<<"\n Ingreso de Estado: \n";
    cin>>_estado;
}

void Producto::mostrarP(){
    cout<<"\n Codigo Producto: "<<_codProducto;
    cout<<"\n Tipo Producto: "<<_tipoProducto;
    cout<<"\n Nombre: "<<_nombre;
    cout<<"\n Categoria: "<<_categoria;
    cout<<"\n Precio: "<<_precio;
    cout<<"\n Estado: "<<_estado;
}