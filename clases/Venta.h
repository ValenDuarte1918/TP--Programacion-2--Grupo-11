#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

# include "fecha.h"

class Venta{
    protected:
        int _codEmpleado, _codVenta, _formaPago, _total;
        Fecha _fecha;
        float _precioUnitario;
        
    public:
        Venta();
        Venta(int ce, int cv, int fp, Fecha f, int t, float pu);
        void cargarV();
        void mostrarV();
        ///Getters
        int getCodEmpleado() { return _codEmpleado; }
        int getCodVenta() { return _codVenta; }
        int getFormaPago() { return _formaPago; }
        Fecha getFecha() { return _fecha; }
        int getTotal() { return _total; }
        float getPrecioUnitario() { return _precioUnitario; }
        
        ///Setters
        void setCodEmpleado(int ce){ _codEmpleado=ce; }
        void setCodVenta(int cv){ _codVenta=cv; }
        void setFormaPago(int fp){ _formaPago=fp; }
        void setFecha(Fecha f){ _fecha=f; }
        void setTotal(int t){ _total=t; }
        void setPrecioUnitario(float pu){ _precioUnitario=pu; }
        
        
};

#endif // VENTA_H_INCLUDED
