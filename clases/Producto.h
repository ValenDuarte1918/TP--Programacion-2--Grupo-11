#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED


class Producto{
    protected:
        int _tipoProducto, _codProducto;
        char _nombre[20], _categoria[20];
        float _precio;
        bool _estado;
        
    public:
        
        Producto(int cp=0, int tp=0, const char *n="", const char *c="", float p=0, bool e=false);
        void cargarP();
        void mostrarP();
        ///Getters
        int getCodProducto() { return _codProducto; }
        int getTipoProducto() { return _tipoProducto; }
        const char *getNombre() { return _nombre; }
        const char *getCategoria() { return _categoria; }
        float getPrecio() { return _precio; }
        bool getEstado() { return _estado; }
        
        ///Setters
        void setCodProducto(int cp){_codProducto=cp;} 
        void setTipoProducto(int tp){ _tipoProducto=tp; }
        void setNombre(char *n){ strcpy(_nombre, n); }
        void setCategoria(char *c){ strcpy(_categoria, c); }
        void setPrecio(float p){ _precio=p; }
        void setEstado(bool e){ _estado=e; }
        
        
};

#endif // PRODUCTO_H_INCLUDED
