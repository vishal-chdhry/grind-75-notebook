class Solution {
 public:
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    if (rows == 0) return mat;
    int cols = mat[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (mat[i][j] == 0) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int new_i = curr.first + dir[i][0], new_j = curr.second + dir[i][1];
        if (new_i >= 0 && new_i < rows && new_j < cols && new_j >= 0 &&
            dist[new_i][new_j] > dist[curr.first][curr.second] + 1) {
          dist[new_i][new_j] = dist[curr.first][curr.second] + 1;
          q.push({new_i, new_j});
        }
      }
    }
    return dist;
  }
};
