class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    vector<int> hash(nums.size() + 1, 0);
    for (int i : nums) {
      if (hash[i] != 0) return i;
      hash[i]++;
    }
    return -1;
  }
};