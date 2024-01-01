    #include "LeetCodeBase.h"

    int rob(vector<int>& nums){
        /**
         * 思路：需要隔户，所以对任意i而言，要抢当前户的话能抢到的最多的数值有可能是：max(dp[i-3], dp[i-2]) + dp[i]
        */
        int n = nums.size(), ans = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; ++i){
            if(i < 2){
                dp[i] = nums[i];
            }else{
                if(i > 2){
                    dp[i] = nums[i] + max(dp[i - 3], dp[i - 2]);
                }else{
                    dp[i] = nums[i] + dp[i - 2];
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }