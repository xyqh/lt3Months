#include "LeetCodeBase.h"

bool canPartition(vector<int>& nums){
    int n = nums.size(), sum = 0, maxNum = INT_MIN;
    for(int i = 0; i < n; ++i){
        sum += nums[i];
        maxNum = max(maxNum, nums[i]);
    }

    if((sum & 1) || maxNum > (sum >> 1)){
        return false;
    }
    int target = sum >> 1;
    // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // dp[0][nums[0]] = 1;
    // for(int i = 1; i < n; ++i){
    //     int num = nums[i];
    //     for(int j = 1; j < n; ++j){
    //         if(j >= num){
    //             dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
    //         }else{
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }

    // return dp[n - 1][target];
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        int num = nums[i];
        for(int j = target; j >= num; --j){
            dp[j] |= dp[j - num];
        }
    }
    return dp[target];
}