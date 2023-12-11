#include "LeetCodeBase.h"

int search(vector<int>& nums, int target) {
    int n = nums.size(), l = 0, r = n - 1, m = 0;
    while(l <= r){
        m = l + (r - l >> 1);
        if(nums[m] == target){
            return m;
        }
        if(nums[0] <= nums[m]){
            if(nums[0] <= target && target < nums[m]){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }else{
            if(nums[m] < target && target <= nums[n - 1]){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int idx = search(nums, target);
    return 0;
}