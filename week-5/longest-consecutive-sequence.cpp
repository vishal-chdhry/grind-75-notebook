class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    set<int> hash;
    for (int i : nums) hash.insert(i);
    int ans = 1, curr = 0, prev = 0;
    for (auto i : hash) {
      if (i - prev == 1) {
        curr++;
        ans = max(ans, curr);
      } else {
        curr = 1;
      }
      prev = i;
    }
    return ans;
  }
};