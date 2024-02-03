#include "LeetCodeBase.h"

int maxProduct(vector<int>& nums){
    int minProduct = 1, maxProduct = 1;
    int ans = INT_MIN;
    for(int num:nums){
        int mx = maxProduct, mn = minProduct;
        minProduct = min(mn * num, min(num, mx * num));
        maxProduct = max(mx * num, max(num, mn * num));
        ans = max(ans, maxProduct);
    }
    
    return ans;
}