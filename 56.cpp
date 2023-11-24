#include "LeetCodeBase.h"

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)->bool{
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });

    vector<vector<int>> ans;
    int n = intervals.size(), l = 0, r = 0;
    for(int i = 0; i < n; ++i){
        if(i == 0){
            l = intervals[i][0], r = intervals[i][1];
        }else{
            if(intervals[i][0] <= r){
                r = max(r, intervals[i][1]);
            }else{
                ans.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
        }
        if(i == n - 1){
            ans.push_back({l, r});
        }
    }

    return ans;
}