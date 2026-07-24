class Solution {
private:
    bool found = false;
    bool backtrack(vector<vector<char>>& board, int n, int m, int i, int j, string word, int k){
        if(k == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[k]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = backtrack(board, n, m, i+1, j, word, k+1) ||
        backtrack(board, n, m, i-1, j, word, k+1) ||
        backtrack(board, n, m, i, j+1, word, k+1) ||
        backtrack(board, n, m, i, j-1, word, k+1);

        board[i][j] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(), k = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[k] == board[i][j]){
                    if(backtrack(board, n, m, i, j, word, k)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};