class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>> hts;
    hts.push(make_pair(0, -1));  // to avoid edge cases
    int n = heights.size();
    int maxarea = 0;
    for (int i = 0; i < n; i++) {
      auto t = hts.top();
      int x = -1;
      while (t.second != -1 && t.first > heights[i]) {
        int area = t.first * (i - t.second);
        maxarea = (maxarea > area) ? maxarea : area;
        hts.pop();
        x = t.second;
        t = hts.top();
      }
      if (x == -1)
        hts.push(make_pair(heights[i], i));
      else
        hts.push(make_pair(heights[i], x));
    }

    auto t = hts.top();
    while (t.second != -1) {
      int area = t.first * (n - t.second);
      maxarea = (maxarea > area) ? maxarea : area;
      hts.pop();
      t = hts.top();
    }
    return maxarea;
  }
};