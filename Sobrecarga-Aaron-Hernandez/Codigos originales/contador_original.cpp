/*
// contador_inc_bug.cpp
#include <iostream>
using namespace std;

class Contador {
    int valor;
public:
    Contador(int v) : valor(v) {}
    Contador operator++(int) {
        valor++;
        return *this;  // BUG: ¿qué comportamiento falla?
    }
};
*/