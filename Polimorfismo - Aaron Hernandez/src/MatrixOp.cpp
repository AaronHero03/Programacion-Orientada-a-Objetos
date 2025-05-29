#include "MatrixOp.h"
#include <iostream>

using namespace std;

// Ejercio 1

MatrixOp::MatrixOp(int rows, int cols) : rows(rows), cols(cols) {
    data_ = new double[rows * cols]{};
}
MatrixOp::~MatrixOp(){
    delete[] data_;
}

void MatrixOp::set(int i, int j, double v){
    if(i >= 0 && i < rows && j >= 0 && j < cols){
        int k = i* cols + j;
        data_[k] = v;
    } 
    else {
        throw out_of_range("Indice fuera de rango");
    }
}

double MatrixOp::get(int i, int j) const{
    if(i >= 0 && i < rows && j >= 0 && j < cols){
        int k = i*cols + j;
        return data_[k];
    } 
    else{
        throw out_of_range("Indice fuera de rango");
    }
}

// Ejercicio 2
void MatrixOp::add(const MatrixOp *other, MatrixOp *result)const{
    if(other->cols == this->cols && other->rows == this->rows){
        for(int k = 0; k < rows*cols; k++){
            result->data_[k] = this->data_[k] + other->data_[k];
        }
    }
}

void MatrixOp::apply(const MatrixOp *A, const MatrixOp *B, MatrixOp *out, OpFunc op) const{
    for(int k = 0; k < rows*cols; k++){
        out->data_[k] = op(A->data_[k], B->data_[k]);
    }
}
 
void MatrixOp::forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const ) const{
    for(int i = 0; i < min(rows, cols); i++){
        (this->*fn)(i, i);
    }
}

void MatrixOp::printAt(int i, int j) const{
    cout << get(i, j) << endl;
}

// Suma elemento a elemento: devuelve una nueva matriz
MatrixOp MatrixOp::operator+(const MatrixOp &other) const{
    if(this->cols == other.cols && this->rows == other.rows){
        MatrixOp result(this->rows, this->cols);
        for(int k = 0; k < rows*cols; k++){
            result.data_[k] = this->data_[k] + other.data_[k];
        }
        return result;   
    }
    throw std::invalid_argument("Dimensiones de matrices incompatibles para la suma");
}

// Resta elemento a elemento: devuelve una nueva matriz
MatrixOp MatrixOp::operator-(const MatrixOp &other) const{
    if(this->cols == other.cols && this->rows == other.rows){
        MatrixOp result(this->rows, this->cols);
        for(int k = 0; k < rows*cols; k++){
            result.data_[k] = this->data_[k] - other.data_[k];
        }
        return result;   
    }     
    throw std::invalid_argument("Dimensiones de matrices incompatibles para la resta");
}


double MatrixOp::determinant() const{
    if(this->rows == 2 && this->cols == 2){
        return get(0,0)*get(1,1)-get(0,1)*get(1, 0);    
    }
    else if(this->rows == 3 && this->cols == 3){
        // Regla de Sarrus para 3x3
        double a = get(0,0), b = get(0,1), c = get(0,2);
        double d = get(1,0), e = get(1,1), f = get(1,2);
        double g = get(2,0), h = get(2,1), i = get(2,2);
        return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
    }
    else{
        throw std::logic_error("Implementar para 2x2 o 3x3");

    }
}
