class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size(), columns = rows > 0 ? matrix[0].size() : 0,
        maxlen = 0, upperL = 0;
    vector<int> dp(columns + 1, 0);
    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= columns; j++) {
        int temp = dp[j];
        if (matrix[i - 1][j - 1] == '1') {
          dp[j] = min(dp[j], min(dp[j - 1], upperL)) + 1;
          maxlen = max(maxlen, dp[j]);
        } else {
          dp[j] = 0;
        }
        upperL = temp;
      }
    }
    return maxlen * maxlen;
  }
};