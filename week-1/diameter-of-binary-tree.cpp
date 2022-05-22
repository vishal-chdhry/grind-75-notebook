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
 public:
  int depth(TreeNode* root, int& d) {
    if (root == NULL) return 0;
    int left_d = depth(root->left, d);
    int right_d = depth(root->right, d);
    d = max(d, left_d + right_d);
    return max(left_d, right_d) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    int d = 0;
    depth(root, d);
    return d;
  }
};