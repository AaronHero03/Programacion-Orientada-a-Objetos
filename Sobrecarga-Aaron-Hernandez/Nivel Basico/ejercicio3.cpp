#include <iostream>
using namespace std;

class Empleado {
public:
    string nombre;
    int id;
    Empleado(string n, int i) : nombre(n), id(i) {}
    friend ostream& operator<<(ostream& os, const Empleado& e){
        os << "ID = " << e.id << ", Nombre = " << e.nombre;
        return os;
    }
};

int main() {
    Empleado e("Ana", 101);
    cout << e << endl;  // Empleado[101]: Ana
    Empleado a("Matias", 202);
    cout << a << endl;
    return 0;
}