class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> nums2 = nums;
    sort(nums.begin(), nums.end());
    auto ptr1 = nums.begin(), ptr2 = nums.end() - 1;
    while (*ptr1 + *ptr2 != target) {
      if (*ptr1 + *ptr2 > target)
        ptr2--;
      else if (*ptr1 + *ptr2 < target)
        ptr1++;
    }

    vector<int> ans;
    int first = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums2[i] == *ptr1) {
        ans.push_back(i);
        first = i;
        break;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums2[i] == *ptr2 && i != first) {
        ans.push_back(i);
        break;
      }
    }

    return ans;
  }
};