#ifndef MENU_CONFIGURACIONES_H
#define MENU_CONFIGURACIONES_H
#include "./funciones/funcionesConfiguracion.h"
#include <iostream>

using namespace std;

void menuConfiguraciones()
{
    while (true){
        int opc;
        system("cls");
        cout<<"MENU DE CONFIGURACIONES"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1- Copia de seguridad Ventas"<<endl;
        cout<<"2- Restaurar copia de seguridad Ventas"<<endl;
        cout<<"3- Copia de seguridad Empleados"<<endl;
        cout<<"4- Restaurar copia de seguridad Empleados"<<endl;
        cout<<"5- Copia de seguridad Productos"<<endl;
        cout<<"6- Restaurar copia de seguridad Productos"<<endl;
        cout<<"0- Volver al menu principal"<<endl;
        cout<<"<----------------------->"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                copiaSeguridadVentas();
                break;
            case 2:
                restaurarCopiaSeguridadVentas();
                break;
            case 3:
                copiaDeSeguridadEmpleados();
                break;
            case 4:
                restaurarCopiaDeSeguridadEmpleados();
                break;
            case 5:
                copiaDeSeguridadProductos();
                break;
            case 6:
                restaurarCopiaDeSeguridadProductos();
                break;
            case 0:
                return;
            default:
                cout<<"Opcion incorrecta"<<endl;
                break;
        }








    }
}










#endif // MENU_CONFIGURACIONES_H