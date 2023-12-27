#include "LeetCodeBase.h"

vector<vector<int>> generate(int numRows){
    /**
     * 杨辉三角
    */
    vector<vector<int>> ans(numRows);
    int curNum = 0;
    vector<int> pre;
    while(numRows-- > 0){
        ++curNum;
        vector<int> cur(curNum, 1);
        for(int i = 1; i < curNum - 1; ++i){
            cur[i] = pre[i] + pre[i - 1];
        }
        ans[curNum - 1] = cur;
        pre = cur;
    }

    return ans;
}