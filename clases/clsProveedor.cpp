#include <iostream>
#include <cstring>
#include "clsPersona.cpp"

using namespace std;

// Clase Proveedor que hereda de Persona
class Proveedor: public Persona {
    private:
        char nombre[50];
        char apellido[50];
        int codProveedor;
        char razonSocial[50];
        char direccion[50];
        int telefono;
        bool estado;
    public:
        // Constructor que inicializa el estado a true
        Proveedor(){estado = true;};

        // Métodos setters
        void setCodProveedor(int codProv){codProveedor = codProv;};
        void setRazonSocial(char razon[]) { strcpy(this->razonSocial, razon); }
        void setDireccion(char dir[]) { strcpy(this->direccion, dir); }
        void setTelefono(int t){telefono = t;};
        void setEstado(bool e){estado = e;};

        // Métodos getters
        int getCodProveedor(){return codProveedor;};
        char* getRazonSocial(){return razonSocial;};
        char* getDireccion(){return direccion;};
        int getTelefono(){return telefono;};
        bool getEstado(){return estado;};

        // Métodos para cargar y mostrar datos
        void cargar();
        void mostrar();
};

// Implementación del método cargar
void Proveedor::cargar() {
    cout << "Ingrese nombre: ";
    setNombre(nombre); // Llama al método de la clase base para establecer el nombre
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    setApellido(apellido); // Llama al método de la clase base para establecer el apellido
    cin >> apellido;

    cout << "Ingrese codigo de proveedor: ";
    cin >> codProveedor;
    cin.ignore();
    cout << "Ingrese razon social: ";
    cin.getline(razonSocial, 50);
    cout << "Ingrese direccion: ";
    cin.getline(direccion, 50);
    cout << "Ingrese telefono: ";
    cin >> telefono;
};

// Implementación del método mostrar
void Proveedor::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Codigo de proveedor: " << codProveedor << endl;
    cout << "Razon social: " << razonSocial << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
};