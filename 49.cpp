#include "LeetCodeBase.h"

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> ans_map;
    int n = strs.size();
    for(int i = 0; i < n; ++i){
        string str = "";
        // 这里用char进行计数，且push到string里时又是一个单独的字符，处理得很巧妙
        vector<char> cnt(26, '0');
        for(int j = 0; j < strs[i].length(); ++j){
            ++cnt[strs[i][j] - 'a'];
        }
        for(int j = 0; j < 26; ++j){
            str.push_back(cnt[j]);
        }

        ans_map[str].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for(auto it = ans_map.begin(); it != ans_map.end(); ++it){
        ans.push_back(it->second);
    }

    return ans;
}