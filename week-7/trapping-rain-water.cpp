class Solution {
 public:
  int trap(vector<int>& height) {
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);
    int _max = 0, ans = 0;
    for (int i = 0; i < height.size(); i++) {
      left[i] = _max;
      _max = max(_max, height[i]);
    }
    _max = 0;
    for (int i = height.size() - 1; i > -1; i--) {
      right[i] = _max;
      _max = max(_max, height[i]);
    }

    for (int i = 0; i < height.size(); i++)
      ans += max(min(left[i], right[i]) - height[i], 0);
    return ans;
  }
};