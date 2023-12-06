    #include "LeetCodeBase.h"

    bool check(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

    void backtrace(vector<vector<string>>& ans, vector<string>& tmp, string& s, int idx, int len){
        if(idx == len){
            ans.push_back(tmp);
            return;
        }

        int l = idx;
        for(int i = idx; i < len; ++i){
            if(check(s, l, i)){
                string subS = s.substr(l, i - l + 1);
                tmp.push_back(subS);
                backtrace(ans, tmp, s, i + 1, len);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> tmp;
        backtrace(ans, tmp, s, 0, n);
        return ans;
    }