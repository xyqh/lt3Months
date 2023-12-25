    #include "LeetCodeBase.h"
    
    // {2,3,1,1,4}
    int jump(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int curIdx = 0, endIdx = nums[curIdx];
        while(endIdx < n - 1){
            ++ans;
            int newEndIdx = 0;
            for(int i = curIdx; i <= endIdx; ++i){
                newEndIdx = max(newEndIdx, curIdx + nums[curIdx]);
            }
            endIdx = newEndIdx;
        }

        return ans;
    }