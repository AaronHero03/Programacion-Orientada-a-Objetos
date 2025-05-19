#include <iostream>
using namespace std;

class Vehiculo {
public:
    void encender() {
        cout << "Vehículo encendido" << endl;
    }
};

class Coche : private Vehiculo {
    public:
        void encender() {
            Vehiculo::encender();
        }
};

int main() {
    Coche miCoche;
    miCoche.encender(); // ¿Por qué falla?
    return 0;
}