#include <iostream>
#include <string>

using namespace std;

class DIspositivo {
public:
    string marca;
    DIspositivo(const string& m) : marca(m){}
};

class TV : public virtual DIspositivo {
public:
    TV(const string& m) : DIspositivo(m){}
};

class DVD : public virtual DIspositivo {
public:
    DVD(const string& m) : DIspositivo(m){}
};

class ControlRemoto : public TV, public DVD {
public:
    ControlRemoto(const string& m) : DIspositivo(m), TV(m), DVD(m) {
        cout << "Control remoto de marca " << marca << " creado." << endl;
    }
};

int main() {
    ControlRemoto control("Sony");
    cout << "Marca del control remoto: " << control.marca << endl;
    return 0;
}

