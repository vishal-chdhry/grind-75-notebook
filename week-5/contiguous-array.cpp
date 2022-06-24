class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    int ans = 0, sum = 0, idx = 0;
    for (int i : nums) {
      idx++;
      i ? sum++ : sum--;
      if (sum == 0) ans = max(ans, idx);
      if (mp.find(sum) == mp.end())
        mp[sum] = idx;
      else
        ans = max(ans, idx - mp[sum]);
    }
    return ans;
  }
};