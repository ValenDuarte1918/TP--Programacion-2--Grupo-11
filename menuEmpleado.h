#ifndef MENUEMPLEADO_H_INCLUDED
#define MENUEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./funciones/funcionesEmpleado.h"

using namespace std;

#include "rlutil.h"

void selectEmpleado(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}

void menuEmpleado(){
  system("cls");
  int contEmp=0;
    while (true) {
       selectEmpleado("Menu de Empleados",54,4);
       selectEmpleado("Cargar Empleado",54,6);
       selectEmpleado("Baja Empleado",54,7);
       selectEmpleado("Modificar Empleado",54,8);
       selectEmpleado("Listar Empleados",54,9);
       selectEmpleado("Buscar Empleado por Cargo",54,10);
       selectEmpleado("Buscar Empleado por DNI",54,11);
       selectEmpleado("Limpiar Empleados",54,12);
       selectEmpleado("Volver al Menu",54,13);
       selectEmpleado(">",52,6+contEmp);
       int opc=rlutil::getkey();
       switch (opc) {
         case 14:
           selectEmpleado(" ",52,6+contEmp);
           contEmp--;
           if(contEmp<0) contEmp=0;
          break;
         case 15:
           selectEmpleado(" ",52,6+contEmp);
           contEmp++;
           if(contEmp>7) contEmp=7;
          break;
         case 1:
          system("cls");
           switch(contEmp){
             case 0:
               altaEmpleado();
               system("pause");
                system("cls");
               break;
           case 1:
               bajaEmpleado();
               system("pause");
                system("cls");
               break;
           case 2:
               modificarEmpleado();
               system("pause");
                system("cls");
               break;
           case 3:
               listarEmpleado();
               system("pause");
                system("cls");
               break;
           case 4:
               buscarEmpleadoPorCargo();
               system("pause");
                system("cls");
               break;
           case 5:
               buscarEmpleado();
               system("pause");
                system("cls");
               break;
           case 6:
               limpiarArchivo();
               system("pause");
                system("cls");
               break;
           case 7:
               return;
           }
          break;
       }
    }
}
#endif // MENUEMPLEADO_H_INCLUDED
