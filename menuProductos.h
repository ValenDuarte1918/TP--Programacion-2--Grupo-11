#ifndef MENUPRODUCTOS_H_INCLUDED
#define MENUPRODUCTOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdio>
#include "./funciones/funcionesProducto.h"

using namespace std;

#include "rlutil.h"

void selectProducto(const char* text, int posX, int posY){
  rlutil::locate(posX,posY);
  cout<<text<<endl;
}

void menuProductos(){
  system("cls");
  int contProd=0;
  while (true){
    selectProducto("      Menu de Productos",54,4);
    selectProducto("       Cargar Producto",54,6);
    selectProducto("        Baja Producto",54,7);
    selectProducto("     Modificar  Producto",54,8);
    selectProducto("      Listar  Productos",54,9);
    selectProducto("      Limpiar Productos",54,10);
    selectProducto("Buscar Producto por Categoria",54,11);
    selectProducto(" Buscar Producto por Codigo",54,12);
    selectProducto(" Buscar Producto por Precio",54,13);
    selectProducto("        Volver a Menu",54,14);
    selectProducto(">",52,6+contProd);
    int opc=rlutil::getkey();
    switch (opc){
      case 14:
      selectProducto(" ",52,6+contProd);
        contProd--;
        if(contProd<0) contProd=0;
        break;
      case 15:
      selectProducto(" ",52,6+contProd);
        contProd++;
        if(contProd>8) contProd=8;
        break;
      case 1:
        system("cls");
        switch(contProd){
          case 0:
            altaProducto();
            system("pause");
              system("cls");
            break;
          case 1:
            bajaProducto();
            system("pause");
              system("cls");
            break;
          case 2:
            modificarProducto();
            system("pause");
              system("cls");
            break;
          case 3:
            listarProducto();
            system("pause");
              system("cls");
            break;
          case 4:
            limpiarProducto();
            system("pause");
              system("cls");
            break;
          case 5:
            buscarProductoCategoria();
            system("pause");
              system("cls");
            break;
          case 6:
            buscarProductoCodigo();
            system("pause");
                system("cls");
            break;
         case 7:
            buscarProductoPrecio();
            system("pause");
                system("cls");
            break;
          case 8:
            return;
        }
        break;

    }
    }
}

#endif // MENUPRODUCTOS_H_INCLUDED
