#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;

class Fecha {
private:
    int dia, mes, anio;
    bool esBisiesto();

public:
    Fecha() : dia(1), mes(1), anio(1900) {} // Constructor por defecto
    Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {} // Constructor parametrizado

    void mostrarFecha();
    void cargarFecha();

    void setDia(int dia) {
        this->dia = dia;
    }

    void setMes(int mes) {
        if (mes > 0 && mes < 13) {
            this->mes = mes;
        }
    }

    void setAnio(int anio) {
        if (anio > 0) {
            this->anio = anio;
        }
    }

    int getDia() {
        return dia;
    }

    int getMes() {
        return mes;
    }

    int getAnio() {
        return anio;
    }
};

bool Fecha::esBisiesto() {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

void Fecha::cargarFecha() {
    cout << "Ingrese día: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese año: ";
    cin >> anio;
}

void Fecha::mostrarFecha() {
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
}

#endif // CLSFECHA_H_INCLUDED