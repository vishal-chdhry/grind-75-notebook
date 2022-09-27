class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0, index = -1;
    for (int i = (m * n); i >= 1; i /= 2)
      while (i + index < (m * n) &&
             matrix[(index + i) / n][(index + i) % n] <= target)
        index += i;
    return index != -1 && matrix[(index) / n][index % n] == target;
  }
};