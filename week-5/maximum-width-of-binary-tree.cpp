class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    queue<pair<TreeNode*, long long int>> q;
    q.push({root, 1});
    int ans = 0;
    while (!q.empty()) {
      int s = q.size();
      int start = INT_MIN, end = INT_MIN;
      while (s--) {
        auto curr = q.front();
        if (start == INT_MIN) start = curr.second;
        q.pop();
        if (curr.first->left != NULL)
          q.push({curr.first->left, (curr.second - start + 1) * 2});
        if (curr.first->right != NULL)
          q.push({curr.first->right, (curr.second - start + 1) * 2 + 1});
        end = curr.second - start + 1;
      }
      ans = max(ans, end);
    }
    return ans;
  }
};