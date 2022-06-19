class Solution {
 public:
  void rotate(vector& nums, int k) {
    int n = nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k % n);
    reverse(nums.begin() + k % n, nums.end());
  }
};