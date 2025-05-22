#include <iostream>
using namespace std;

class Sensor {
protected:
    void detectarMovimiento() {
        cout << "Movimiento detectado" << endl;
    }
public:
    Sensor() {
        cout << "Sensor inicializado" << endl;
    }
};

class SistemaAlarma : private Sensor {
public:
    SistemaAlarma() : Sensor() {
        cout << "Sistema de alarma creado" << endl;
    }
    void verificar() {
        detectarMovimiento();
        cout << "Sistema de alarma activado" << endl;
    }
};

int main() {
    SistemaAlarma sa;
    sa.verificar();
    return 0;
}