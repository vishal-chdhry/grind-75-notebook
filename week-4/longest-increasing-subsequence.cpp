class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < dp.size(); i++) {
      int j = i - 1;
      while (j >= 0) {
        if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        j--;
      }
    }
    int ans = 0;
    for (int i : dp) ans = max(ans, i);
    return ans;
  }
};