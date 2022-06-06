class Solution {
 public:
  int uniquePaths(int m, int n) {
    int grid[m][n];
    grid[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) continue;
        int top = i - 1 >= 0 ? grid[i - 1][j] : 0;
        int left = j - 1 >= 0 ? grid[i][j - 1] : 0;
        grid[i][j] = top + left;
      }
    }
    return grid[m - 1][n - 1];
  }
};