class Solution {
 public:
  static bool comparator(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
  }
  int interval_index = 0;
  vector<int> mergeInter(vector<vector<int>>& intervals) {
    vector<int> new_interval = intervals[interval_index++];
    while (interval_index < intervals.size() &&
           new_interval[1] >= intervals[interval_index][0]) {
      new_interval[0] = min(new_interval[0], intervals[interval_index][0]);
      new_interval[1] = max(new_interval[1], intervals[interval_index++][1]);
    }
    return new_interval;
  }
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comparator);
    vector<vector<int>> ans;
    int n = intervals.size();
    while (interval_index < n - 1) {
      cout << intervals[interval_index][0] << ' '
           << intervals[interval_index][1] << endl;
      if (intervals[interval_index][1] >= intervals[interval_index + 1][0]) {
        ans.push_back(mergeInter(intervals));
      } else
        ans.push_back(intervals[interval_index++]);
    }
    while (interval_index < n) {
      ans.push_back(intervals[interval_index++]);
    }
    return ans;
  }
};