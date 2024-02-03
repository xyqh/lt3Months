#include "LeetCodeBase.h"

int majorityElement(vector<int>& nums){
    int cnt = 1, cur = nums[0], n = nums.size();
    for(int i = 1; i < n; ++i){
        if(cur == nums[i]){
            ++cnt;
        }else{
            if(--cnt == 0){
                cur = nums[i];
                cnt = 1;
            }
        }
    }
    return cur;
}