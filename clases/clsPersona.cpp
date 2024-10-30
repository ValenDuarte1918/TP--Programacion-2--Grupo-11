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
        Fecha fechaNacimiento; // Objeto de la clase Fecha
        bool estado; 

    public:
        Persona(){estado = true;} // Constructor que inicializa el estado a true
        void setNombre(char n[]){strcpy(nombre, n);}; // Establece el nombre
        void setApellido(char a[]){strcpy(apellido, a);}; // Establece el apellido
        void setDni(int d){dni=d;}; // Establece el DNI
        void setEstado(bool e){estado = e;}; // Establece el estado
        void setFechaNacimiento(Fecha f){fechaNacimiento = f;}; // Establece la fecha de nacimiento
        int getDni(){return dni;}; // Obtiene el DNI
        bool getEstado(){return estado;}; // Obtiene el estado
       
  
      void cargar(); // Metodo para cargar los datos de la persona
        void mostrar(); // Metodo para mostrar los datos de la persona
};

// Implementacion de los metodos
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


















