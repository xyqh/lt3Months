    #include "LeetCodeBase.h"

    vector<int> partitionLabels(string s){
        /**
         * 划分字符串，使每个字符最多只出现在一个子串里，且要求子串尽量多
         * 思路：
         * 记录所有字符的索引
         * 从第一个字符开始，找到最远的索引，并且更新当前位置到最远位置直接其他字符的最远位置
         * 不断更新直至没有最远位置不再变化，进行一次划分
        */
        vector<vector<int>> indexs(26);
        int n = s.size();
        for(int i = 0; i < n; ++i){
            indexs[s[i] - '0'].push_back(i);
        }
        int l = 0;
        vector<int> ans;
        while(l < n){
            int idx = l;
            char c = s[idx];
            int furthest = indexs[c - '0'].back();
            while(idx < furthest){
                c = s[++idx];
                furthest = max(furthest, indexs[c - '0'].back());
            }
            ans.push_back(furthest - l + 1);
            l = furthest + 1;
        }
        return ans;
    }