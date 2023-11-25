#include "LeetCodeBase.h"

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int idx = 0, n = matrix.size(), m = matrix[0].size();
    vector<int> ans(m * n);
    int l = 0, r = m - 1, t = 0, b = n - 1;
    while(idx < m * n){
        for(int i = l; i <= r; ++i){
            ans[idx++] = matrix[t][i];
        }
        if(idx >= m * n) break;
        ++t;
        for(int i = t; i <= b; ++i){
            ans[idx++] = matrix[i][r];
        }
        if(idx >= m * n) break;
        --r;
        for(int i = r; i >= l; --i){
            ans[idx++] = matrix[b][i];
        }
        if(idx >= m * n) break;
        --b;
        for(int i = b; i >= t; --i){
            ans[idx++] = matrix[i][l];
        }
        ++l;
    }

    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> ans = spiralOrder(matrix);
    return 0;
}