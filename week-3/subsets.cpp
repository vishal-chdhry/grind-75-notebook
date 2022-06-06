class Solution {
 public:
  vector<vector<int>> sub;
  vector<int> curr;
  void gen_sub(vector<int>& nums, int k) {
    if (k == nums.size()) {
      sub.push_back(curr);
      return;
    } else {
      curr.push_back(nums[k]);
      gen_sub(nums, k + 1);
      curr.pop_back();
      gen_sub(nums, k + 1);
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    gen_sub(nums, 0);
    return sub;
  }
};