class Solution {
 public:
  void sortColors(vector<int>& nums) {
    vector<int> hash(3, 0);
    for (int i : nums) hash[i]++;
    int curr_ptr = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < hash[i]; j++) {
        nums[curr_ptr] = i;
        curr_ptr++;
      };
    }
  }
};