#include "LeetCodeBase.h"

void backtrace(vector<vector<int>>& res, vector<int>& output, int first, int len){
if(first == len){
    res.push_back(output);
    return;
}

for(int i = first; i < len; ++i){
    swap(output[i], output[first]);
    backtrace(res, output, first + 1, len);
    swap(output[i], output[first]);
}
}

vector<vector<int>> permute(vector<int>& nums) {
vector<vector<int>> ans;
int n = nums.size();
backtrace(ans, nums, 0, n - 1);
return ans;
}