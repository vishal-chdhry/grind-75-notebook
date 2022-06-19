class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    vector<int> ans(nums.end() - k, nums.end());
    for (int i = 0; i < nums.size() - k; i++) ans.push_back(nums[i]);
    nums = ans;
  }
};