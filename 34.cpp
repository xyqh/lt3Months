#include "LeetCodeBase.h"

vector<int> searchRange(vector<int>& nums, int target) {
    int minIdx = -1, maxIdx = -1;
    int n = nums.size(), l = 0, r = n - 1, m = 0;
    while(l <= r){
        m = l + (r - l >> 1);
        if(nums[m] == target){
            minIdx = m;
            r = m - 1;
        }else if(nums[m] < target){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }

    l = 0, r = n - 1;
    while(l <= r){
        m = l + (r - l >> 1);
        if(nums[m] == target){
            maxIdx = m;
            l = m + 1;
        }else if(nums[m] < target){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }

    return {minIdx, maxIdx};
}