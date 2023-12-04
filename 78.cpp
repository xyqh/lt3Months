    #include "LeetCodeBase.h"

    void backtrace(vector<vector<int>>& ans, vector<int>& sub, vector<int>& nums, int idx, int n){
        ans.push_back(sub);
        for(int i = idx; i < n; ++i){
            sub.push_back(nums[i]);
            backtrace(ans, sub, nums, i + 1, n);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n = nums.size();
        backtrace(ans, sub, nums, 0, n);
        return ans;
    }