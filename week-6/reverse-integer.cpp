class Solution {
 public:
  int reverse(int x) {
    int old = abs(x), ans = 0;
    while (old > 0) {
      if (ans && INT_MAX / ans < 10) return 0;
      ans = ans * 10 + old % 10;
      old /= 10;
    }
    if (x < 0) ans *= -1;
    return ans;
  }
};