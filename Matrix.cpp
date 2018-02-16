//
// Created by nikita on 02.02.18.
//

#include "Matrix.h"
Matrix::Matrix(int def_value, int rows, int cols):def_value(def_value), rows(rows), cols(cols){
    max_one_dim = rows * cols;
}
