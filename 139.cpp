#include "LeetCodeBase.h"

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> mp;
    for(string word : wordDict){
        mp[word] = true;
    }

    int n = s.size();
    vector<bool> dp(n + 1);
    dp[0] = true;
    for(int i = 1; i < s.size() + 1; ++i){
        for(int j = 0; j < i; ++j){
            if(dp[j] && mp.find(s.substr(j, i - j)) != mp.end()){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}