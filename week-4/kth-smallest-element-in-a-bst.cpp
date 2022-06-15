class Solution {
 public:
  int ans = 0, t = 0;
  void inorder(TreeNode* root) {
    if (root == NULL || t < 0) return;
    inorder(root->left);
    if (t-- > 0) ans = root->val;
    inorder(root->right);
  }
  int kthSmallest(TreeNode* root, int k) {
    t = k;
    inorder(root);
    return ans;
  }
};