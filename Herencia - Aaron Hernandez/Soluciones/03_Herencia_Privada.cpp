#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
public:
    string marca;
    string tipo;

    Vehiculo(const string& m, const string& t): marca(m), tipo(t) { }

    void encender() {
        cout << tipo << " se ha encendido" << endl;
    }

    void mostrarDatos() {
        cout << "Marca: " << marca << endl;
        cout << "Tipo: " << tipo << endl;
    }
};

class Coche : private Vehiculo {
public:
    Coche(const string& m) : Vehiculo(m, "Carro") { }
    
    void encender() {
        Vehiculo::encender();
    }

    void mostrarDatos() {
        Vehiculo::mostrarDatos();
    }
};

int main() {
    Coche miCoche("Ford");
    miCoche.encender(); // ¿Por qué falla?
    miCoche.mostrarDatos(); // ¿Por qué falla?
    return 0;
}