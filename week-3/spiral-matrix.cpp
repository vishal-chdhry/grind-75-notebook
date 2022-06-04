class Solution {
 public:
  vector<int> ans;
  void printBorder(vector<vector<int>>& matrix, int offset) {
    // top row
    for (int i = offset; i < matrix[0].size() - offset; i++) {
      if (matrix[offset][i] != INT_MAX) ans.push_back(matrix[offset][i]);
      matrix[offset][i] = INT_MAX;
    }
    // right column
    for (int i = offset + 1; i < matrix.size() - offset; i++) {
      if (matrix[i][matrix[0].size() - offset - 1] != INT_MAX)
        ans.push_back(matrix[i][matrix[0].size() - offset - 1]);
      matrix[i][matrix[0].size() - offset - 1] = INT_MAX;
    }
    // bottom row
    for (int i = matrix[0].size() - offset - 1 - 1; i >= offset; i--) {
      if (matrix[matrix.size() - offset - 1][i] != INT_MAX)
        ans.push_back(matrix[matrix.size() - offset - 1][i]);
      matrix[matrix.size() - offset - 1][i] = INT_MAX;
    }
    // left col
    for (int i = matrix.size() - offset - 1 - 1; i > offset; i--) {
      if (matrix[i][offset] != INT_MAX) ans.push_back(matrix[i][offset]);
      matrix[i][offset] = INT_MAX;
    }
  }
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int no = min(matrix.size(), matrix[0].size()) / 2;
    for (int i = 0; i <= no; i++) {
      printBorder(matrix, i);
    }
    return ans;
  }
};