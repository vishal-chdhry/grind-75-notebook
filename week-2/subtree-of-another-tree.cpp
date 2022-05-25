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
  vector<TreeNode*> nodes;
  int findSubtrees(TreeNode* node, int d) {
    if (node == NULL)
      return 0;
    else {
      if (d == node->val) nodes.push_back(node);
      return max(findSubtrees(node->left, d), findSubtrees(node->right, d)) + 1;
    }
  }

  bool isSame(TreeNode* node1, TreeNode* node2) {
    if (node1 == NULL && node2 == NULL)
      return true;
    else if (node1 == NULL && node2 != NULL)
      return false;
    else if (node1 != NULL && node2 == NULL)
      return false;
    else if (node1->val != node2->val)
      return false;
    else {
      bool isRight = isSame(node1->right, node2->right);
      if (!isRight) return false;
      bool isLeft = isSame(node1->left, node2->left);
      if (!isLeft) return false;
    }
    return true;
  }
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL || subRoot == NULL) return false;
    findSubtrees(root, subRoot->val);
    for (TreeNode* n : nodes) {
      if (isSame(n, subRoot)) return true;
    }
    return false;
  }
};