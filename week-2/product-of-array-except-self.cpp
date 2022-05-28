class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    for (int i = nums.size() - 2; i >= 0; i--) {
      ans[i] = ans[i + 1] * nums[i + 1];
    }
    int prefix = 1;
    for (int& i : nums) {
      int temp = prefix * i;
      i = prefix;
      prefix = temp;
    }
    for (int i = 0; i < nums.size(); i++) {
      ans[i] = ans[i] * nums[i];
    }
    return ans;
  }
};