#include "LeetCodeBase.h"

bool canJump(vector<int>& nums) {
    int n = nums.size(), curIdx = 0, maxIdx = nums[curIdx];
    while(curIdx <= maxIdx && maxIdx < n){
        maxIdx = max(maxIdx, curIdx + nums[curIdx]);
        if(maxIdx >= n - 1){
            return true;
        }
        ++curIdx;
    }

    return maxIdx >= n - 1;
}