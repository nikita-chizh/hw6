#include "Matrix.h"

int main() {
    Matrix mat(5,5,5);
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(i%2 ==0 && j%2 == 0){
                mat[i][j] = i * j;
            }
        }
    }
    mat.show();
    return 0;
}