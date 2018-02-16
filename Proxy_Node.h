//
// Created by nikita on 05.02.18.
//

#ifndef MATRIX_PROXY_NODE_H
#define MATRIX_PROXY_NODE_H
#include <stdexcept>


template <class T>
class Proxy_Node {
public:
    Proxy_Node()  = delete;

    explicit Proxy_Node(T& target, int i ):target(target), i(i){

    }

    Proxy_Node<T> operator[](int j){
        if(j > target.get_cols() || j < 0 ) throw std::runtime_error("j is out of bounds");
        id_from_m = i * target.get_rows() + j;
        return *this;
    }

    Proxy_Node<T>& operator=(const int& right) {
        if(right == target.default_value()){
            target.free(id_from_m);
            return *this;
        }
        target.assign(id_from_m, right);
        return *this;
    }

    int get_value() const {
        return target.get_value(id_from_m);
    }

    friend bool operator ==(const Proxy_Node<T> &a, int b)
    {
        return (a.get_value() == b);
    }

private:
    T& target;
    int i;
    int id_from_m;
};



#endif //MATRIX_PROXY_NODE_H
