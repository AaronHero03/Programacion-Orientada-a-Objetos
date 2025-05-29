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
    
    MatrixOp a(2, 2), b(2, 2), c(2, 2), d(2,2);

    a.set(0, 0, 1.0); b.set(0, 0, 2.0);
    a.set(1, 1, 3.0); b.set(1, 1, 5.0);

    a.apply(&a, &b, &c, sub);
    a.apply(&a, &b, &d, mul);

    
    cout << "Matriz C - Resta" << endl;
    c.printAt(0, 0); c.printAt(0,1);
    c.printAt(1, 0); c.printAt(1,1);

    cout << endl << "Matriz D - Multiplicacion" << endl;
    d.printAt(0, 0); d.printAt(0,1);
    d.printAt(1, 0); d.printAt(1,1);

    MatrixOp M(2, 2);
    M.set(0, 0, 2); M.set(0, 1, 4);
    M.set(1, 0, 6); M.set(1, 1, 8);

    cout << endl << "Diagonal" << endl;
    M.forEachDiagonal(&MatrixOp::printAt);

    MatrixOp A(2,2), B(2,2);
    A.set(0, 0, 1.0); A.set(0, 1, 2.0);
    A.set(1, 0, 3.0); A.set(1, 1, 5.0);
    B.set(0, 0, 2.0); B.set(0, 1, 9.0);
    B.set(1, 0, 7.0); B.set(1, 1, 7.0);

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    cout << endl << "Sobrecarga de operadores" << endl;
    cout << "C[0, 0] = " << C.get(0,0) << endl;
    cout << "C[0, 1] = " << C.get(0,1) << endl;
    cout << "D[1, 1] = " << D.get(1,1) << endl;
    cout << "D[1, 0] = " << D.get(1,0) << endl;

    MatrixOp M2(3,3);
    M2.set(0, 0, 6.0); M2.set(0, 1, 23.0); M2.set(0, 2, 5.0); 
    M2.set(1, 0, 14.0); M2.set(1, 1, 3.0); M2.set(1, 2, 6.0); 
    M2.set(2, 0, 2.0); M2.set(2, 1, 67.0); M2.set(2, 2, 12.0); 

    double maxElem = maxValue<double>(M.getData(), M.getRows() * M.getCols());
    cout << endl << "Máximo elemento de M: " << maxElem << endl;

    IMatrix *mat = new MatrixOp(2,2);

    dynamic_cast<MatrixOp*>(mat)->set(0, 0, 1.0); // Elemento [0][0]
    dynamic_cast<MatrixOp*>(mat)->set(0, 1, 2.0); // Elemento [0][1]
    dynamic_cast<MatrixOp*>(mat)->set(1, 0, 3.0); // Elemento [1][0]
    dynamic_cast<MatrixOp*>(mat)->set(1, 1, 4.0); // Elemento [1][1]

    cout << endl << "Determinante: " << mat->determinant() << endl;

    return 0;
}
