# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>

using namespace std;

#include "Almacenamiento.h"

#include "Producto.h"

Almacenamiento::Almacenamiento(){
    _stock=0;
    Producto auxP;
    Almacenamiento::setProducto(auxP);
}
Almacenamiento::Almacenamiento(int s, Producto p){
    _stock=s;
    _producto=p;
}

void Almacenamiento::mostrarA(){
    cout<<"\n Stock: "<<_stock;
    _producto.mostrarP();
}

void Almacenamiento::cargarA(){
    cout<<"\n Ingreso de Stock: \n";
    cin>>_stock;
    cout<<"\n Ingreso de Producto: \n";
    _producto.cargarP();
}