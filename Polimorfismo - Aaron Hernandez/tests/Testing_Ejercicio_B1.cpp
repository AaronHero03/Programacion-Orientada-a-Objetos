#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_ejercicio_b1(){
    cout << "Prueba Ejercicio B1. Sobrecarga de operadores" << endl << endl;

    MatrixOp A(2, 2), B(2, 2);

    A.set(0, 0, 1.0); B.set(0, 0, 2.0);
    A.set(0, 1, 3.0); B.set(0, 1, 4.0);
    A.set(1, 0, 5.0); B.set(1, 0, 6.0);
    A.set(1, 1, 7.0); B.set(1, 1, 8.0);

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    // Verificar resultados esperados
    assert(C.get(0, 0) == 3.0 && C.get(1, 1) == 15.0);
    assert(D.get(0, 1) == -1.0 && D.get(1, 0) == -1.0);

    cout << "Test 1. Suma y resta. Pasado" << endl;

    // Test de dimensiones incompatibles
    try{
        MatrixOp E(3, 3);
        MatrixOp F = A + E;
        assert(false); // No debe llegar aquí
    }
    catch(const std::invalid_argument&){
        cout << "Test 2. Dimensiones incompatibles. Pasado" << endl;
    }
}

int main(){
    test_ejercicio_b1();
    return 0;
}
