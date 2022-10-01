class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int ans = 0;
    if (intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a1, vector<int> &a2) { return a1[1] < a2[1]; });
    for (auto i = intervals.begin() + 1; i < intervals.end(); i++) {
      if ((*i)[0] < (*(i - 1))[1]) {
        ans++;
        (*i)[1] = (*(i - 1))[1];
      }
    }
    return ans;
  }
};