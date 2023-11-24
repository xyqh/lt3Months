#include "LeetCodeBase.h"

// // 想不出来，就o(n)空间吧
// int firstMissingPositive(vector<int>& nums) {
//     int n = nums.size();
//     priority_queue<int, vector<int>, greater<int>> que;
//     for(int i = 0; i < n; ++i){
//         que.push(nums[i]);
//     }
//     int ans = 1;
//     while(!que.empty() && que.top() <= ans){
//         ans = max(ans, que.top() + 1);
//         que.pop();

//     }
//     return ans;
// }

// // 官方题解1
// int firstMissingPositive(vector<int>& nums) {
//     int n = nums.size();
//     for(int i = 0; i < n; ++i){
//         if(nums[i] <= 0){
//             nums[i] = n + 1;
//         }
//     }
//     for(int i = 0; i < n; ++i){
//         if(abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0){
//             nums[abs(nums[i]) - 1] *= -1;
//         }
//     }
//     for(int i = 0; i < n; ++i){
//         if(nums[i] > 0){
//             return i + 1;
//         }
//     }
//     return n + 1;
// }

// 官方题解2，相关还原正确位置，但是想到有重复数字觉得太复杂就没有继续想了
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for(int i = 0; i < n; ++i){
        if(nums[i] != i + 1){
            return i + 1;
        }
    }
    return n + 1;
}

int main(){
    // vector<int> nums = {7,8,9,11,12};
    // vector<int> nums = {1,2,0};
    vector<int> nums = {3,4,-1,1,1};
    int n = firstMissingPositive(nums);
    cout << n << endl;
    return 0;
}