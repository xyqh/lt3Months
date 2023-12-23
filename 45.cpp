    #include "LeetCodeBase.h"
    
    // {2,3,1,1,4}
    int jump(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int curIdx = 0, endIdx = 0, newEndIdx = nums[curIdx];
        while(newEndIdx < n - 1){
            if(curIdx > endIdx){
                ++ans;
                endIdx = newEndIdx;
            }
            newEndIdx = max(endIdx, curIdx + nums[curIdx++]);
        }

        return ans + (endIdx < n - 1);
    }