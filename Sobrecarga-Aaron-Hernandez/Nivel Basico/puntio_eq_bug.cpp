// punto_eq_bug.cpp
#include <iostream>
using namespace std;

class Punto {
public:
    int x, y;
    Punto(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(const Punto& p) {
        return x == p.x && y == p.y;  // BUG: ¿qué no está bien?
    }
};