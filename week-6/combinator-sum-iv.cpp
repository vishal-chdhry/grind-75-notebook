class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++)
      for (int c : nums)
        if (i - c >= 0) dp[i] += dp[i - c];
    return dp.back();
  }
};