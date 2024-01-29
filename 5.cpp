    #include "LeetCodeBase.h"

    pair<int, int> expandFromCenter(const string& s, int left, int right){
        int n = s.length();
        if(left > 0 && right < n && s[left] == s[right]){
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s){
        int n = s.length(), start = 0, end = 0;
        string ans = s.substr(0, 1);
        for(int i = 0; i < n; ++i){
            auto[left1, right1] = expandFromCenter(s, i, i);
            auto[left2, right2] = expandFromCenter(s, i, i + 1);
            if(right1 - left1 > end - start){
                start = left1;
                end = right1;
            }
            if(right2 - left2 > end - start){
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }