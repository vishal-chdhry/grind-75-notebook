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
  unordered_map<long long int, long long int> hash;
  long long int total = 0;

 public:
  int pathSum(TreeNode* root, int targetSum, long long int currentSum = 0) {
    if (root == NULL) return 0;
    currentSum += root->val;
    if (currentSum == targetSum) total++;
    if (hash.find(currentSum) == hash.end()) hash[currentSum] = 0;
    if (hash.find(currentSum - targetSum) != hash.end())
      total += hash[currentSum - targetSum];
    hash[currentSum]++;
    pathSum(root->left, targetSum, currentSum);
    pathSum(root->right, targetSum, currentSum);
    hash[currentSum]--;
    return total;
  }
};