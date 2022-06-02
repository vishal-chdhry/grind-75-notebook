class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int offsets[] = {0, 1, 0, -1, 0}, rows = grid.size(), cols = grid[0].size(),
        ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    q.push({-1, -1});
    pair<int, int> nill = {-1, -1};
    while (!q.empty() && q.front() != nill) {
      while (q.front() != nill) {
        pair<int, int> fr = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
          int new_r = fr.first + offsets[k], new_c = fr.second + offsets[k + 1];
          if (new_r < rows && new_r >= 0 && new_c < cols && new_c >= 0 &&
              grid[new_r][new_c] == 1) {
            grid[new_r][new_c] = 0;
            q.push({new_r, new_c});
          }
        }
      }
      q.pop();
      q.push({-1, -1});
      if (!q.empty() && q.front() != nill) ans++;
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << grid[i][j] << ' ';
        if (grid[i][j] == 1) return -1;
      }
      cout << endl;
    }
    return ans;
  }
};