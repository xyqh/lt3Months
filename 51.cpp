#include "LeetCodeBase.h"

vector<string> generateLine(vector<int>& tmp, int n){
    vector<string> lines;
    string str;
    for(auto pos : tmp){
        for(int i = 0; i < n; ++i){
            if((pos >> i) & 1){
                str.push_back('Q');
            }else{
                str.push_back('.');
            }
        }
        lines.push_back(str);
        str = "";
    }
    return lines;
}

void backtrace(vector<vector<string>>& ans, vector<int>& tmp, int n, int idx, int col, int ldiag, int rdiag){
    if(idx == 0){
        ans.push_back(generateLine(tmp, n));
        return;
    }

    int valid = ((1 << n) - 1) & ~(col | ldiag | rdiag);
    while(valid){
        int pos = valid & -valid;
        valid &= valid - 1;
        col |= pos;
        ldiag |= pos;
        rdiag |= pos;
        tmp.push_back(pos);
        backtrace(ans, tmp, n, idx - 1, col, ldiag << 1, rdiag >> 1);
        tmp.pop_back();
        col ^= pos;
        ldiag ^= pos;
        rdiag ^= pos;
    }
}

vector<vector<string>> solveNQueens(int n) {
    int col = 0, row = 0, ldiag = 0, rdiag = 0;
    vector<vector<string>> ans;
    vector<int> tmp;
    backtrace(ans, tmp, n, n, col, ldiag, rdiag);
    return ans;
}

int main(){
    int n = 4;
    auto ans = solveNQueens(n);
    for(auto sol : ans){
        for(auto str : sol){
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}