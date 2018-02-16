//
// Created by nikita on 02.02.18.
//

#ifndef HW6_MATRIX_H
#define HW6_MATRIX_H

#include "Proxy_Node.h"
#include <unordered_map>
#include <iostream>
class Matrix {
public:
    friend class Proxy_Node<Matrix>;

    explicit Matrix(int def_value, int rows, int cols);

    int get_rows() const{
        return rows;
    }

    int get_cols() const{
        return cols;
    }

    Proxy_Node<Matrix> operator[](int i){
        if(i > rows || i < 0) throw std::runtime_error("i is out of bounds");
        return Proxy_Node<Matrix>(*this, i);
    }

    unsigned long elements(){
        return one_dim_mat.size();
    }

    void show(){
        for(auto& ref: one_dim_mat){
            int i = ref.first/rows;
            int j = ref.first % rows;
            std::cout<<"I="<<i<<" J="<<j<<" V="<<ref.second<<std::endl;
        }
    }
private:

    void free(int id){
        one_dim_mat.erase(id);
    }

    int default_value(){
        return def_value;
    }

    void assign(int pos, int value){
        auto res = one_dim_mat.find(pos);
        if (res != one_dim_mat.end()){
            one_dim_mat.erase(pos);
        }
        one_dim_mat.insert({pos,value});
    }

    int get_value(int pos){
        auto res = one_dim_mat.find(pos);
        if (res == one_dim_mat.end()){
            return def_value;
        }
        return res->second;
    }

    std::unordered_map<int,int> one_dim_mat;
    int rows, cols;
    int max_one_dim;
    int def_value;

};


#endif //HW6_MATRIX_H
