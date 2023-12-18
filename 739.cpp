    #include "LeetCodeBase.h"
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++i){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                int j = stk.top();
                ans[j] = i - j;
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }