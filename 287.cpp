#include "LeetCodeBase.h"

int findDuplicate(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        while(i != nums[i] - 1){
            if(nums[i] == nums[nums[i] - 1]){
                return nums[i];
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    return -1;
}