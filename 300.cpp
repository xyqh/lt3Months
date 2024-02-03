#include "LeetCodeBase.h"

int lengthOfLIS(vector<int>& nums){
    int n = nums.size(), ans = 0;
    vector<int> dp(n, 1);
    for(int i = 0; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}