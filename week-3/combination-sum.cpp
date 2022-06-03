class Solution {
 public:
  vector<vector<int>> ans;
  vector<int> perm;
  void generate(vector<int>& candidates, vector<int> perm, int target, int curr,
                int index) {
    if (target == curr) {
      ans.push_back(perm);
      perm.clear();
    } else if (curr < target) {
      for (int i = index; i < candidates.size(); i++) {
        perm.push_back(candidates[i]);
        generate(candidates, perm, target, curr + candidates[i], i);
        perm.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    generate(candidates, perm, target, 0, 0);
    return ans;
  }
};