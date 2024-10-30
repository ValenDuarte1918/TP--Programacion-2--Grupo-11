#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED

class DetalleVenta: public Venta{   // Donde se hereda de la clase Venta?
    protected:
        int _codDetalleVenta, _codProducto, _cantProducto;
        bool _estado;
        
    public:
        DetalleVenta(int cdv=0, int cp=0, int cantp=0, bool e=false);
        void cargarDV();
        void mostrarDV();
    ///Getters
        int getCodDetalleVenta() { return _codDetalleVenta; }
        int getCodProducto() { return _codProducto; }
        int getCantProducto() { return _cantProducto; }
        bool getEstado() { return _estado; }
    ///Setters
        void setCodDetalleVenta(int cdv) { _codDetalleVenta=cdv; }
        void setCodProducto(int cp) { _codProducto=cp; }
        void setCantProducto(int cp) { _cantProducto=cp; }
        void setEstado(bool e) { _estado=e; }
};

#endif // DETALLEVENTA_H_INCLUDED
