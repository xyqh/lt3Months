#include "LeetCodeBase.h"

int uniqueLetterString(string s) {
    int n = s.length(), unique = 0;
    unordered_map<char, vector<int>> index;
    for(int i = 0; i < n; ++i){
        index[s[i]].emplace_back(i);
    }

    for(auto&&[_, arr]:index){
        arr.insert(arr.begin(), -1);
        arr.emplace_back(n);
        for(int i = 1; i < arr.size() - 1; ++i){
            unique += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
        }
    }

    return unique;
}