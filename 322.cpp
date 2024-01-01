    #include "LeetCodeBase.h"

    int findIndex(vector<int>& coins, int coin){
        int n = coins.size(), l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l >> 1);
            if(coins[m] == coin){
                return m;
            }else if(coins[m] < coin){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return -1;
    }

    int coinChange(vector<int>& coins, int amount){
        sort(coins.begin(), coins.end());

    }