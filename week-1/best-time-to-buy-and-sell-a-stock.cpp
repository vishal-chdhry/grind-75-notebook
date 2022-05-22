class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int curr_min = prices[0], max_diff = 0;
    for (int i : prices) {
      if (i < curr_min) curr_min = i;
      max_diff = max(max_diff, i - curr_min);
    }
    return max_diff;
  }
};