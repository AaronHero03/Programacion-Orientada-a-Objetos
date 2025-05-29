#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdexcept>

/**
 * @brief Interfaz abstracta para operaciones avanzadas de matriz.
 */
class IMatrix {
public:
    virtual ~IMatrix() = default;
    virtual double determinant() const = 0;
};

class MatrixOp: public IMatrix{
public:
    
    int rows, cols;
    double *data_;

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

    //Polimorfismo

    // Suma elemento a elemento: devuelve una nueva matriz
    MatrixOp operator+(const MatrixOp &other) const;

    // Resta elemento a elemento: devuelve una nueva matriz
    MatrixOp operator-(const MatrixOp &other) const;

    double determinant() const override;
};

/**
 * @brief Devuelve el valor máximo en un arreglo contiguo de longitud n.
 * @tparam T Tipo de dato (double, int, etc.)
 * @param arr Puntero al primer elemento del arreglo
 * @param n   Número de elementos
 * @return    El máximo entre arr[0] … arr[n-1]
 */
template<typename T>
T maxValue(const T*arr, int n){
    if(n <= 0) throw std::invalid_argument("El arrego debe tener al menos dos elementos");
    T max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

#endif // MATRIXOP_H

