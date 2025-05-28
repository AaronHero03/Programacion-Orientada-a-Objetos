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

