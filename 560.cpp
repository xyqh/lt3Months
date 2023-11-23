#include "LeetCodeBase.h"

int subarraySum(vector<int>& nums, int k) {
    int ans = 0, cur = 0, pre = 0;
    int n = nums.size();
    unordered_map<int, int> numForIndexs;
    for(int i = 0; i < n; ++i){
        cur = nums[i] + pre;
        if(cur == k){
            ++ans;
        }
        int diff = cur - k;
        if(numForIndexs.count(diff)){
            ans += numForIndexs[diff];
        }
        ++numForIndexs[cur];
        pre = cur;
    }

    return ans;
}