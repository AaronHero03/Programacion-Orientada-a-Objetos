#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
    string especie;

    Animal(const string& es) : especie(es) { }

    void comer(){
        cout << especie << " esta comiendo..." << endl;
    }
};

class Perro: public Animal{
    public:

    Perro() : Animal("Perro") { }

    void ladrar(){
        cout << "Guaus..." << endl;
    }
};

int main(){
    Animal miAnimal("Perry el ornitorrinco");
    miAnimal.comer();

    Perro miPerro;
    miPerro.comer();
    miPerro.ladrar();
    return 0;
}
