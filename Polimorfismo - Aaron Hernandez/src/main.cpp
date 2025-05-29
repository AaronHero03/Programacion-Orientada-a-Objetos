#include "MatrixOp.h"
#include <iostream>

using namespace std;

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}

int main() {
    // MatrixOp matriz(5, 2);

    // matriz.set(0, 1, 5);
    // cout << matriz.get(0, 1) << endl;

    // MatrixOp A(1, 3);
    // MatrixOp B(1, 3);
    // MatrixOp C(1, 3);
    // MatrixOp D(1, 3);

    // // Llenar manualmente A
    // A.set(0, 0, 1);
    // A.set(0, 1, 2);
    // A.set(0, 2, 3);

    // // Llenar manualmente B
    // B.set(0, 0, 7);
    // B.set(0, 1, 8);
    // B.set(0, 2, 9);

    // A.add(&B, &C);

    // cout << C.get(0, 0) << endl;
    // cout << C.get(0, 1) << endl;
    // cout << C.get(0, 2) << endl;

    // A.apply(&A, &B, &C, sub);
    // A.apply(&A, &B, &D, mul);

    // cout << C.get(0, 0) << endl;
    // cout << C.get(0, 1) << endl;
    // cout << C.get(0, 2) << endl;

    // cout << D.get(0, 0) << endl;
    // cout << D.get(0, 1) << endl;
    // cout << D.get(0, 2) << endl;
    
    // // Ejercicio 4

    MatrixOp M(3, 3);

    // Llenar manualmente M
    M.set(0, 0, 5);
    M.set(0, 1, 2);
    M.set(0, 2, 8);

    M.set(1, 0, 7);
    M.set(1, 1, 9);
    M.set(1, 2, 6);
    
    M.set(2, 0, 1);
    M.set(2, 1, 6);
    M.set(2, 2, 3);

    M.forEachDiagonal(&MatrixOp::printAt);

    MatrixOp A(2,2), B(2,2);
    
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);
    
    MatrixOp C = A + B;
    MatrixOp D = A - B;

    // Mostrar resultados
    std::cout << "C[0,0] = " << C.get(0,0) << "\n";
    std::cout << "D[1,1] = " << D.get(1,1) << "\n";

    double maxElem = maxValue<double>(M.data_, M.rows * M.cols);
    std::cout << "Máximo elemento de M: " << maxElem << "\n";

    IMatrix *mat = new MatrixOp(2,2);
    
    if (auto m = dynamic_cast<MatrixOp*>(mat)) {
        m->set(0, 0, 5);
        m->set(0, 1, 2);
        m->set(1, 0, 7);
        m->set(1, 1, 9);
    }
    

    std::cout << "Determinante: " << mat->determinant() << "\n";
    delete mat;

    return 0;
}
