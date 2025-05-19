// complejo_bug.cpp
#include <iostream>
using namespace std;

class Complejo {
public:
    double re, im;
    Complejo(double r, double i);
    // BUG: firma incorrecta y falta const
    Complejo operator+(const Complejo& otro) {
        return Complejo(re + otro.im, im + otro.re);
    }
};