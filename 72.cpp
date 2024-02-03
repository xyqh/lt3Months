#include "LeetCodeBase.h"

int minDistance(string word1, string word2){
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m + 1; ++i){
        dp[i][0] = i;
    }
    for(int i = 0; i < n + 1; ++i){
        dp[0][i] = i;
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            // 需要分析三个项的含义。分别是word1新增一个，word2新增一个，以及替换
            if(word1[i - 1] == word2[j - 1]){
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] - 1) + 1;
            }else{
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[m][n];
}