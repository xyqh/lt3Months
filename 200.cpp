#include "LeetCodeBase.h"

int m = 0, n = 0, ans = 0;
vector<vector<int>> visited;
pair<int, int> rounds[4] = {
    {0,1}, {0,-1}, {1,0}, {-1,0}
};

void dfs(vector<vector<char>>& grid, int i, int j){
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 || grid[i][j] == '0') return;
    visited[i][j] = 1;
    for(int k = 0; k < 4; ++k){
        int newI = i + rounds[k].first;
        int newJ = j + rounds[k].second;
        dfs(grid, newI, newJ);
    }
}

int numIslands(vector<vector<char>>& grid) {
    m = grid.size(), n = grid[0].size(), ans = 0;
    visited = vector<vector<int>>(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(visited[i][j] == 1) continue;
            if(grid[i][j] == '1'){
                dfs(grid, i, j);
                ++ans;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    int n = numIslands(grid);
    return 0;
}