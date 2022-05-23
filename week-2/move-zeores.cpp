class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() == 1)
      return;
    else {
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
          int k = i;
          while (k > 0 && nums[k - 1] == 0) {
            swap(nums[k], nums[k - 1]);
            k--;
          }
        }
      }
    }
  }
};