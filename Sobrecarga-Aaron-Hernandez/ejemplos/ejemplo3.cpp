#include <iostream>
using namespace std;

class Persona {
public:
    string nombre;
    Persona(string n) : nombre(n) {}
    friend ostream& operator<<(ostream& os, const Persona& p) {
        os << "Nombre: " << p.nombre;
        return os;
    }
};

int main() {
    Persona p("Camilo");
    cout << p << endl;
}