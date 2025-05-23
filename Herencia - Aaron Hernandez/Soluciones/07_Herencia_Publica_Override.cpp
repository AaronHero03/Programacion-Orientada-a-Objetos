#include <iostream>
#include <string>
using namespace std;

class Instrumento {
public:
    string nombre;

    Instrumento(const string& nom) : nombre(nom) {}
    
    virtual void tocar() {
        cout << nombre << " esta sonando" << endl;
    }

    virtual ~Instrumento() {} // Destructor virtual
};

class Guitarra : public Instrumento {
public:

    Guitarra() : Instrumento("Guitarra") {}

    void tocar() override {
        cout << nombre << " esta sonando" << endl;
        cout << "Chan chan chan" << endl << endl;
    }
};

void probar(Instrumento* inst) {
    inst->tocar();
}

int main() {
    Instrumento sax("Saxofon");
    Instrumento *piano = new Instrumento("Piano"); 

    Guitarra g;
    probar(&g);
    probar(&sax);
    probar(piano);

    delete piano; // Liberar memoria del objeto Instrumento creado dinámicamente
    return 0;
}