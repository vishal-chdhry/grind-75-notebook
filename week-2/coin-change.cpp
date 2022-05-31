class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> res(amount + 1, INT_MAX);
    res[0] = 0;
    for (int i = 1; i < amount + 1; i++)
      for (int c : coins)
        if (i - c >= 0 && res[i - c] != INT_MAX)
          res[i] = min(res[i], res[i - c] + 1);
    if (res[amount] == INT_MAX)
      return -1;
    else
      return res[amount];
  }
};