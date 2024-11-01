# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>

using namespace std;

#include "Venta.h"
#include "DetalleVenta.h"

DetalleVenta::DetalleVenta(int cdv, int cp, int cantp, bool e){
    _codDetalleVenta=cdv;
    _codProducto=cp;
    _cantProducto=cantp;
    _estado=e;
}

void DetalleVenta::mostrarDV(){
    cout<<"\n Codigo Detalle Venta: "<<_codDetalleVenta;
    cout<<"\n Codigo Producto: "<<_codProducto;
    cout<<"\n Cantidad de Producto: "<<_cantProducto;
    cout<<"\n Estado: "<<_estado;
}

void DetalleVenta::cargarDV(){
    cout<<"\n Ingrese Codigo Detalle Venta: ";
    cin>>_codDetalleVenta;
    cout<<"\n Ingrese Codigo Producto: ";
    cin>>_codProducto;
    cout<<"\n Ingrese Cantidad de Producto: ";
    cin>>_cantProducto;
    cout<<"\n Ingrese Estado: ";
    cin>>_estado;
    
}

