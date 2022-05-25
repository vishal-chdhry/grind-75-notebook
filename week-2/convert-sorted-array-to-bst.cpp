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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
      return NULL;
    } else if (nums.size() == 1) {
      TreeNode* head = new TreeNode(nums[0]);
      return head;
    } else {
      int middle = nums.size() / 2;
      TreeNode* head = new TreeNode(nums[middle]);
      vector<int> leftInts(nums.begin(), nums.begin() + middle);
      vector<int> rightInts(nums.begin() + middle + 1, nums.end());
      TreeNode* left = sortedArrayToBST(leftInts);
      TreeNode* right = sortedArrayToBST(rightInts);
      head->left = left;
      head->right = right;
      return head;
    }
  }
};