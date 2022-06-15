class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp;
    int count = 0;
    for (char c : tasks) {
      mp[c]++;
      count = max(count, mp[c]);
    }
    int ans = (n + 1) * (count - 1);
    for (auto p : mp)
      if (p.second == count) ans++;
    return max((int)tasks.size(), ans);
  }
};