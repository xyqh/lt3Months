#include "LeetCodeBase.h"

void moveZeroes(vector<int>& nums) {
    int curIdx = 0, replaceIdx = 0;
    int n = nums.size();
    while(curIdx < n){
        while(curIdx < n && nums[curIdx] == 0){
            ++curIdx;
        }
        if(curIdx >= 0){
            break;
        }
        nums[replaceIdx++] = nums[curIdx++];
    }
    while(replaceIdx < n){
        nums[replaceIdx++] = 0;
    }
}