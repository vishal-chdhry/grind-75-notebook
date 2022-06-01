class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0, rows = grid.size();
    if (rows == 0) return ans;
    int cols = grid[0].size();
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          ans++;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int k = p.first, l = p.second;
            cout << k << ' ' << l << endl;
            if (k + 1 < rows && grid[k + 1][l] == '1') {
              q.push({k + 1, l});
              grid[k + 1][l] = '0';
            }
            if (l + 1 < cols && grid[k][l + 1] == '1') {
              q.push({k, l + 1});
              grid[k][l + 1] = '0';
            }
            if (l - 1 >= 0 && grid[k][l - 1] == '1') {
              q.push({k, l - 1});
              grid[k][l - 1] = '0';
            }
            if (k - 1 >= 0 && grid[k - 1][l] == '1') {
              q.push({k - 1, l});
              grid[k - 1][l] = '0';
            }
          }
          cout << "EOQ" << endl;
        }
      }
    }
    return ans;
  }
};