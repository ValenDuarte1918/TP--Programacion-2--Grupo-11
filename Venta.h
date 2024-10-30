#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

//#include "../clases/clsEmpleado.cpp"

class Venta{
    protected:
       // Empleado _empleado;   Composición: objeto de la clase Empleado 
        int _codEmpleado, _codVenta, _formaPago, _fecha, _total;
        float _precioUnitario;
        
    public:
        //Venta();
        Venta(/*Empleado empleado , */ int ce=0, int cv=0, int fp=0, int f=0, int t=0, float pu=0);
       // : _empleado(empleado)
        ///Getters
       // Empleado getEmpleado() { return _empleado; }
        int getCodEmpleado() { return _codEmpleado; }
        int getCodVenta() { return _codVenta; }
        int getFormaPago() { return _formaPago; }
        int getFecha() { return _fecha; }
        int getTotal() { return _total; }
        float getPrecioUnitario() { return _precioUnitario; }
        
        ///Setters
        //void setEmpleado(Empleado empleado){ _empleado=empleado; }
        void setCodEmpleado(int ce){ _codEmpleado=ce; }
        void setCodVenta(int cv){ _codVenta=cv; }
        void setFormaPago(int fp){ _formaPago=fp; }
        void setFecha(int f){ _fecha=f; }
        void setTotal(int t){ _total=t; }
        void setPrecioUnitario(float pu){ _precioUnitario=pu; }
        
        void cargarV();
        void mostrarV();
};

#endif // VENTA_H_INCLUDED
