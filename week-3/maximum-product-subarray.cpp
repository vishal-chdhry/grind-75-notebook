class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int currMax = nums[0], maxim;
    int currMin = nums[0], minim;

    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      maxim = max(max(currMax * nums[i], currMin * nums[i]), nums[i]);
      minim = min(min(currMin * nums[i], currMax * nums[i]), nums[i]);
      cout << currMax << currMin << endl;
      ans = max(ans, maxim);
      currMax = maxim;
      currMin = minim;
    }
    return ans;
  }
};