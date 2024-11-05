#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
#include <cstring>
#include "./archivos/archivoVentas.h"
#include "./clases/Venta.cpp"
#include "./archivos/archivoProducto.h"
#include "./clases/Fecha.h"
#include "./clases/Producto.h"

void ponerCeroInt(int* cod, int tam){
  for(int i=0;i<tam;i++) cod[i]=0;
}
void ponerCeroFloat(float* cod, int tam){
  for(int i=0;i<tam;i++) cod[i]=0;
}

void recauAnual(){
    archivoVenta arcVentas("Venta.dat");
    Venta vent;
    Fecha fec;
    int mes = 0,recauMes[12];
    ponerCeroInt(recauMes,12);
    int cont = arcVentas.contarRegistros();

    for(int i=0; i<cont; i++){
      vent = arcVentas.leerRegistro(i);
      for(int mes=1;mes<=12;mes++){
        if(mes==vent.getFecha().getMes()) recauMes[mes - 1] += vent.getTotal();
      }

    }
    for (int mes = 0; mes < 12; mes++) {
      cout << "Total del mes " << mes + 1 << ": " << recauMes[mes] << endl;
      system("Pause");
    }
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
    for (int i = 0; i < numEmp; i++) {
        cout << "Empleado con Codigo: " << codEmpleados[i] << ", Recaudacion del ultimo mes: $" << recaudacionEmpleados[i] << endl;
    }
    delete[] codEmpleados;
    delete[] recaudacionEmpleados;
    system("pause");
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
    cout << "El producto más comprado es el tipo: " << nombreProducto[tipoProduct-1] << endl;
    system("pause");
}



#endif // INFORME_H_INCLUDED
