#include "LeetCodeBase.h"

int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> stk;
    for(int i = 0; i < n; ++i){
        while(!stk.empty() && heights[i] < heights[stk.top()]){
            right[stk.top()] = i;
            stk.pop();
        }
        if(!stk.empty()){
            left[i] = stk.top();
        }
        stk.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }

    return ans;
}

int main(){
    vector<int> nums = {6,7,5,2,4,5,9,3};
    int ans =largestRectangleArea(nums);
    return 0;
}