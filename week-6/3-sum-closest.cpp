class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans = 1e7;
    sort(nums.begin(), nums.end());
    for (auto i = nums.begin(); i < nums.end(); i++) {
      auto begin = nums.begin(), end = nums.end() - 1;
      while (begin < end) {
        if (begin == i) {
          begin++;
        } else if (end == i) {
          end--;
        } else {
          int sum = *begin + *end + *i;
          if (sum > target) {
            end--;
          } else {
            begin++;
          }
          if (abs(target - sum) < abs(target - ans)) {
            ans = sum;
          }
        }
      }
    }
    return ans;
  }
};