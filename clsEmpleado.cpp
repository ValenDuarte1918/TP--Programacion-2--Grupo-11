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
        Empleado();
        Empleado(char nombre[], char apellido[], int dni, int codEmpleado, char cargo[], int horasTrabajadas, float sueldo, bool estado);
        void setCodEmpleado(int codEmpleado);
        void setCargo(char cargo[]);
        void setHorasTrabajadas(int horasTrabajadas);
        void setSueldo(float sueldo);
        void setEstado(bool e){estado=e;};
        int getCodEmpleado();
        char* getCargo();
        int getHorasTrabajadas();
        float getSueldo();
        bool getEstado();
        void mostrarDatos();
        ~Empleado();
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
