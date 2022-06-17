class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> degrees(numCourses, 0);
    vector<vector<int>> children(numCourses);

    for (auto v : prerequisites) {
      degrees[v[0]]++;
      children[v[1]].push_back(v[0]);
    }

    vector<int> ans;
    for (int i = 0; i < degrees.size(); i++)
      if (degrees[i] == 0) ans.push_back(i);

    for (int i = 0; i < ans.size(); i++) {
      vector<int> child = children[ans[i]];
      for (int d : child) {
        if (--degrees[d] == 0) ans.push_back(d);
      }
    }
    if (ans.size() == numCourses) return ans;
    return {};
  }
};