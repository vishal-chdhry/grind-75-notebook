/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  stack<TreeNode*> lst;
  TreeNode* prev = NULL;
  vector<int> ans;
  void find(TreeNode* root, TreeNode* target) {
    if (root == NULL || (!lst.empty() && lst.top() == target)) return;
    lst.push(root);
    if (root == target) return;
    find(root->left, target);
    find(root->right, target);
    if (!lst.empty() && lst.top() == target) return;
    lst.pop();
  }

  void get(TreeNode* root, int k, TreeNode* avoid) {
    if (root == NULL || k < 0 || root == prev) return;
    if (k == 0 && root != avoid) ans.push_back(root->val);
    get(root->left, k - 1, avoid);
    get(root->right, k - 1, avoid);
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    find(root, target);
    while (!lst.empty()) {
      auto a = lst.top();
      lst.pop();
      get(a, k--, prev);
      prev = a;
    }
    return ans;
  }
};