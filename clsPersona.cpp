#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#include "clsFecha.cpp"


#include <iostream>
#include <cstring>

class Persona {
    private: 
        char nombre[50];
        char apellido[50];
        int dni;
        Fecha fechaNacimiento;

    public:
        Persona();
        Persona(char nombre[], char apellido[], int dni);
        void setNombre(char nombre[]);
        void setApellido(char apellido[]);
        void setDni(int dni);
        void setFechaNacimiento(Fecha fechaNacimiento);
        char* getNombre();
        char* getApellido();
        int getDni();
        void mostrarDatos();
        ~Persona();
        void cargar();
        void mostrar();
};

// Implementación de los métodos
void Persona::cargar() {
    std::cout << "Ingrese nombre: ";
    std::cin.getline(nombre, 50);
    std::cout << "Ingrese apellido: ";
    std::cin.getline(apellido, 50);
    std::cout << "Ingrese dni: ";
    std::cin >> dni;
    std::cin.ignore(); // Para ignorar el salto de línea que queda en el buffer
    fechaNacimiento.cargarFecha();
}

void Persona::mostrar() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << "Dni: " << dni << std::endl;
}

#endif // CLSPERSONA_H_INCLUDED



















