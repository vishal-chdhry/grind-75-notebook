class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    vector<int> freq(2 * 1e4 + 1, 0);
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
      pq.push(nums[i]);
      freq[1e4 + nums[i]]++;
    }
    ans.push_back(pq.top());
    for (int i = k; i < nums.size(); i++) {
      freq[1e4 + nums[i - k]]--;
      freq[1e4 + nums[i]]++;
      while (!pq.empty() && !freq[1e4 + pq.top()]) {
        pq.pop();
      }
      pq.push(nums[i]);
      ans.push_back(pq.top());
    }
    return ans;
  }
};