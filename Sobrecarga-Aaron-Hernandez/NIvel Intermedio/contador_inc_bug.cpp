// contador_inc_bug.cpp
#include <iostream>
using namespace std;

class Contador {
    int valor;
public:
    Contador(int v) : valor(v) {}
    Contador operator++(int) {
        Contador copia = *this;
        valor++;
        return copia;  // BUG: ¿qué comportamiento falla?
    }
};