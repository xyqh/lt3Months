#include "LeetCodeBase.h"

int maxProfit(vector<int>& prices) {
    int ans = 0, idx = 0, n = prices.size();
    int in = prices[idx++];
    while(idx < n){
        if(prices[idx] < in){
            in = prices[idx];
        }else{
            ans = max(ans, prices[idx] - in);
        }
        ++idx;
    }
    return ans;
}