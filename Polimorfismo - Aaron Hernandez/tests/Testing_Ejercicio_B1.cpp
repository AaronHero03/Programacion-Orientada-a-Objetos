#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_constructor(){
    
    cout << "Prueba Ejercicio 1. Constructor" << endl << endl;

    // Test 1: Creacion  // Verifica que la matriz sea de las dimensiones indicadas    
    MatrixOp mat(2, 3);
    assert(mat.getRows() == 2 && mat.getCols() == 3);
    cout << "Test 1. Pasado" << endl;

    // Test 2: Set y get
    mat.set(0, 1, 5.5);
    assert(mat.get(0, 1) == 5.5);
    cout << "Test 2. Pasado" << endl;

    // Test 3: 
    try{
        mat.set(10, 0, 2); // Debe mostrar un error
        assert(false);
    } catch(const std::out_of_range&){    
        cout << "Test 3. Pasado" << endl;
    }
}

void test_destructor(){
    cout << endl << "Prueba Ejercicio 1. Destructor" << endl << endl;
    MatrixOp* mat = new MatrixOp(10, 10);
    delete mat;
    cout << "Destructor. Test 1. Pasado" << endl;
}

int main(){
    test_constructor();
    test_destructor();

    return 0;
}