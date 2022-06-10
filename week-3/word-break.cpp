class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> mp;
    for (string a : wordDict) mp.insert(a);
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i <= s.size(); i++)
      for (int j = i; j >= 0; j--)
        if (dp[j] && mp.find(s.substr(j, i - j)) != mp.end()) dp[i] = true;
    return dp[s.size()];
  }
};