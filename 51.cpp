    #include "LeetCodeBase.h"

    string getLine(int n, int idx){
        string s('.', n);
        s[idx] = 'Q';
        return s;
    }

    void backtrace(vector<vector<string>>& ans, vector<string>& tmp, int n, int col, int row, int ldiag, int rdiag){
        if(n == 0){
            ans.push_back(tmp);
            return;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        int col = 0, row = 0, ldiag = 0, rdiag = 0;
        vector<vector<string>> ans;
        vector<string> tmp;
        backtrace(ans, tmp, n, col, row, ldiag, rdiag);
        return ans;
    }