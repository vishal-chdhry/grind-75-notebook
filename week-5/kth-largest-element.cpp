class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> freq(20001, 0);
    for (int i : nums) freq[10000 + i]++;
    int ans, n = 20000;
    while (k > 0) {
      k -= freq[n];
      ans = n - 10000;
      n--;
    }
    return ans;
  }
};