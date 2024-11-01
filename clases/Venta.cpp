# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>

using namespace std;
# include "Venta.h"
# include "fecha.h"

Venta::Venta(){
    Fecha aux(0,0,0);
    _codEmpleado=0;
    _codVenta=0;
    _formaPago=0;
    _fecha=aux;
    _total=0;
    _precioUnitario=0;
}

Venta::Venta(int ce, int cv, int fp, Fecha f, int t, float pu){
    _codEmpleado=ce;
    _codVenta=cv;
    _formaPago=fp;
    _fecha=f;
    _total=t;
    _precioUnitario=pu;
}

void Venta::cargarV(){
    cout<<"\n Ingrese Codigo Empleado: \n";
    cin>>_codEmpleado;
    cout<<"\n Ingrese Codigo Venta: \n";
    cin>>_codVenta;
    cout<<"\n Ingrese Forma de Pago: ";
    cin>>_formaPago;
    cout<<"\n Ingrese Fecha: ";
    _fecha.cargarFecha();
    cout<<"\n Ingrese Total: ";
    cin>>_total;
    cout<<"\n Precio Unitario: ";
    cin>>_precioUnitario;
}

void Venta::mostrarV(){
    cout<<"\n Codigo Empleado: "<<_codEmpleado;
    cout<<"\n Codigo Venta: "<<_codVenta;
    cout<<"\n Forma de Pago: "<<_formaPago;
    cout<<"\n Fecha: ";
    _fecha.mostrarFecha();
    cout<<"\n Total: $"<<_total;
    cout<<"\n Precio Unitario: $"<<_precioUnitario;
}