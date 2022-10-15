/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  int ans = INT_MIN;

  int dp(TreeNode* root) {
    if (root == NULL) return 0;
    int lt = max(dp(root->left), 0);
    int rt = max(dp(root->right), 0);
    ans = max(ans, root->val + rt + lt);
    return root->val + max(lt, rt);
  }

 public:
  int maxPathSum(TreeNode* root) {
    dp(root);
    return ans;
  }
};