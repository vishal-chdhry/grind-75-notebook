class Solution {
 public:
  vector<vector<bool>> visited;
  bool dfs(vector<vector<char>>& board, string word, int m, int n, int index) {
    if (index == word.size())
      return true;
    else if (m < 0 || n < 0 || n >= board[0].size() || m >= board.size())
      return false;
    else if (visited[m][n]) {
      return false;
    } else if (board[m][n] == word[index]) {
      visited[m][n] = true;
      bool top = dfs(board, word, m - 1, n, index + 1);
      bool left = dfs(board, word, m, n - 1, index + 1);
      bool right = dfs(board, word, m, n + 1, index + 1);
      bool bottom = dfs(board, word, m + 1, n, index + 1);
      visited[m][n] = false;
      return top || left || right || bottom;
    } else {
      return false;
    }
  }
  bool exist(vector<vector<char>>& board, string word) {
    bool ans = false;
    for (auto vc : board) {
      vector<bool> row;
      for (char c : vc) row.push_back(false);
      visited.push_back(row);
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++)
        if (board[i][j] == word[0]) {
          ans = ans || dfs(board, word, i, j, 0);
        }
    }
    cout << endl;
    return ans;
  }
};