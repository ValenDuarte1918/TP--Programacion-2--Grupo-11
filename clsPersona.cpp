#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#include "clsFecha.cpp"


#include <iostream>
#include <cstring>

using namespace std;

class Persona {
    private: 
        char nombre[50];
        char apellido[50];
        int dni;
        Fecha fechaNacimiento;
        bool estado;

    public:
        Persona(){estado = true;}
        void setDni(int d){dni=d;};
        void setEstado(bool e){estado = e;};
        void setFechaNacimiento(Fecha f){fechaNacimiento = f;};
        int getDni(){return dni;};
        bool getEstado(){return estado;};
       
        void cargar();
        void mostrar();
};

// Implementación de los métodos
void Persona::cargar() {
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese DNI: ";
    cin >> dni;
    fechaNacimiento.cargarFecha();
}

void Persona::mostrar() {
    if  (estado == true){   
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "DNI: " << dni << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrarFecha();
    cout << endl;
    }
}

#endif // CLSPERSONA_H_INCLUDED



















