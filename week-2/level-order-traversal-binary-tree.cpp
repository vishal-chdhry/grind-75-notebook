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
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> st;
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    st.push(root);
    while (!st.empty()) {
      st.push(NULL);
      vector<int> values;
      while (st.front() != NULL) {
        TreeNode* curr = st.front();
        values.push_back(curr->val);
        if (curr->left != NULL) st.push(curr->left);
        if (curr->right != NULL) st.push(curr->right);
        st.pop();
      }
      st.pop();
      ans.push_back(values);
    }
    return ans;
  }
};