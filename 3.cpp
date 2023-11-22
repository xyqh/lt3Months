#include "LeetCodeBase.h"

int lengthOfLongestSubstring(string s){
    int l = 0, r = 0, n = s.size(), ans = 0;
    unordered_map<char, int> cnt;
    while(r < n){
        if(cnt[s[r]]++ > 0){
            while(l < r && --cnt[s[l++]] != 1){
            }
        }else{
            ans = max(ans, r - l + 1);
        }
        ++r;
    }

    return ans;
}