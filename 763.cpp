#include "LeetCodeBase.h"

vector<int> partitionLabels(string s){
    vector<int> indexs(26, 0);
    vector<int> ans;
    int n = s.size(), l = 0;
    for(int i = 0; i < n; ++i){
        indexs[s[i] - 'a'] = i;
    }
    while(l < n){
        int idx = l;
        char c = s[idx];
        int furthest = indexs[c - 'a'];
        while(idx < furthest){
            c = s[++idx];
            furthest = max(furthest, indexs[c - 'a']);
        }
        ans.push_back(idx - l + 1);
        l = idx + 1;
    }

    return ans;
}

int main(){
    string s = "ababcbacadefegdehijhklij";
    auto ans = partitionLabels(s);
    return 0;
}