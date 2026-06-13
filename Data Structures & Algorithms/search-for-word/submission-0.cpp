class Solution {
    static constexpr int DIRS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (dfs(board, word, r, c, 0)) return true;

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int idx) {
        if (idx == (int)word.size()) return true;

        if (r < 0 || r >= (int)board.size()
         || c < 0 || c >= (int)board[0].size()
         || board[r][c] != word[idx]
         || board[r][c] == '#') return false;

        char temp = board[r][c];
        board[r][c] = '#';

        for (auto& d : DIRS)
            if (dfs(board, word, r + d[0], c + d[1], idx + 1)) {
                board[r][c] = temp;
                return true;
            }

        board[r][c] = temp;
        return false;
    }
};
