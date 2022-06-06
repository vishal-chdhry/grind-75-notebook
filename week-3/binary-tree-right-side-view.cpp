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
  vector<int> ans;
  queue<TreeNode*> nodes;
  void right() {
    while (!nodes.empty() && nodes.front() != NULL) {
      TreeNode* curr = nodes.front();
      nodes.pop();
      if (curr->left != NULL) {
        nodes.push(curr->left);
      }
      if (curr->right != NULL) {
        nodes.push(curr->right);
      }
      if (nodes.front() == NULL) {
        ans.push_back(curr->val);
        nodes.pop();
        nodes.push(NULL);
      }
    }
  }
  vector<int> rightSideView(TreeNode* root) {
    nodes.push(root);
    nodes.push(NULL);
    right();
    return ans;
  }
};