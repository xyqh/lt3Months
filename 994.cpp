#include "LeetCodeBase.h"

int m = 0, n = 0, ans = 0;
pair<int, int> rounds[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void changeRound(vector<vector<int>>& grid, int i, int j){
    for(int k = 0; k < 4; ++k){
        int newI = i + rounds[k].first;
        int newJ = j + rounds[k].second;
        if(newI < 0 || newI >= m || newJ < 0 || newJ >= n || grid[newI][newJ] != 1){
            continue;
        }
        grid[newI][newJ] = 2 + ans + 1;
    }
}

int orangesRotting(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    bool check = true;
    while(check){
        check = false;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2 + ans){
                    check = true;
                    changeRound(grid, i, j);
                }
            }
        }
        ++ans;
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return ans - 2;
}

int main(){
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1},
    };
    int n = orangesRotting(grid);
    cout << n << endl;
    return 0;
}