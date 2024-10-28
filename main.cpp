#include <iostream>
#include <cstring>


#include "./archivos/archivoEmpleado.h"
#include "./archivos/archivoPersona.h"
#include "./archivos/archivoProveedor.h"
#include "./funciones/funcionesPersona.h"
#include "menuPersona.h"



using namespace std;

int main (){
        while (true) {
        int opc;
        system("cls");
        cout << "1-Menú de personas" << endl;
        cout << "2-Menú de empleados" << endl;
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                menuPersona();
                break;
            case 2:
                break;
            case 0:
                return 0;
            default:
                cout << "Opción incorrecta" << endl;
                break;
        }

    
    
    }
}