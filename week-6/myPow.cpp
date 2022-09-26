class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n & 1) {
      return n > 0 ? x * pow(x, n - 1) : (1 / x) * pow(x, n + 1);
    } else {
      return myPow(x * x, n / 2);
    }
  }
};