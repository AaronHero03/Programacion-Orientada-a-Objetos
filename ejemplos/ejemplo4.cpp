#include <iostream>
using namespace std;

class Contador {
private:
    int valor;
public:
    Contador(int v) : valor(v) {}
    Contador operator++(int) { // post-incremento
        Contador temp = *this;
        valor++;
        return temp;
    }

    void mostrar() { cout << "Valor: " << valor << endl; }
};

int main() {
    Contador c(10);
    c++;
    c.mostrar(); // 11
}