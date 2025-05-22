#include <iostream>
using namespace std;

class Persona {
protected:
    string nombre;
public:
    Persona(const string& nombre) : nombre(nombre) {}
};

class Cliente : protected Persona {
public:
    Cliente(const string& n) : Persona(n) {}
    void mostrar() {
        cout << "Nombre del cliente: " << nombre << endl; // Error si se cambia a private
    }
};

int main() {
    Cliente c("Aaron");
    c.mostrar();
    return 0;
}