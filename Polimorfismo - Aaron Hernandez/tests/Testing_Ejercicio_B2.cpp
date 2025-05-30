#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_ejercicio_b2(){
    cout << "Prueba Ejercicio B2. Funcion plantilla maxValue" << endl << endl;

    MatrixOp M(2, 3);

    M.set(0, 0, 1.0);
    M.set(0, 1, 10.5);
    M.set(0, 2, 3.0);
    M.set(1, 0, -4.0);
    M.set(1, 1, 8.0);
    M.set(1, 2, 2.5);

    double max_elem = maxValue<double>(M.getData(), M.getSize());
    assert(max_elem == 10.5);

    cout << "Test 1. Maximo en matriz. Pasado" << endl;

    int arr[] = {4, 8, 2, 9, 1};
    int max_int = maxValue<int>(arr, 5);
    assert(max_int == 9);

    cout << "Test 2. Maximo en arreglo de enteros. Pasado" << endl;
}

int main(){
    test_ejercicio_b2();
    return 0;
}
