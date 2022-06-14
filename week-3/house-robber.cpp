class Solution {
 public:
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      int j = i - 2;
      dp[i] = nums[i];
      while (j >= 0) {
        dp[i] = max(dp[j] + nums[i], dp[i]);
        j--;
      }
    }
    int ans = 0;
    for (int i : dp) ans = max(ans, i);
    return ans;
  }
};