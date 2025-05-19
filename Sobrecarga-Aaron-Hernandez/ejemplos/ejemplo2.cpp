#include <iostream>
using namespace std;

class Libro {
public:
    string titulo;
    Libro(string t) : titulo(t) {}
    bool operator==(const Libro& otro) {
        return titulo == otro.titulo;
    }
};

int main() {
    Libro a("C++ Avanzado"), b("C++ Avanzado");
    cout << "¿Son iguales? " << (a == b ? "Sí" : "No") << endl;
}