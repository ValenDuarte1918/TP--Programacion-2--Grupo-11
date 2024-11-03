#include <iostream>
#include <cstring>
using namespace std;

#include "./archivos/archivoEmpleado.h"
#include "./archivos/archivoPersona.h"
#include "./archivos/archivoProveedor.h"
#include "./archivos/archivoVentas.h"
#include "./funciones/funcionesPersona.h"
#include "./funciones/funcionesEmpleado.h"
#include "./funciones/funcionesProveedor.h"
#include "./clases/Venta.cpp"
#include "menuPersona.h"
#include "menuEmpleado.h"
#include "menuProveedor.h"
#include "menuVenta.cpp"
#include "Informe.h"

int main ()
{
    while (true)
    {
        int opc, menu;
        system("cls");
        cout<<"1-Menus"<<endl;
        cout<<"2-Informes"<<endl;
        cout<<"3-Consultas"<<endl;
        cout<<"0-Salir"<<endl;
        cout<<"Ingrese un numero"<<endl;
        cin >> opc;
        system("cls");
        switch (opc){
        case 1:

            cout << "1-Menu de personas" << endl;
            cout << "2-Menu de empleados" << endl;
            cout << "3-Menu de proveedores" << endl;
            cout << "4-Menu de Ventas" << endl;
            cout << "0-Volver al Menu Principal" << endl;
            cout << "Ingrese una opcion: ";
            cin>>menu;
            switch(menu){
            case 1:
                menuPersona();
                break;
            case 2:
                menuEmpleado();
                break;
            case 3:
                menuProveedor();
                break;
            case 4:
               menuVenta();
               break;
            case 0:
             break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
          break;
        case 2:
          ///recauAnual();
          break;
        case 0:
            return 0;
        }
    }
}
