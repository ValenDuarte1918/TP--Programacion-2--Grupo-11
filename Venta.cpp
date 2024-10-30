# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>

using namespace std;
# include "Venta.h"

Venta::Venta(/*Empleado empleado , */int ce, int cv, int fp, int f, int t, float pu){
    //_empleado=empleado;
    _codEmpleado=ce;
    _codVenta=cv;
    _formaPago=fp;
    _fecha=f;
    _total=t;
    _precioUnitario=pu;

}

void Venta::cargarV(){
    // int codEmpleado
    cout<<"\n Ingrese Codigo Empleado: \n";
    // cin>> codEmpleado
    // _empleado.setCodEmpleado(codEmpleado);
    cin>>_codEmpleado; // eliminar esta linea
    cout<<"\n Ingrese Codigo Venta: \n";
    cin>>_codVenta;
    cout<<"\n Ingrese Forma de Pago: ";
    cin>>_formaPago;
    cout<<"\n Ingrese Fecha: ";
    cin>>_fecha;
    cout<<"\n Ingrese Total: ";
    cin>>_total;
    cout<<"\n Precio Unitario: ";
    cin>>_precioUnitario;
}

void Venta::mostrarV(){
    cout<<"\n Codigo Empleado: "<<_codEmpleado;  // _empleado.getCodEmpleado();
    cout<<"\n Codigo Venta: "<<_codVenta;
    cout<<"\n Forma de Pago: "<<_formaPago;
    cout<<"\n Fecha: "<<_fecha;
    cout<<"\n Total: $"<<_total;
    cout<<"\n Precio Unitario: $"<<_precioUnitario;
}