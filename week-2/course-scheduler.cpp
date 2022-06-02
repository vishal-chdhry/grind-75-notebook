class Solution {
 public:
  bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(n, vector<int>());
    vector<int> degree(n, 0), bfs;
    for (auto p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      degree[p[0]]++;
    }
    for (int i = 0; i < n; i++)
      if (!degree[i]) bfs.push_back(i);
    for (int i = 0; i < bfs.size(); i++) {
      for (int a : graph[bfs[i]]) {
        if (--degree[a] == 0) bfs.push_back(a);
      }
    }
    return bfs.size() == n;
  }
};