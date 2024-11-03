#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>

class Fecha {
private:
    int dia, mes, anio;

    // Método privado para verificar si el año es bisiesto
    bool esBisiesto();

public:
    // Constructor por defecto que inicializa la fecha al 1/1/1900
    Fecha();

    // Constructor parametrizado para inicializar la fecha con valores específicos
    Fecha(int dia, int mes, int anio);

    // Métodos para mostrar y cargar la fecha
    void mostrarFecha();
    void cargarFecha();

    // Métodos setters para establecer los valores de día, mes y año
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    // Métodos getters para obtener los valores de día, mes y año
    int getDia();
    int getMes();
    int getAnio();
};

#endif // FECHA_H_INCLUDED