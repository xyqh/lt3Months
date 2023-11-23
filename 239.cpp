#include "LeetCodeBase.h"

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> ans;
    priority_queue<pair<int, int>> que;
    for(int i = 0; i < k; ++i){
        que.emplace(nums[i], i);
    }
    ans.push_back(que.top().first);
    for(int i = k; i < n; ++i){
        que.emplace(nums[i], i);
        while(que.top().second <= i - k){
            que.pop();
        }
        ans.push_back(que.top().first);
    }

    return ans;
}