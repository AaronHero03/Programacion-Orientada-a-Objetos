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


/**
 * @brief Clase para operaciones con matrices usando memoria dinámica
 */
class MatrixOp: public IMatrix{

private:
    int rows_, cols_;
    double *data_;

public:
    /**
     * @brief Constructor que crea una matriz de rows x cols
     * @param rows Número de filas
     * @param cols Número de columnas
    */
    MatrixOp(int rows, int cols);

    /**
     * @brief Destructor
    */
    ~MatrixOp();

    // Getters
    int getRows() const{ return rows_;}
    int getCols() const{ return cols_;}
    const double* getData() const { return data_; }
    int getSize() const { return rows_ * cols_; }

    /**
     * @brief Establece el valor en la posición (i,j)
     * @throws std::out_of_range Si los índices están fuera de rango
     */
    void set(int i, int j, double v);

    /**
     * @brief Obtiene el valor en la posición (i,j)
     * @throws std::out_of_range Si los índices están fuera de rango
     */
    double get(int i, int j) const;

    /**
     * @brief Suma esta matriz con other y almacena el resultado en result
     * @throws std::invalid_argument Si las dimensiones no coinciden
    */
    void add(const MatrixOp *other, MatrixOp *result)const;

    // Puntero a una funcion
    using OpFunc = double(*)(double, double);

    /**
     * @brief Aplica la operación op elemento a elemento entre A y B, guardando en out
     */
    void apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op) const;

    /**
     * @brief Itera sobre la diagonal principal aplicando la función fn
     */
    void forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const;

    /**
     * @brief Imprime el valor en la posicion (i, j)
    */
    void printAt(int i, int j) const;

    // Sobrecarga de operadores

    MatrixOp operator+(const MatrixOp &other) const;
    MatrixOp operator-(const MatrixOp &other) const;

    // Implementacion de determinade desde IMatrix
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

