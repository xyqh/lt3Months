#include "LeetCodeBase.h"

int numSquares(int n){
    /**
     * 需要计算k个完全平方数之后正好等于n，其中k的最小值
     * 思路：动态规划，可以从1开始计算对应k的最小值，再由这些值推导出后面的值
     * 状态转移方程应该如何建立？
     * 一个最简单粗暴的思路是：
     * dp[i] = min((dp[1] + dp[i - 1]), (dp[2] + dp[i - 2]), ... , (dp[i / 2] + dp[i - i / 2]))
     * 需要思考是否有简化/优化空间
     * 对于任意的i = x1 + x2 + ... + xn，有当且仅当x为完全平方数时，i最小，即n
     * 对于x1~xn-1，应尽量为完全平方数，因此状态转移方程可列为：
     * dp[i] = min((dp[1] + dp[i - 1]), (dp[4] + dp[i - 4]), ... )
     * 解释：对于数值较小时而言，可拆分为1个完全平方数+1个非完全平方数，此时符合要求
     * 而对于完全平方数a+(i-a)的组合而言，当i-a不是完全平方数时，已经在dp的前段计算过最小和的数量了
    */
    int dp[n + 1];
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i < n + 1; ++i){
        int _sqrt = floor(sqrt(i));
        bool isSqrt = _sqrt * _sqrt == i;
        if(isSqrt){
            dp[i] = 1;
        }else{
            dp[i] = i;
            for(int k = 1; k * k <= i / 2; ++k){
                dp[i] = min(dp[i], 1 + dp[i - k * k]);
            }
        }
    }
    return dp[n];
}

int main(){
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}