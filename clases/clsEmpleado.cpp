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
        char *getCargo() { return cargo; };

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

  // Lista de cargos predefinidos
    const char* cargos[] = {"Cocinero", "Ayudante de cocina", "Cajero"};
    int numCargos = sizeof(cargos) / sizeof(cargos[0]);

    // Mostrar opciones de cargos
    cout << "Seleccione el cargo:\n";
    for (int i = 0; i < numCargos; ++i) {
        cout << i + 1 << ". " << cargos[i] << endl;
    }

    int opcion;
    cout << "Ingrese el numero del cargo: ";
    cin >> opcion;
    cin.ignore();

    // Validar la opción ingresada
    if (opcion < 1 || opcion > numCargos) {
        cout << "Opción inválida. Cargo no asignado." << endl;
        strcpy(cargo, "Sin asignar");
    } else {
        strcpy(cargo, cargos[opcion - 1]);
    }

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
}

#endif // CLSEMPLADO_H_INCLUDED
