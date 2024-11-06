#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
#include <cstring>
#include "./archivos/archivoVentas.h"
#include "./clases/Venta.cpp"
#include "./archivos/archivoProducto.h"
#include "./clases/Fecha.h"
#include "./clases/Producto.h"
#include "rlutil.h"

void ponerCeroInt(int* cod, int tam){
  for(int i=0;i<tam;i++) cod[i]=0;
}
void ponerCeroFloat(float* cod, int tam){
  for(int i=0;i<tam;i++) cod[i]=0;
}
void colum(char text,int posX,int posY,char textLimit,int limit,int tam){
  for(int i=0;i<tam;i++){
    rlutil::locate(posX+i,posY);
    cout<<text;
    if(i==limit){
      rlutil::locate(posX+i,posY);
      cout<<textLimit;
    }
  }
}

void recauAnual(){
    archivoVenta arcVentas("Venta.dat");
    Venta vent;
    Fecha fec;

    int mes = 0,recauMes[12];
    ponerCeroInt(recauMes,12);
    const char* vMes[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    int cont = arcVentas.contarRegistros();

    for(int i=0; i<cont; i++){
      vent = arcVentas.leerRegistro(i);
      for(int mes=1;mes<=12;mes++){
        if(mes==vent.getFecha().getMes()) recauMes[mes - 1] += vent.getTotal();
      }
    }
    rlutil::locate(51,1);
    cout<<"Recaudacion del Anio"<<endl;
    colum(205,50,2,203,12,22);
    colum(205,50,15,202,12,22);
    for (int mes = 0; mes < 12; mes++) {
      rlutil::locate(51,3+mes);
      cout << vMes[mes];
      rlutil::locate(62,3+mes);
      cout<<(char)186 <<" $" << recauMes[mes] << endl;
    }
    system("Pause");
}

void recauEmp(){
  archivoVenta archiVenta("Venta.dat");
  Venta objVent;

  int numEmp = 0,codEmp, j=0;
  int* vEmp;
  int contReg = archiVenta.contarRegistros();
  int* codEmpleados = new int[contReg];
  float* recaudacionEmpleados = new float[contReg];
  float totalVenta;
  bool busqueda;
  ponerCeroFloat(recaudacionEmpleados,contReg);
  ponerCeroInt(codEmpleados,contReg);

  for (int i = 0; i < contReg; i++) {
    objVent = archiVenta.leerRegistro(i);
    codEmp = objVent.getCodEmpleado();
    totalVenta = objVent.getTotal();
    busqueda = false;
      for (j=0; j < numEmp; j++) {
        if (codEmpleados[j] == codEmp) {
          busqueda = true;
          break;
          }
      }
      if (busqueda!=true) {
        if (numEmp < contReg) {
          codEmpleados[numEmp] = codEmp;
          j = numEmp;
          numEmp++;
          }
      }
      recaudacionEmpleados[j] += totalVenta;
    }
    rlutil::locate(44,1);
    cout<<"Codigo Empleado"<<endl;
    rlutil::locate(60,1);
    cout<<(char)186<<" Recaudacion del Ultimo Mes"<<endl;
    colum(205,43,2,206,17,46);
    for (int i = 0; i < numEmp; i++) {
        rlutil::locate(54,3+i);
        cout <<codEmpleados[i];
        rlutil::locate(60,3+i);
        cout<<(char)186;
        rlutil::locate(62,3+i);
        cout << "$" << recaudacionEmpleados[i] << endl;
    }
    delete[] codEmpleados;
    delete[] recaudacionEmpleados;
    system("Pause");
}

void producMasConsum() {
    archivoVenta archiVenta("Venta.dat");
    Venta ven;
    int cont = archiVenta.contarRegistros();
    const char* nombreProducto[14] = {"Pizza", "Hamburguesa", "Empanadas","Sandwich","Coca cola","Helado","Pepsi","Licuado","Agua","Nuggets","Nachos","Papas","Ensalada","Cafe"};
    int vecProd[14]={},maximo = 0, tipoProduct = 0, produc;
    for (int i = 0;i<cont; i++) {
        ven = archiVenta.leerRegistro(i);
        produc = ven.getNumProduct();
          vecProd[produc-1]++;
        if (i==0) {
            maximo = vecProd[produc-1];;
            tipoProduct = produc;
        }
        if (maximo<vecProd[produc-1]) {
            maximo = vecProd[produc-1];
            tipoProduct = produc;
        }
    }
    rlutil::locate(50,10);
    cout <<(char)186<<" El producto mas consumido: " << nombreProducto[tipoProduct-1] <<" "<<(char)186<< endl;
    system("pause");
}



#endif // INFORME_H_INCLUDED
