class Solution {
 public:
  int binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int index = 0;
    for (int i = n / 2; i >= 1; i /= 2) {
      while (i + index < n && nums[index + i] <= target) {
        index += i;
      }
    }
    return index;
  }
  vector<int> sortedSquares(vector<int>& nums) {
    int zero = binarySearch(nums, 0);
    if (nums[zero] < 0) zero++;
    int ptr1 = zero - 1, ptr2 = zero;
    vector<int> ans;
    while (ptr1 > -1 && ptr2 < nums.size()) {
      int a = pow(nums[ptr1], 2), b = pow(nums[ptr2], 2);
      if (a < b) {
        ans.push_back(a);
        ptr1--;
      } else {
        ans.push_back(b);
        ptr2++;
      }
    }
    while (ptr1 > -1) {
      int a = pow(nums[ptr1], 2);
      ans.push_back(a);
      ptr1--;
    }
    while (ptr2 < nums.size()) {
      int b = pow(nums[ptr2], 2);
      ans.push_back(b);
      ptr2++;
    }
    return ans;
  }
};