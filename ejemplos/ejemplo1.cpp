#include <iostream>
using namespace std;

class Punto {
public:
    int x, y;
    Punto(int x, int y) : x(x), y(y) {}
    Punto operator+(const Punto& otro) {
        return Punto(x + otro.x, y + otro.y);
    }
};

int main() {
    Punto p1(2, 3), p2(4, 1);
    Punto resultado = p1 + p2;
    cout << "Resultado: (" << resultado.x << ", " << resultado.y << ")" << endl;
}