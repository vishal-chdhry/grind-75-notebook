class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    long long int y = 0, x_cpy = x;
    while (x_cpy) {
      y *= 10;
      y += x_cpy % 10;
      x_cpy /= 10;
    }
    return y == x;
  }
};