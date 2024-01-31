    #include "LeetCodeBase.h"

    void sortColors(vector<int>& nums){
        int n = nums.size(), l = 0, r = n - 1;
        // 0在最前，2在最后
        while(l < r && nums[l] == 0){
            ++l;
        }
        while(l < r && nums[r] == 2){
            --r;
        }
        // 0放最前，2放最后
        for(int i = l; i <= r; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[l]);
                ++l;
            }else if(nums[i] == 2){
                swap(nums[i], nums[r]);
                --r;
            }
        }
    }