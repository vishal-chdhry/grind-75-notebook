class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for (int i : nums) sum += i;

    if (sum & 1) return false;
    sum /= 2;

    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < sum + 1; j++) dp[i][j] = false;

    for (int i = 1; i < n + 1; i++) {
      dp[i][0] = true;
    }
    for (int j = 1; j < sum + 1; j++) {
      dp[0][j] = false;
    }

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < sum + 1; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= nums[i - 1]) {
          dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i - 1]]);
        }
      }
    }
    return dp[n][sum];
  }
};