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
#include "menuProductos.h"
#include "menuConfiguraciones.h"
#include "Informe.h"
#include "rlutil.h"

void menus(bool opc2);
void informe(bool opc3);
void selector(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}
int main (){
    rlutil::hidecursor();
    int cont=0;
    system("cls");
    while (true) {
      rlutil::setColor(3);
      bool opc2=true;
      bool opc3=true;
        selector("    Menus",58,8);
        selector("   Informe",58,9);
        selector("Configuracion",58,10);
        selector("    Salir",58,11);
        selector(">",56,8+cont);
        int opc = rlutil::getkey();
        switch(opc){
        case 14:
          selector(" ",56,8+cont);
          cont--;
          if(cont<0) cont=0;
          break;
        case 15:
          selector(" ",56,8+cont);
          cont++;
          if(cont>3) cont=3;
          break;
        case 1:
          system("cls");
          if(cont==0){
            menus(opc2);
          }else if(cont==1){
            informe(opc3);
          }else if(cont==2){
            menuConfiguraciones();
          }else if(cont==3){
            return 0;
          }
          break;
        }
    }
}
void menus(bool opc2){
  int contMenu=0;
  system("cls");
  while(opc2!=false){
    selector("  Menu Persona",56,8);
    selector(" Menu Empleados",56,9);
    selector("Menu Proveedores",56,10);
    selector("   Menu Venta",56,11);
    selector(" Menu Productos",56,12);
    selector(" Menu Principal",56,13);
    selector(">",54,8+contMenu);
   int menu=rlutil::getkey();
   switch(menu){
    case 14:
      selector(" ",54,8+contMenu);
      contMenu--;
      if(contMenu<0) contMenu=0;
     break;
    case 15:
      selector(" ",54,8+contMenu);
      contMenu++;
      if(contMenu>5) contMenu=5;
     break;
    case 1:
      system("cls");
      switch(contMenu){
        case 0:
        menuPersona();
        break;
        case 1:
        menuEmpleado();
        break;
      case 2:
        menuProveedor();
        break;
      case 3:
        menuVenta();
        break;
      case 4:
        menuProductos();
        break;
      case 5:
        opc2=false;
        break;
      }
      break;
   }
   }
}

void informe(bool opc3){
  int contInfo=0;
  system("cls");
while(opc3!=false){
    selector("  Recaudacion Anual",56,8);
    selector("Recaudacion  Empleados",56,9);
    selector("Producto mas consumido",56,10);
    selector("        Salir",56,11);
    selector(">",54,8+contInfo);
  int info= rlutil::getkey();
  switch(info){
  case 14:
    selector(" ",54,8+contInfo);
    contInfo--;
    if(contInfo<0) contInfo =0;
   break;
  case 15:
    selector(" ",54,8+contInfo);
    contInfo++;
    if(contInfo>3) contInfo =3;
   break;
  case 1:
  system("cls");
  switch(contInfo){
    case 0:
      recauAnual();
      system("cls");
      break;
    case 1:
      recauEmp();
      system("cls");
      break;
    case 2:
      producMasConsum();
      system("cls");
      break;
    case 3:
    opc3=false;
    break;
      }
      break;
    }
  }
}
