#ifndef MATRIXOP_H
#define MATRIXOP_H

class MatrixOp{
public:

    // Ejercicio 1
    MatrixOp(int rows, int cols);
    ~MatrixOp();

    void set(int i, int j, double v);
    void check();
    double get(int i, int j) const;

    // Ejercicio 2
    void add(const MatrixOp *other, MatrixOp *result)const;

    // Ejercicio 3
    using OpFunc = double(*)(double, double);
    void apply(const MatrixOp *A, const MatrixOp *B, MatrixOp *out, OpFunc op) const;
    
    // Ejercicio 4
    void forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const;
    void printAt(int i, int j) const;

    private: 
        int rows, cols;
        double *data_;

};

#endif // MATRIXOP_H