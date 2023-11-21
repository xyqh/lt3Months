#include "LeetCodeBase.h"

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n - 2; ++i){
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }

        int r = n - 1, target = -nums[i];
        for(int l = i + 1; l < r; ++l){
            if(l > i + 1 && nums[l] == nums[l - 1]){
                continue;
            }
            while(l < r && nums[r] + nums[l] > target){
                --r;
            }
            if(l == r){
                break;
            }
            if(nums[l] + nums[r] == target){
                ans.push_back({nums[i], nums[l], nums[r]});
            }
        }
    }

    return ans;
}