    #include "LeetCodeBase.h"

    int longestValidParentheses(string s){
        int n = s.length(), ans = 0;
        vector<int> left(n, 0), right(n, 0);
        for(int i = 0; i < n; ++i){
            if(i > 0){
                left[i] = left[i - 1];
                right[i] = right[i - 1];
            }

            if(s[i] == '('){
                right[i] = max(min(right[i], left[i] - 1), 0);
                ++left[i];
            }else{
                ++right[i];
                if(right[i] > left[i]){
                    left[i] = 0;
                }
            }
            ans = max(ans, min(left[i], right[i]) * 2);
        }

        return ans;
    }