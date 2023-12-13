#include "LeetCodeBase.h"

class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {
        stk = stack<int>();
        minStk = stack<int>();
    }
    
    void push(int val) {
        stk.push(val);
        if(!minStk.empty() && minStk.top() < val){
            minStk.push(minStk.top());
        }else{
            minStk.push(val);
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */