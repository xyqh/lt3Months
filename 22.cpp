#include "LeetCodeBase.h"

void backtrace(vector<string>& ans, string& tmp, int left, int right){
    if(left == 0 && right == 0){
        ans.push_back(tmp);
        return;
    }

    if(left == right){
        tmp.push_back('(');
        backtrace(ans, tmp, left - 1, right);
        tmp.pop_back();
    }else{
        if(left > 0){
            tmp.push_back('(');
            backtrace(ans, tmp, left - 1, right);
            tmp.pop_back();
        }
        tmp.push_back(')');
        backtrace(ans, tmp, left, right - 1);
        tmp.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    if(n == 0) return {};
    vector<string> ans;
    string tmp;
    backtrace(ans, tmp, n, n);
    return ans;
}

int main(){
    int n = 3;
    auto ans = generateParenthesis(n);
    return 0;
}