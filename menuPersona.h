#ifndef MENUPERSONA_H_INCLUDED
#define MENUPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./funciones/funcionesPersona.h"

using namespace std;

#include "rlutil.h"

void selectPersona(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}

void menuPersona(){
  system("cls");
  int contPers=0;
    while (true) {
        selectPersona("Menu de personas",54,4);
        selectPersona(" Cargar persona",54,6);
        selectPersona("  Baja persona",54,7);
        selectPersona("Modificar persona",54,8);
        selectPersona(" Listar personas",54,9);
        selectPersona(" Limpiar archivo",54,10);
        selectPersona("  Volver a Menu",54,11);
        rlutil::locate(52,6+contPers);
        cout<<(char)62<<endl;
        int opc=rlutil::getkey();
        switch (opc) {
        case 14:
          rlutil::locate(52,6+contPers);
          cout<<" "<<endl;
          contPers--;
          if(contPers<0) contPers=0;
          break;
        case 15:
          rlutil::locate(52,6+contPers);
          cout<<" "<<endl;
          contPers++;
          if(contPers>5) contPers=5;
          break;
        case 1:
          system("cls");
          switch(contPers){
            case 0:
                altaRegistro();
                system("pause");
                system("cls");
                break;
            case 1:
                bajaRegistro();
                system("pause");
                system("cls");
                break;
            case 2:
                modificarRegistro();
                system("pause");
                system("cls");
                break;
            case 3:
                listarRegistros();
                system("pause");
                system("cls");
                break;
            case 4:
                limpiarArchivo();
                system("pause");
                system("cls");
                break;
            case 5:
                return;
          }
        }
    }
}
#endif // MENUPERSONA_H_INCLUDED
