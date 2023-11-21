#include "LeetCodeBase.h"

int minDeletion(vector<int>& nums){
    /**
     * 模拟，依次遍历，对于任意的i%2==0，有nums[i]==nums[i+1]，则需要进行删除，知道新的nums[i+1]!=nums[i]
    */
    int n = nums.size();
    int virtualIdx = 0, actualIdx = 0, ans = 0;
    while(actualIdx < n){
        if(virtualIdx % 2 == 0){
            while(actualIdx < n - 1 && nums[actualIdx] == nums[actualIdx + 1]){
                ++actualIdx;
                ++ans;
            }
        }
        ++actualIdx;
        ++virtualIdx;
    }
    return ans + virtualIdx % 2;
}

int main(){
    vector<int> nums = {1,1,2,2,3,3};
    int del = minDeletion(nums);
    cout << del << endl;
    return 0;
}