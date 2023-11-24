#include "LeetCodeBase.h"

// /**
//  * 动态规划
// */
// int maxSubArray(vector<int>& nums) {
//     int n = nums.size();
//     int cur = 0, pre = 0, ans = INT_MIN;
//     for(int i = 0; i < n; ++i){
//         cur = max(pre + nums[i], nums[i]);
//         ans = max(ans, cur);
//         pre = cur;
//     }
//     return ans;
// }

/**
 * 线段树
 * 对于一个区间 [l,r]，我们可以维护四个量：
 * lSum 表示 [l,r] 内以 l 为左端点的最大子段和
 * rSum 表示 [l,r] 内以 r 为右端点的最大子段和
 * mSum 表示 [l,r] 内的最大子段和
 * iSum 表示 [l,r] 的区间和
*/
struct Status{
    int lSum, rSum, mSum, iSum;
};

Status pushUp(Status l, Status r){
    int iSum = l.iSum + r.iSum;
    int lSum = max(l.lSum, l.iSum + r.lSum);
    int rSum = max(r.rSum, r.iSum + l.rSum);
    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
    return (Status){lSum, rSum, mSum, iSum};
}

Status Get(vector<int>& nums, int l, int r){
    if(l == r){
        return (Status){nums[l], nums[l], nums[l], nums[l]};
    }

    int m = (l + r) >> 1;
    Status lSub = Get(nums, l, m);
    Status rSub = Get(nums, m + 1, r);
    return pushUp(lSub, rSub);
}

int maxSubArray(vector<int>& nums){
    return Get(nums, 0, nums.size() - 1).mSum;
}