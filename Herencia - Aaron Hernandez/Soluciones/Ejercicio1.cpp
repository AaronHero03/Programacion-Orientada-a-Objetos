#include <iostream>

using namespace std;

class Animal{
    public:
    void comer(){
        cout << "El animal esta comiendo..." << endl;
    }
};

class Perro: public Animal{
    public:
    void ladrar(){
        cout << "Guaus..." << endl;
    }
};

int main(){

    Perro miPerro;
    miPerro.comer();
    miPerro.ladrar();
    return 0;
}
