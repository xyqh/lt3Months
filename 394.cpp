#include "LeetCodeBase.h"

string decodeString(string s) {
    string ans = "", repeat = "";
    vector<string> stk;
    int i = 0, n = s.length();
    while(i < n){
        if(isdigit(s[i])){
            string num = "";
            while(isdigit(s[i])){
                num.push_back(s[i++]);
            }
            stk.push_back(num);
        }else if(isalpha(s[i]) || s[i] == '['){
            stk.push_back(string(1, s[i++]));
        }else{
            // 右括号
            string sub = "";
            while(stk.back() != "["){
                // 翻转是因为前面已经翻转过的要翻转回去，待会还会翻转一次才恢复正常
                string str = stk.back();
                reverse(str.begin(), str.end());
                sub += str;
                stk.pop_back();
            }
            // pop掉[
            stk.pop_back();
            reverse(sub.begin(), sub.end());
            int loopTime = stoi(stk.back());
            stk.pop_back();
            string _sub = "";
            while(loopTime-- > 0) _sub += sub;
            stk.push_back(_sub);
            ++i;
        }
    }

    while(!stk.empty()){
        string str = stk.back();
        reverse(str.begin(), str.end());
        ans += str;
        stk.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    auto ans = decodeString(s);
    cout << ans << endl;
    return 0;
}