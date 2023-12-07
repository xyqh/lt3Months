    #include "LeetCodeBase.h"
    
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = n, l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l >> 1);
            if(target <= nums[m]){
                idx = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return idx;
    }