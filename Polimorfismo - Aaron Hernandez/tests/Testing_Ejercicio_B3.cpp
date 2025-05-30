#include "MatrixOp.h"
#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;

void test_ejercicio_b3(){
    cout << "Prueba Ejercicio B3. Herencia y determinante" << endl << endl;

    // Test 1: Matriz 2x2
    IMatrix *mat2x2 = new MatrixOp(2, 2);
    dynamic_cast<MatrixOp*>(mat2x2)->set(0, 0, 3);
    dynamic_cast<MatrixOp*>(mat2x2)->set(0, 1, 8);
    dynamic_cast<MatrixOp*>(mat2x2)->set(1, 0, 4);
    dynamic_cast<MatrixOp*>(mat2x2)->set(1, 1, 6);

    double det2x2 = mat2x2->determinant();
    assert(det2x2 == (3 * 6 - 8 * 4));

    cout << "Test 1. Determinante 2x2. Pasado" << endl;

    delete mat2x2;

    // Test 2: Matriz 3x3
    MatrixOp mat3x3(3, 3);
    mat3x3.set(0, 0, 6); mat3x3.set(0, 1, 1); mat3x3.set(0, 2, 1);
    mat3x3.set(1, 0, 4); mat3x3.set(1, 1, -2); mat3x3.set(1, 2, 5);
    mat3x3.set(2, 0, 2); mat3x3.set(2, 1, 8); mat3x3.set(2, 2, 7);

    double det3x3 = mat3x3.determinant();
    double expected_det = 6*(-2*7) + 1*5*2 + 1*4*8 - 1*(-2)*2 - 1*4*7 - 6*5*8;

    assert(fabs(det3x3 - expected_det) < 1e-9);

    cout << "Test 2. Determinante 3x3. Pasado" << endl;

    // Test 3: Dimensiones no soportadas
    try{
        MatrixOp mat4x4(4, 4);
        mat4x4.determinant();
        assert(false);
    }
    catch(const std::logic_error&){
        cout << "Test 3. Matriz no soportada. Pasado" << endl;
    }
}

int main(){
    test_ejercicio_b3();
    return 0;
}
