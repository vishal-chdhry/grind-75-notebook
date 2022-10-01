class Solution {
 public:
  int findMin(vector<int>& nums) {
    int el = nums[0], index = 0, sz = nums.size();
    if (sz == 0) return 0;
    for (int i = sz / 2; i > 0; i /= 2)
      while (index + i < sz && nums[index + i] >= el) index += i;
    if (index == sz - 1)
      return el;
    else
      return nums[index + 1];
  }
};