#include "LeetCodeBase.h"

unordered_map<char, int> ori, cnt;

bool check(){
    for(const auto &p:ori){
        if(cnt[p.first] < p.second){
            return false;
        }
    }

    return true;
}

string minWindow(string s, string t) {
    for(char& c:t){
        ++ori[c];
    }

    int l = 0, r = l, n = s.size();
    int beginIdx = -1, len = INT_MAX;
    while(r < n){
        if(ori.count(s[r])){
            ++cnt[s[r]];
        }

        while(check() && l <= r){
            if(r - l + 1 < len){
                beginIdx = l;
                len = r - l + 1;
            }

            if(ori.count(s[l])){
                --cnt[s[l]];
            }
            ++l;
        }
        ++r;
    }

    return beginIdx == -1 ? "" : s.substr(beginIdx, len);
}