#ifndef ARCHIVOEMPLEADO_H_INCLUDED
#define ARCHIVOEMPLEADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "../clases/clsEmpleado.cpp"

using namespace std;

class archivoEmpleado{
    private:
        char nombre[50];
    public:
    archivoEmpleado(const char *nombre= "empleado.dat"){strcpy(this->nombre, nombre);}
        void limpiarArchivo();
        void grabarRegistro(Empleado obj);
        void modificarRegistro(Empleado obj, int pos);
        void listarRegistros();
        int contarRegistros();
        int buscarRegistro(int num);
        Empleado leerRegistro(int pos);
};
 void archivoEmpleado::limpiarArchivo(){
    FILE *p= fopen(nombre, "wb");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fclose(p);
 };
void archivoEmpleado::grabarRegistro(Empleado obj){
    FILE *p= fopen(nombre, "ab");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    };
void archivoEmpleado::modificarRegistro(Empleado obj, int pos){
    FILE *p= fopen(nombre, "rb+");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fseek(p, pos*sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
};
void archivoEmpleado::listarRegistros(){
    int cant= contarRegistros();
    Empleado obj;
        for (int i=0; i<cant; i++){
            obj= leerRegistro(i);
            obj.mostrar();
        }
};
int archivoEmpleado::contarRegistros(){
    FILE *p= fopen(nombre, "rb");
        if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cant= ftell(p)/sizeof(Empleado);
    fclose(p);
    return cant;
};
Empleado archivoEmpleado::leerRegistro(int pos){
    FILE *p= fopen(nombre, "rb");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return Empleado();
        }
    Empleado obj;
    fseek(p, pos*sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
};
int archivoEmpleado::buscarRegistro(int num){
    int cant= contarRegistros();
    Empleado obj;
        for (int i=0; i<cant; i++){
            obj= leerRegistro(i);
                if(obj.getDni()==num){
                    return i;
                }
        }
    return -1;
};

#endif // ARCHIVOEMPLEADO_H_INCLUDED