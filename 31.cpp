#include "LeetCodeBase.h"

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    if(n <= 1) return;

    int i = n - 1;
    while(i > 0 && nums[i] <= nums[--i]){

    }
    int idx = i + 1;
    for(int k = idx; k < n; ++k){
        if(nums[k] > nums[i] && nums[k] < nums[idx]){
            idx = k;
        }
    }
    if(nums[idx] <= nums[i]){
        sort(nums.begin(), nums.end());
    }else{
        swap(nums[i], nums[idx]);
        sort(nums.begin() + i + 1, nums.end());
    }
}