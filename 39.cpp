#include "LeetCodeBase.h"

void backtrace(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& candidates, int idx, int target){
    if(target == 0){
        ans.push_back(tmp);
        return;
    }

    for(int i = idx; i < candidates.size(); ++i){
        if(candidates[i] <= target){
            tmp.push_back(candidates[i]);
            backtrace(ans, tmp, candidates, i, target - candidates[i]);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    backtrace(ans, tmp, candidates, 0, target);
    return ans;
}