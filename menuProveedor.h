#ifndef MENUPROVEEDOR_H_INCLUDED
#define MENUPROVEEDOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./funciones/funcionesProveedor.h"

using namespace std;

#include "rlutil.h"

void selectProveedor(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}

void menuProveedor(){
  system("cls");
    int contProv=0;
    while (true) {
      selectProveedor("Menu de Proveedores",54,4);
      selectProveedor(" Cargar  proveedor",54,6);
      selectProveedor("  Baja proveedor",54,7);
      selectProveedor("Modificar proveedor",54,8);
      selectProveedor(" Listar  proveedor",54,9);
      selectProveedor("  Limpiar archivo",54,10);
      selectProveedor("   Volver a Menu",54,11);
      selectProveedor(">",52,6+contProv);
      //cout <<  << endl;
      int opc=rlutil::getkey();
      switch (opc) {
        case 14:
        selectProveedor(" ",52,6+contProv);
        contProv--;
        if(contProv<0) contProv=0;
        break;
        case 15:
        selectProveedor(" ",52,6+contProv);
        contProv++;
        if(contProv>5) contProv=5;
        break;
        case 1:
          system("cls");
          switch(contProv){
          case 0:
              altaProveedor();
              system("pause");
                system("cls");
              break;
          case 1:
              bajaProveedor();
              system("pause");
                system("cls");
              break;
          case 2:
              modificarProveedor();
              system("pause");
                system("cls");
              break;
          case 3:
              listarProveedor();
              system("pause");
                system("cls");
              break;
          case 4:
              limpiarProveedor();
              system("pause");
                system("cls");
              break;
          case 5:
              return;
          }
        break;
      }
    }
}
#endif // MENUPROVEEDOR_H_INCLUDED
