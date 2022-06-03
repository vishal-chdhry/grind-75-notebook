class Solution {
 public:
  int binarySearch(vector<int>& nums, int target) {
    int index = 0, n = nums.size();
    for (int i = n / 2; i >= 1; i /= 2) {
      while (index + i < n && nums[index + i] <= target) {
        index += i;
      }
    }
    if (nums[index] == target)
      return index;
    else
      return -1;
  }
  int search(vector<int>& nums, int target) {
    int first = nums[0], index = 0, n = nums.size();
    for (int i = n / 2; i >= 1; i /= 2) {
      while (index + i < n && nums[index + i] >= first) {
        index += i;
      }
    }
    if (index == n - 1) return binarySearch(nums, target);
    vector<int> one(nums.begin() + index + 1, nums.end());
    cout << one.back() << ' ' << one.front() << endl;
    vector<int> two(nums.begin(), nums.begin() + index + 1);
    cout << two.back() << ' ' << two.front() << endl;
    if (two.size() && target >= two[0]) {
      return binarySearch(two, target);
    } else {
      int idx = binarySearch(one, target);
      if (idx == -1) return -1;
      return idx + index + 1;
    }
  }
};