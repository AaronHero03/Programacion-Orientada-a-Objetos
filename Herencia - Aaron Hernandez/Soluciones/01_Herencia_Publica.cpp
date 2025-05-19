#include <iostream>
#include <string>

using namespace std;

class Animal{
    public:
    string nombre;
    string especie;

    Animal(const string& es, const string& nom) : especie(es), nombre(nom) { }

    void comer(){
        cout << nombre << " el " << especie << " esta comiendo..." << endl;
    }
};

class Perro: public Animal{
    public:

    Perro(const string& nom) : Animal("Perro", nom){}

    void ladrar(){
        cout << nombre << " dice: Guaus..." << endl;
    }
};

int main(){
    Animal miAnimal("Ornitorrinco", "Perry");
    miAnimal.comer();

    Perro miPerro("Toby");
    miPerro.comer();
    miPerro.ladrar();
    return 0;
}
