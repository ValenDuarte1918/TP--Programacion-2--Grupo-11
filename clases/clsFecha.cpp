#include "./Fecha.h"
#include <iostream>

using namespace std;

// Constructor por defecto que inicializa la fecha al 1/1/1900
Fecha::Fecha() : dia(1), mes(1), anio(1900) {}

// Constructor parametrizado para inicializar la fecha con valores específicos
Fecha::Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

// Método privado para verificar si el año es bisiesto
bool Fecha::esBisiesto() {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

// Método para cargar la fecha desde la entrada estándar
void Fecha::cargarFecha() {
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
    cin >> anio;
}

// Método para mostrar la fecha en formato dd/mm/aaaa
void Fecha::mostrarFecha() {
    cout << dia << "/" << mes << "/" << anio << endl;
}

// Métodos setters para establecer los valores de día, mes y año
void Fecha::setDia(int d) {
    dia = d;
}

void Fecha::setMes(int m) {
    if (mes > 0 && mes < 13) {
        mes = m;
    }
}

void Fecha::setAnio(int a) {
    if (a > 0) {
        anio = a;
    }
}

// Métodos getters para obtener los valores de día, mes y año
int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getAnio() {
    return anio;
}