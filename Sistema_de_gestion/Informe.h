#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
#include <cstring>
#include "./clases/Venta.cpp"
#include "./archivos/archivoVentas.h"
#include "./clases/Fecha.h"

///void recauAnual(){
///    archivoVenta arcVentas("Venta.dat");
///    Venta vent;
///    Fecha fec;
///    int recauMes[12]= {};
///    int cont = arcVentas.contarRegistros();
///    for(int i=0; i<cont; i++){
///        arcVentas.leerRegistro(i);
///        vent.getTotal();
///        system("Pause");
///        int mes = vent.getFecha().getMes();
///         recauMes[mes - 1] += vent.getTotal();
///    }
///    for (int mes = 0; mes < 12; mes++) {
///        cout << "Total del mes " << mes + 1 << ": " << recauMes[mes-1] << endl;
///        system("Pause");
///    }
///}

#endif // INFORME_H_INCLUDED
