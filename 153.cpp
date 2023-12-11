    #include "LeetCodeBase.h"

    int findMin(vector<int>& nums){
        int n = nums.size(), l = 0, r = n - 1, m = 0, ans = INT_MAX;
        while(l <= r){
            m = l + (r - l >> 1);
            if(nums[0] <= nums[m]){
                ans = min(ans, nums[0]);
                l = m + 1;
            }else{
                ans = min(ans, nums[m]);
                r = m - 1;
            }
        }

        return ans;
    }

    int main(){
        vector<int> nums = {4,5,6,7,-1,0,1,2};
        int ans = findMin(nums);
        cout << ans << endl;
        return 0;
    }