#include "MatrixOp.h"
#include <cassert>
#include <iostream>

using namespace std;

void test_ejercicio_a2(){
    cout << "Prueba Ejercicio 2" << endl << endl;

    // Test1: Suma de matrices
    try{
        MatrixOp a(2, 2), b(2, 2), c(2, 2);

        a.set(0, 0, 1.0); b.set(0, 0, 2.0);
        a.set(1, 1, 3.0); b.set(1, 1, 5.0);
        a.add(&b, &c);

        if(c.get(0, 0) == 3.0 && c.get(1, 1) == 8.0){            
            cout << "Test 1. Pasado" << endl;
        }
        else{
            cerr << "Test 1. Fallado";
        }
    }
    catch(const std::invalid_argument&){
        cerr << "Test 1. Fallado. Argumentos Invalidos";
    }
}

int main(){
    test_ejercicio_a2();

    return 0;
}