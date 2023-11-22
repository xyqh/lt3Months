#include "LeetCodeBase.h"

vector<int> findAnagrams(string s, string p){
    int len = p.length(), n = s.length();
    int l = 0, r = 0;
    unordered_map<char, int> cnt;
    for(int i = 0; i < len; ++i, ++r){
        if(--cnt[p[i]] == 0){
            cnt.erase(p[i]);
        }
        if(++cnt[s[r]] == 0){
            cnt.erase(s[r]);
        }
    }

    --l;
    --r;
    vector<int> ans;
    while(r < n){
        if(cnt.empty()){
            ans.push_back(l + 1);
        }
        if(r == n - 1) break;
        if(++cnt[s[++r]] == 0){
            cnt.erase(s[r]);
        }
        if(--cnt[s[++l]] == 0){
            cnt.erase(s[l]);
        }
    }

    return ans;
}