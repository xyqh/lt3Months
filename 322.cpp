#include "LeetCodeBase.h"

int coinChange(vector<int>& coins, int amount){
    sort(coins.begin(), coins.end());
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for(int i = 1; i < amount + 1; ++i){
        for(int k = 0; k < coins.size(); ++k){
            if(coins[k] > i){
                break;
            }
            if(dp[i - coins[k]] == -1){
                continue;
            }
            if(dp[i] == -1){
                dp[i] = dp[i - coins[k]] + 1;
            }else{
                dp[i] = min(dp[i], dp[i - coins[k]] + 1);
            }
            cout << i << " " << dp[i] << endl;
        }
    }
    return dp[amount];
}

int main(){
    vector<int> coins = {186,419,83,408};
    int n = 6249;
    cout << coinChange(coins, n) << endl;
    return 0;
}