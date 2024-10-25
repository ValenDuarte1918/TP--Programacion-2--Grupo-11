#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
        bool esBisiesto();
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        void setDia(int dia){
            if(dia>0 && dia<32){
                this->dia= dia;
            }else{
                this->dia= 1;
            }
        };
        void setMes(int mes){
            if(mes>0 && mes<13){
                this->mes= mes;
            }else{
                this->mes= 1;
            }
        };
        void setAnio(int anio){
            if(anio>0){
                this->anio= anio;
            }else{
                this->anio= 2021;
            }
        };
        int getDia(){
            return dia;
        };
        int getMes(){
            return mes;
        };
        int getAnio(){
            return anio;
        };
        void mostrarFecha();
        ~Fecha();
        void cargarFecha();
};
void Fecha::cargarFecha(){
    cout << "Ingrese día: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese año: ";
    cin >> anio;
};
void Fecha::mostrarFecha(){
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
};

#endif // CLSFECHA_H_INCLUDED