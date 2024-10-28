#ifndef CLSPROVEEDOR_H_INCLUDED
#define CLSPROVEEDOR_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;

class Proveedor{
    private:
        int codProveedor;
        char razonSocial[50];
        char direccion[50];
        int telefono;
        bool estado;
    public:
        Proveedor(){estado = false;};
        void setCodProveedor(int codProveedor){codProveedor = codProveedor;};
        void setRazonSocial(char razonSocial[]){razonSocial = razonSocial;};
        void setDireccion(char direccion[]){direccion = direccion;};
        void setTelefono(int telefono){telefono = telefono;};
        void setEstado(bool estado){estado = estado;};
        int getCodProveedor(){return codProveedor;};
        char* getRazonSocial(){return razonSocial;};
        char* getDireccion(){return direccion;};
        int getTelefono(){return telefono;};
        bool getEstado(){return estado;};

        void cargar();
        void mostrar();
};

// Implementación de los métodos
void Proveedor::cargar() {
    cout << "Ingrese código de proveedor: ";
    cin >> codProveedor;
    cin.ignore();
    cout << "Ingrese razón social: ";
    cin.getline(razonSocial, 50);
    cout << "Ingrese dirección: ";
    cin.getline(direccion, 50);
    cout << "Ingrese teléfono: ";
    cin >> telefono;
    cout << "Ingrese estado (1: activo, 0: inactivo): ";
    cin >> estado;
    cin.ignore();
};
void Proveedor::mostrar() {
    cout << "Código de proveedor: " << codProveedor << endl;
    cout << "Razón social: " << razonSocial << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
};

#endif // CLSPROVEEDOR_H_INCLUDED