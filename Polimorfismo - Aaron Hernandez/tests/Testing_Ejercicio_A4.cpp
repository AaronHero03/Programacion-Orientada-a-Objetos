#include "MatrixOp.h"
#include <iostream>

using namespace std;

void test_ejercicio_a4(){
    cout << "Prueba Ejercicio A4" << endl << endl;

    // Test1: Suma de matrices
    MatrixOp a(2, 2);

    a.set(0, 0, 1.0); a.set(0, 1, 2.0);
    a.set(1, 0, 3.0); a.set(1, 1, 5.0);

    a.forEachDiagonal(&MatrixOp::printAt);

    cout << "Test 4. Pasado" << endl;
}

int main(){
    test_ejercicio_a4();
    return 0;
}