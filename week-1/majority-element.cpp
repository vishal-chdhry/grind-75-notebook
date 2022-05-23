class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int major = 0, count = 0;
    for (int i : nums) {
      if (count == 0) {
        major = i;
        count++;
      } else if (major == i) {
        count++;
      } else {
        count--;
      }
    }
    return major;
  }
};