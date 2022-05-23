class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> counter(n + 1);
    counter[0] = 0;
    if (n == 0) return counter;
    counter[1] = 1;
    if (n == 1) return counter;
    for (int i = 2; i <= n; i++) {
      int lastPowOfTwo = pow(2, (int)log2(i));
      counter[i] = counter[i - lastPowOfTwo] + 1;
    }
    return counter;
  }
};