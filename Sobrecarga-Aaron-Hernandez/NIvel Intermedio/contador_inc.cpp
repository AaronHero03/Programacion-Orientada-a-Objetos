#include <iostream>

using namespace std;

class Contador {
private:
    int valor;
public:
    Contador(int v) : valor(v) {}
    Contador operator++(int) {
        Contador copia = *this;
        valor++;
        return copia;
    }
    int get() const { return valor; }
};

int main() {
    Contador cnt(7);
    Contador old = cnt++;
    cout << "Old: " << old.get() << ", New: " << cnt.get() << endl;

    return 0;
}