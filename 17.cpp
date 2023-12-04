#include "LeetCodeBase.h"

unordered_map<char, vector<char>> mp = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},
};

void backtrace(vector<string>& ans, string tmp, string digits, int idx, int n){
    if(idx == n){
        ans.push_back(tmp);
        return;
    }
    auto chars = mp[digits[idx]];
    for(int i = 0; i < chars.size(); ++i){
        tmp.push_back(chars[i]);
        backtrace(ans, tmp, digits, idx + 1, n);
        tmp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    int n = digits.size();
    if(n < 1) return {};
    vector<string> ans;
    string tmp;
    backtrace(ans, tmp, digits, 0, n);
    return ans;
}