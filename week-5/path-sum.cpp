class Solution {
 public:
  int sum = 0;
  vector<int> path;
  vector<vector<int>> ans;
  void dfs(TreeNode* root, int target) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
      path.push_back(root->val);
      sum += root->val;
      if (sum == target) ans.push_back(path);
      sum -= root->val;
      path.pop_back();
      return;
    }
    path.push_back(root->val);
    sum += root->val;
    dfs(root->left, target);
    dfs(root->right, target);
    sum -= root->val;
    path.pop_back();
    return;
  }
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == NULL) return {};
    dfs(root, targetSum);
    return ans;
  }
};