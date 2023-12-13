#include "LeetCodeBase.h"

bool isValid(string s) {
    stack<char> stk;
    for(char c:s){
        if(stk.empty()){
            stk.push(c);
        }else{
            char _c = stk.top();
            if((c == ')' && _c == '(') || (c == ']' && _c == '[') || (c == '}' && _c == '{')){
                stk.pop();
            }else{
                stk.push(c);
            }
        }
    }

    return stk.empty();
}