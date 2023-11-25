#include "LeetCodeBase.h"

void swap(int &x, int &y){
    x -= y;
    y += x;
    x = -x + y;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < (n + 1) / 2; ++i){
        for(int j = i; j < n - 1 - i; ++j){
            int pixel = matrix[i][j], temp = 0, x = i, y = j;
            for(int k = 0; k < 4; ++k){
                // (x, y): (0, 0)->(0, n - 1)->(n - 1, n - 1)->(n - 1, 0)
                swap(x, y);
                y = -y + n - 1;
                temp = matrix[x][y];
                matrix[x][y] = pixel;
                pixel = temp;
            }
        }
    }
}

int main(){
    // vector<vector<int>> nums = {
    //     {5,1,9,11},
    //     {2,4,8,10},
    //     {13,3,6,7},
    //     {15,14,12,16},
    // };
    vector<vector<int>> nums = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    rotate(nums);
    return 0;
}