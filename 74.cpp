#include "LeetCodeBase.h"

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = matrix.size(), j = matrix[0].size();
    int total = i * j, l = 0, r = total - 1;
    while(l <= r){
        int m = l + (r - l >> 1);
        int x = m / j, y = m % j;
        if(target == matrix[x][y]){
            return true;
        }else if(target < matrix[x][y]){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 13;
    bool find = searchMatrix(matrix, target);
    return 0;
}