#include "LeetCodeBase.h"

int countPairs(vector<int>& nums, int target) {
    int ans = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 1; ++i){
        int a = nums[i];
        int l = i + 1, r = n - 1, idx = l;
        while(l <= r){
            int m = l + (r - l >> 1);
            if(nums[m] >= target - a){
                r = m - 1;
            }else{
                idx = m;
                l = m + 1;
            }
        }
        if(nums[idx] < target - a){
            ans += idx - i;
        }
    }

    return ans;
}