#include "LeetCodeBase.h"

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> hash;
    for(int num:nums){
        hash[num] = 1;
    }

    int ans = 0, n = nums.size();
    for(int i = 0; i < n; ++i){
        // 向下找，找到最小的再开始向上算长度
        if(!hash.count(nums[i] - 1)){
            int len = 1;
            int cur = nums[i] + 1;
            while(hash.count(cur)){
                ++len;
                ++cur;
            }
            ans = max(ans, len);
        }
    }

    return ans;
}