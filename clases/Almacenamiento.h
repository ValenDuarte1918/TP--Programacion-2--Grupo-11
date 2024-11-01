#ifndef ALMACENAMIENTO_H_INCLUDED
#define ALMACENAMIENTO_H_INCLUDED

#include"Producto.h"


class Almacenamiento{
    protected:
        int _stock;
        Producto _producto;
    public:
        Almacenamiento();
        Almacenamiento(int s, Producto p);
        void mostrarA();
        void cargarA();
        ///Getters
        int getStock(){ return _stock; }
        Producto getProducto () { return _producto; }
        
        ///Setters
        void setStock(int s){ _stock=s; }
        void setProducto(Producto p){ _producto=p; }
};

#endif // ALMACENAMIENTO_H_INCLUDED
