#include <iostream>
using namespace std;

class Dispositivo { 
public: 
    string marca; 

};

class Tablet : public virtual Dispositivo {};

class Telefono : public virtual Dispositivo {};

class Smartphone : public Tablet, public Telefono {};

int main() {
    Smartphone s;
    s.marca = "Mi marca";
    cout << s.marca << endl;
    return 0;
}