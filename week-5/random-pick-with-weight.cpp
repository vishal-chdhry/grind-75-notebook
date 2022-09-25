class Solution {
 public:
  vector<int> sum;
  Solution(vector<int>& w) {
    sum.push_back(w[0]);
    for (int i = 1; i < w.size(); i++) {
      sum.push_back(w[i] + sum[sum.size() - 1]);
    }
  }

  int pickIndex() {
    int mx = sum[sum.size() - 1];
    int index = rand() % mx;
    auto it = upper_bound(sum.begin(), sum.end(), index);
    return it - sum.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */