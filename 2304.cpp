#include "LeetCodeBase.h"

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost){
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
    for(int j = 0; j < n; ++j){
        costs[0][j] = grid[0][j];
    }
    int ans = INT_MAX;
    for(int i = 0; i < m - 1; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                // 路径消耗+目标节点消耗+到达上一个节点的消耗
                int cost = moveCost[grid[i][j]][k] + grid[i + 1][k] + costs[i][j];
                costs[i + 1][k] = min(costs[i + 1][k], cost);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        ans = min(ans, costs[m - 1][i]);
    }

    return ans;
}