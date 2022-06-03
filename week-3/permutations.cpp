class Solution {
 public:
  vector<vector<int>> ans;
  bool taken[21] = {0};
  vector<int> perm;
  void generate(vector<int>& nums) {
    if (perm.size() == nums.size()) {
      ans.push_back(perm);
    } else {
      for (int i : nums) {
        if (taken[i + 10]) continue;
        taken[i + 10] = true;
        perm.push_back(i);
        generate(nums);
        perm.pop_back();
        taken[i + 10] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    generate(nums);
    return ans;
  }
};