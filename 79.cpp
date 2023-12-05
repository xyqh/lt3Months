    #include "LeetCodeBase.h"

    bool isExist = false;
    int m = 0, n = 0, len = 0;
    vector<vector<int>> visited;
    void backtrace(vector<vector<char>>& board, string word, int idx, int i, int j){
        if(isExist || idx == len || i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 || board[i][j] != word[idx]) return;
        if(idx == len - 1){
            isExist = true;
            return;
        }
        visited[i][j] = 1;
        backtrace(board, word, idx + 1, i, j + 1);
        backtrace(board, word, idx + 1, i, j - 1);
        backtrace(board, word, idx + 1, i + 1, j);
        backtrace(board, word, idx + 1, i - 1, j);
        visited[i][j] = 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), len = word.size();
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                visited = vector<vector<int>>(m, vector<int>(n, 0));
                backtrace(board, word, 0, i, j);
            }
        }

        return isExist;
    }

    int main(){
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
        };
        string word = "ABCCED";
        bool ans = exist(board, word);
        return 0;
    }