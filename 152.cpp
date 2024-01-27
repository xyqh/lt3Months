    #include "LeetCodeBase.h"

    int maxProduct(vector<int>& nums){
        int minProduct = 1, maxProduct = 1;
        int ans = INT_MIN;
        for(int num:nums){
            minProduct = min(minProduct * num, num);
            maxProduct = max(maxProduct * num, num);
            ans = max(minProduct, maxProduct);
        }
        
        return ans;
    }