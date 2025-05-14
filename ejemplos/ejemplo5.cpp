#include <iostream>
#include <cstring>
using namespace std;

class Cadena {
private:
    char* texto;
public:
    Cadena(const char* t) {
        texto = new char[strlen(t)+1];
        strcpy(texto, t);
    }

    ~Cadena() {
        delete[] texto;
    }

    Cadena& operator=(const Cadena& otra) {
        if (this != &otra) {
            delete[] texto;
            texto = new char[strlen(otra.texto)+1];
            strcpy(texto, otra.texto);
        }
        return *this;
    }

    void mostrar() {
        cout << "Texto: " << texto << endl;
    }
};

int main() {
    Cadena a("Hola"), b("Adios");
    a = b;
    a.mostrar();  // Texto: Adios
}