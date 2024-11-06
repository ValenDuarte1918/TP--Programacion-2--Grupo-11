#include <iostream>
#include <cstring>
#include "./funciones/funcionesVenta.h"

using namespace std;

#include "rlutil.h"

void selectVenta(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}

void menuVenta(){
    int contVent=0;
    system("cls");
    while (true) {
        rlutil::locate(52,4);
        cout << " Menu de Venta" << endl;
        selectVenta(" Cargar  Venta",52,6);
        selectVenta("  Baja  Venta",52,7);
        selectVenta("Modificar Venta",52,8);
        selectVenta(" Listar  Venta",52,9);
        selectVenta(" Limpiar Venta",52,10);
        selectVenta(" Volver a Menu",52,11);
        rlutil::locate(50,6+contVent);
        cout<<(char)62<<endl;
        int opc=rlutil::getkey();
        switch (opc){
          case 14:
          rlutil::locate(50,6+contVent);
          cout<<" "<<endl;
          contVent--;
          if(contVent<0) contVent=0;
          break;
          case 15:
          rlutil::locate(50,6+contVent);
          cout<<" "<<endl;
          contVent++;
          if(contVent>5) contVent=5;
          break;
          case 1:
            system("cls");
            switch(contVent){
             case 0:
                altaVenta();
                system("pause");
                system("cls");
                break;
             case 1:
                bajaVenta();
                system("pause");
                system("cls");
                break;
             case 2:
                modificarVenta();
                system("pause");
                system("cls");
                break;
             case 3:
                listarVenta();
                system("pause");
                system("cls");
                break;
             case 4:
                limpiarVenta();
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
