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
                /**
                 * (x, y): (0, 0)->(0, n - 1)->(n - 1, n - 1)->(n - 1, 0)
                 * 旋转公式：x' = xcosθ + ysinθ, y' = -xsinθ + ycosθ; 其中θ为逆时针旋转角度
                 * 由于题目要求顺时针旋转90°，可得sinθ=-1, cosθ=0;
                 * 即x' = -y, y' = x
                 * 注意：坐标原点0，0在左上角，旋转后需要向x轴正方向平移n-1个单位长度，即
                 * x' = -y + n - 1
                 * 得到新坐标(-y + n - 1, x)
                 * 需要映射到二维数组的下标可得下标为：[x, -y + n - 1]
                */
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