#pragma once
using namespace std;
#include "fecha.h"

class Venta {
  private:
    int _codEmpleado;
    int _codVenta;
    int _formaPago;
    Fecha _fecha;
    float _total;
    float _precioUnitario;
    char _Producto[50];
    int _numProd;
    bool _estado;
  public:
    Venta(){
    Fecha aux(0,0,0); _codEmpleado=0, _codVenta=0, _formaPago=0,_fecha=aux, _total=0, _precioUnitario=0,_Producto[50]={},_numProd=0, _estado = true;};
    ///Setters
    void setCodEmpleado(int ce){ _codEmpleado=ce; }
    void setCodVenta(int cv){ _codVenta=cv; }
    void setFormaPago(int fp){ _formaPago=fp; }
    void setFecha(Fecha f){ _fecha=f; }
    void setTotal(int t){ _total=t; }
    void setPrecioUnitario(float pu){ _precioUnitario=pu; }
    void setNumPorduct(int np){_numProd=np;}
    void setEstado(bool est){ _estado = est; }
    ///Getters
    int getCodEmpleado() { return _codEmpleado; }
    int getCodVenta() { return _codVenta; }
    int getFormaPago() { return _formaPago; }
    Fecha getFecha() { return _fecha; }
    int getTotal() { return _total; }
    float getPrecioUnitario() { return _precioUnitario; }
    char* getProducto(){return _Producto;}
    int getNumProduct(){return _numProd;}
    bool getEstado() { return _estado; }
    void cargar();
    void mostrar();
    };

void Venta::cargar() {
    cout<<"Ingrese Codigo Empleado:"<<endl;
    cin>>_codEmpleado;
    cout<<"Ingrese Codigo Venta:"<<endl;
    cin>>_codVenta;
    cout<<"Ingrese Forma de Pago: "<<endl;
    cin>>_formaPago;
    cout<<"Ingrese Fecha: "<<endl;
    _fecha.cargarFecha();
    cout<<"Ingrese Total: "<<endl;
    cin>>_total;
    cout<<"Precio Unitario: "<<endl;
    cin>>_precioUnitario;

    const char* productos[] = {"Pizza", "Hamburguesa", "Empanadas","Sandwich","Coca cola","Helado","Pepsi","Licuado","Agua","Nuggets","Nachos","Papas","Ensalada","Cafe"};
    int opcionProd = sizeof(productos) / sizeof(productos[0]);
    cout << "Seleccione el producto:\n";
    for (int i = 0; i < opcionProd; ++i) {
      cout << i + 1 << ". " << productos[i] << endl;}
    int op;
    cout<<"Ingrese Producto: "<<endl;
    cin>>op;
    cin.ignore();
    if (op < 1 || op > opcionProd) {
      cout << "Opci�n inv�lida. Producto no cargado." << endl;
      strcpy(_Producto, "Sin asignar");
    } else {
      _numProd=op;
      strcpy(_Producto, productos[op - 1]);
    }
    _estado=true;
}

void Venta::mostrar() {
    cout<<"Codigo Empleado: "<<getCodEmpleado()<<endl;
    cout<<"Codigo Venta: "<<getCodVenta()<<endl;
    cout<<"Forma de Pago: "<<getFormaPago()<<endl;
    cout<<"Fecha: ";
    _fecha.mostrarFecha();
    cout<<"Total: $"<<getTotal()<<endl;
    cout<<"Precio Unitario: $"<<getPrecioUnitario()<<endl;
    cout<<"Producto: "<<_Producto<<endl;
}
