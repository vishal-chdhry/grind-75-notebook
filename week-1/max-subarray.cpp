class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max_value = INT_MIN, local_max = 0;
    for (int i : nums) {
      local_max += i;
      max_value = max(max_value, local_max);
      local_max = max(0, local_max);
    }
    return max_value;
  }
};