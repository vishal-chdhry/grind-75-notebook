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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    int n = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> vi;
      int sz = q.size();
      while (sz--) {
        auto a = q.front();
        q.pop();
        if (a == NULL) continue;
        q.push(a->left);
        q.push(a->right);
        vi.push_back(a->val);
      }
      if (vi.size() == 0) break;
      if (n & 1) reverse(vi.begin(), vi.end());
      ans.push_back(vi);
      n++;
    }
    return ans;
  }
};