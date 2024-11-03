

# include<iostream>
# include<cstdlib>
# include<stdio.h>
# include<ctime>
# include<cmath>
# include<cstring>


///Ejercicio: Clases

// D - Producto (Sin Iniciar) 
// D - Venta (Sin Iniciar) - Clase Base
// D - Detalle de Venta (Sin Iniciar)
// D - almacenamiento (Sin Iniciar)
///Comentario: Crear las Clases y Comprobar que funcionan.

using namespace std;

#include "Producto.h"
#include "Producto.cpp"
#include "Venta.h"
#include "Venta.cpp"
#include "DetalleVenta.h"
#include "DetalleVenta.cpp"
#include "Almacenamiento.h"
#include "Almacenamiento.cpp"
#include "fecha.h"
#include "clsfecha.cpp"


int main(){
    
    /*cout<<"\n";
    cout<<"Ingreso de Producto: \n";
    Producto obj1;
    //Producto obj2(123,1,"Coca","Bebida",250.5,true);
    //obj1.cargarP();
    cout<<"Valor de Objeto Producto: \n";
    obj1.mostrarP();
    cout<<"\n\n";
    //obj2.mostrarP();*/
    
    cout<<"\n";
    cout<<"Ingrese Venta: \n";
    Venta obj2; 
    //Venta obj3(321,222,1,135,2000,130);
    //obj2.cargarV();
    cout<<"Valor de Objeto Venta: \n";
    obj2.mostrarV();
    cout<<"\n\n";
    //obj3.mostrarV();
    
    /*cout<<"\n";
    cout<<"Ingrese Detalle de Venta: \n";
    DetalleVenta obj3,obj4(333,101,30,1);
    obj3.cargarDV();
    cout<<"Valor de Objeto Detalle de Venta: \n";
    obj3.mostrarDV();
    cout<<"\n\n";
    obj4.mostrarDV();*/
    
    /*cout<<"\n\n";
    cout<<"Ingrese almacenamiento: \n";
    Almacenamiento obj4,obj5(15,obj1);
    //obj4.cargarA();
    cout<<"Valor de Objeto almacenamiento: \n";
    obj4.mostrarA();
    cout<<"\n\n";
    
    obj5.mostrarA();
    cout<<"\n Modificar Producto obj4 \n";
    obj4.cargarA();
    cout<<"\n\n";
    obj4.mostrarA();*/
    
    cout<<"\n\n";
    system("pause");
    return 0;
}