class Solution {
 public:
  vector<vector<int>> dp;

  int dpf(vector<vector<int>>& matrix, int i, int j) {
    if (i < 0 || i >= dp.size()) return 0;
    if (j < 0 || j >= dp[0].size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int offset[5] = {1, 0, -1, 0, 1};
    int val = 0;
    for (int o = 1; o < 5; o++) {
      int curr = (i + offset[o - 1] < 0 || i + offset[o - 1] >= dp.size())
                     ? INT_MIN
                 : (j + offset[o] < 0 || j + offset[o] >= dp[0].size())
                     ? INT_MIN
                     : matrix[i + offset[o - 1]][j + offset[o]];
      if (matrix[i][j] < curr) {
        val = max(val, dpf(matrix, i + offset[o - 1], j + offset[o]) + 1);
      }
    }
    dp[i][j] = val;

    return dp[i][j];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    for (auto v : matrix) {
      vector<int> vi;
      for (auto i : v) vi.push_back(-1);
      dp.push_back(vi);
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        dpf(matrix, i, j);
      }
    }
    int ans = 0;
    for (auto v : dp) {
      for (auto i : v) ans = max(ans, i);
    }
    return ans + 1;
  }
};