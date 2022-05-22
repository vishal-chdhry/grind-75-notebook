class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int index = 0;
    for (int i = nums.size() / 2; i >= 1; i /= 2) {
      while (index + i < nums.size() && nums[index + i] <= target) {
        cout << i << endl;
        index += i;
      }
    }
    if (nums[index] == target)
      return index;
    else
      return -1;
  }
};