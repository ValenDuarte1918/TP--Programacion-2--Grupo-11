#ifndef CLSEMPLADO_H_INCLUDED
#define CLSEMPLADO_H_INCLUDED
#include <iostream>
#include <cstring>
#include "clsPersona.cpp"


using namespace std;
class Empleado : public Persona {
    private:
        int codEmpleado;
        char cargo[50];
        int horasTrabajadas;
        float sueldo;
        bool estado;
    public:
        Empleado(){estado = false;};
        void setCodEmpleado(int codEmpleado){codEmpleado = codEmpleado;};
        void setCargo(char cargo[]){cargo = cargo;};
        void setHorasTrabajadas(int horasTrabajadas){horasTrabajadas = horasTrabajadas;};
        void setSueldo(float sueldo){sueldo = sueldo;};
        void setEstado(bool e){estado=e;};
        int getCodEmpleado(){return codEmpleado;};
        char* getCargo(){return cargo;};
        int getHorasTrabajadas(){return horasTrabajadas;};
        float getSueldo(){return sueldo;};
        bool getEstado(){return estado;};
        
        void cargar();
        void mostrar();
};

// Implementación de los métodos
void Empleado::cargar() {
    Persona::cargar();
    cout << "Ingrese código de empleado: ";
    cin >> codEmpleado;
    cin.ignore();
    cout << "Ingrese cargo: ";
    cin.getline(cargo, 50);
    cout << "Ingrese horas trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese sueldo: ";
    cin >> sueldo;
    cout << "Ingrese estado (1: activo, 0: inactivo): ";
    cin >> estado;
    cin.ignore();
};
void Empleado::mostrar() {
    Persona::mostrar();
    cout << "Código de empleado: " << codEmpleado << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "Horas trabajadas: " << horasTrabajadas << endl;
    cout << "Sueldo: " << sueldo << endl;
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
};

#endif // CLSEMPLADO_H_INCLUDED
