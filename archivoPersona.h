#ifndef   ARCHIVOPERSONA_H_INCLUDED
#define   ARCHIVOPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "./clsPersona.cpp"


using namespace std;


class archivoPersona{
    private:
        char nombre[50];
    public:
    archivoPersona(const char *n= "persona.dat"){strcpy(nombre, n);}
        void limpiarArchivo();
        void grabarRegistro(Persona obj);
        void modificarRegistro(Persona obj, int pos);
        Persona leerRegistro(int pos);
        void listarRegistros();
        int contarRegistros();
        int buscarRegistro(int num);
};

void archivoPersona::limpiarArchivo(){
    FILE *p= fopen(nombre, "wb");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fclose(p);
 }
void archivoPersona::grabarRegistro(Persona obj){
    FILE *p= fopen(nombre, "ab");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    }
void archivoPersona::modificarRegistro(Persona obj, int pos){
    FILE *p= fopen(nombre, "rb+");
        if(p==NULL){
            cout << "Error de apertura de archivo" << endl;
            return;
        }
    fseek(p, pos*sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}
void archivoPersona::listarRegistros(){
    int cant= contarRegistros();
    Persona obj;
        for (int i=0; i<cant; i++){
            obj= leerRegistro(i);
            obj.mostrar();
            if (obj.getEstado()== true){
                cout << "Estado: Activo" << endl;
            }else{
                cout << "Estado: Inactivo" << endl;
            }
        }
    }
int archivoPersona::contarRegistros(){
    FILE *p= fopen(nombre, "rb");
        if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes= ftell(p);
    fclose(p);
    return cantBytes/sizeof(Persona);
}
int archivoPersona::buscarRegistro(int num){
    int cant= contarRegistros();
    Persona obj;
        for (int i=0; i<cant; i++){
            obj= leerRegistro(i);
                if(num == obj.getDni()){
                    return i;
                }
        }
    return -1;
}
Persona archivoPersona::leerRegistro(int pos){
    Persona obj;
    obj.setDni(-1);
    FILE *p= fopen(nombre, "rb");
        if(p==NULL){
            obj.setDni(-2);
            return obj;
        }
    fseek(p, pos*sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

#endif // ARCHIVOPERSONA_H_INCLUDED