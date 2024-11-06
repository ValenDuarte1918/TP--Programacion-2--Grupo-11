#ifndef MENU_CONFIGURACIONES_H
#define MENU_CONFIGURACIONES_H
#include "./funciones/funcionesConfiguracion.h"
#include <iostream>

using namespace std;

#include "rlutil.h"

void selectConfig(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}

void menuConfiguraciones(){
  system("cls");
  int contConfig=0;
    while (true){
        selectConfig("      MENU DE CONFIGURACIONES",54,4);
        selectConfig("     Copia de seguridad Ventas",54,6);
        selectConfig("Restaurar copia de seguridad Ventas",54,7);
        selectConfig("     Copia de seguridad Empleados",54,8);
        selectConfig("Restaurar copia de seguridad Empleados",54,9);
        selectConfig("     Copia de seguridad Productos",54,10);
        selectConfig("Restaurar copia de seguridad Productos",54,11);
        selectConfig("       Volver al menu principal",54,12);
        selectConfig(">",52,6+contConfig);
        int opc=rlutil::getkey();
        switch(opc){
        case 14:
          selectConfig(" ",52,6+contConfig);
          contConfig--;
          if(contConfig<0) contConfig=0;
          break;
        case 15:
          selectConfig(" ",52,6+contConfig);
          contConfig++;
          if(contConfig>6) contConfig=6;
          break;
        case 1:
          system("cls");
          switch(contConfig){
            case 0:
                copiaSeguridadVentas();
                break;
            case 1:
                restaurarCopiaSeguridadVentas();
                break;
            case 2:
                copiaDeSeguridadEmpleados();
                break;
            case 3:
                restaurarCopiaDeSeguridadEmpleados();
                break;
            case 4:
                copiaDeSeguridadProductos();
                break;
            case 5:
                restaurarCopiaDeSeguridadProductos();
                break;
            case 6:
                return;
          }
          break;
        }
    }
}

#endif // MENU_CONFIGURACIONES_H
