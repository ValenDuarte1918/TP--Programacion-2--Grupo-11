#ifndef CLSEMPLADO_H_INCLUDED
#define CLSEMPLADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <locale>
#include "clsPersona.cpp"


using namespace std;
// Definición de la clase Empleado que hereda de la clase Persona
class Empleado : public Persona { 
    private:
        int codEmpleado; 
        char cargo[50]; 
        int horasTrabajadas; 
        float sueldo; 
        bool estado; 
    public:
        // Constructor por defecto que inicializa el estado del empleado a activo
        Empleado() { estado = true; };

        // Métodos setter para establecer los valores de los atributos
        void setCodEmpleado(int codEmp) { codEmpleado = codEmp; };
        void setHorasTrabajadas(int hsTrab) { horasTrabajadas = hsTrab; };
        void setSueldo(float s) { sueldo = s; };
        void setEstado(bool e) { estado = e; };

        // Métodos getter para obtener los valores de los atributos
        int getCodEmpleado() { return codEmpleado; };
        int getHorasTrabajadas() { return horasTrabajadas; };
        float getSueldo() { return sueldo; };
        bool getEstado() { return estado; };

        // Declaración de los métodos cargar y mostrar
        void cargar();
        void mostrar();
};

// Implementación del método cargar
void Empleado::cargar() {
    // Llama al método cargar de la clase base Persona
    Persona::cargar();

    cout << "Ingrese codigo de empleado: ";
    cin >> codEmpleado;
    cin.ignore(); 

    cout << "Ingrese cargo: ";
    cin.getline(cargo, 50);

    cout << "Ingrese horas trabajadas: ";
    cin >> horasTrabajadas;

    cout << "Ingrese sueldo: ";
    cin >> sueldo;

}

// Implementación del método mostrar
void Empleado::mostrar() {
    // Llama al método mostrar de la clase base Persona
    Persona::mostrar();

    cout << "Codigo de empleado: " << codEmpleado << endl;

    cout << "Cargo: " << cargo << endl;

    cout << "Horas trabajadas: " << horasTrabajadas << endl;

    cout << "Sueldo: " << sueldo << endl;

    cout << "Estado: " <<  (estado ? "Activo" : "Inactivo") << endl;
}

#endif // CLSEMPLADO_H_INCLUDED
