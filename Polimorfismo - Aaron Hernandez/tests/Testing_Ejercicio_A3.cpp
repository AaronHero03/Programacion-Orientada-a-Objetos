#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}

void test_ejercicio_a3(){
    cout << "Prueba Ejercicio 3" << endl << endl;

    // Test1: Suma de matrices
    MatrixOp a(2, 2), b(2, 2), c(2, 2), d(2,2);

    a.set(0, 0, 1.0); b.set(0, 0, 2.0);
    a.set(1, 1, 3.0); b.set(1, 1, 5.0);

    a.apply(&a, &b, &c, sub);
    a.apply(&a, &b, &d, mul);

    if(c.get(0, 0) == -1 && c.get(1, 1) == -2){            
        cout << "Test 1. Pasado" << endl;
    }
    else{
        cerr << "Test 1. Fallado";
    }
    
    if(d.get(0, 0) == 2 && d.get(1, 1) == 15){            
        cout << "Test 2. Pasado" << endl;
    }
    else{
        cerr << "Test 2. Fallado";
    }
}

int main(){
    test_ejercicio_a3();

    return 0;
}