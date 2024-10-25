#ifndef ARCHIVOPROVEEDORH_INCLUDED
#define ARCHIVOPROVEEDOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./clsProveedor.cpp"

using namespace std;

class archivoProveedor{
    private:
        char nombre[50];
    public:
    archivoProveedor(const char *nombre= "empleado.dat"){strcpy(this->nombre, nombre);}
        void limpiarArchivo();
        void grabarRegistro(Proveedor obj);
        void modificarRegistro(Proveedor obj, int pos);
        void listarRegistros();
        int contarRegistros();
        int buscarRegistro(int num);
        Proveedor leerRegistro(int pos);
};
 void archivoProveedor::limpiarArchivo(){
    FILE *p= fopen(nombre, "wb");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fclose(p);
 };
void archivoProveedor::grabarRegistro(Proveedor obj){
    FILE *p= fopen(nombre, "ab");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    };
void archivoProveedor::modificarRegistro(Proveedor obj, int pos){
    FILE *p= fopen(nombre, "rb+");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fseek(p, pos*sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
};
void archivoProveedor::listarRegistros(){
    int cant= contarRegistros();
    Proveedor obj;
        for (int i=0; i<cant; i++){
            obj= leerRegistro(i);
            obj.mostrar();
        }
};
int archivoProveedor::contarRegistros(){
    FILE *p= fopen(nombre, "rb");
        if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cant= ftell(p)/sizeof(Proveedor);
    fclose(p);
    return cant;
};
int archivoProveedor::buscarRegistro(int num){
    Proveedor obj;
    int cant= contarRegistros();
        for (int i=0; i<cant; i++){
            obj= leerRegistro(i);
                if(obj.getCodProveedor()==num){
                    return i;
                }
        }
    return -1;
};
 Proveedor archivoProveedor::leerRegistro(int pos){
    FILE *p= fopen(nombre, "rb");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return Proveedor();
        }
    Proveedor obj;
    fseek(p, pos*sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
};

#endif // ARCHIVOEMPLEADO_H_INCLUDED