#include "LeetCodeBase.h"

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool hasFirstColZero = false, hasFirstRowZero = false;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
                if(i == 0){
                    hasFirstColZero = true;
                }
                if(j == 0){
                    hasFirstRowZero = true;
                }
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(hasFirstColZero){
        for(int i = 0; i < m; ++i){
            matrix[i][0] = 0;
        }
    }
    if(hasFirstRowZero){
        for(int j = 0; j < n; ++j){
            matrix[0][j] = 0;
        }
    }
}