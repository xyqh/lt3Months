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
            // 当把当前的2放到最后时，无法确定换过来的数位置是否正确，所以需要继续检测当前索引。上面的情况不需要处理，因为换过来的数一定>0
            --i;
            --r;
        }
    }
}