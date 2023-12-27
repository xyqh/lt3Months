#include "LeetCodeBase.h"

// {2,3,1,1,4}
int jump(vector<int>& nums) {
    int ans = 0, n = nums.size();
    int curIdx = 0, endIdx = 0;
    while(endIdx < n - 1){
        ++ans;
        int newEndIdx = 0;
        for(int i = curIdx; i <= endIdx; ++i){
            newEndIdx = max(newEndIdx, i + nums[i]);
        }
        curIdx = endIdx + 1;
        endIdx = newEndIdx;
    }

    return ans;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    jump(nums);
    return 0;
}