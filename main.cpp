#include <iostream>
#include <cstring>


#include "./archivos/archivoEmpleado.h"
#include "./archivos/archivoPersona.h"
#include "./archivos/archivoProveedor.h"
#include "./funciones/funcionesPersona.h"
#include "menuPersona.h"
#include "menuEmpleado.h"




using namespace std;

int main (){
        while (true) {
        int opc;
        system("cls");
        cout << "1-Menu de personas" << endl;
        cout << "2-Menu de empleados" << endl;
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                menuPersona();
                break;
            case 2:
                menuEmpleado();
                break;
            case 0:
                return 0;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }

    
    
    }
}