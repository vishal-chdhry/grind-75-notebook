class Solution {
 public:
  int myAtoi(string s) {
    int i = 0, mul = 1;
    long long int ans = 0;
    for (; i < s.size(); i++) {
      if (s[i] != 32) break;
    }
    if (s[i] == '-') {
      mul = -1;
      i++;
    } else if (s[i] == '+') {
      mul = 1;
      i++;
    }
    for (; i < s.size(); i++) {
      if (!(s[i] >= '0' && s[i] <= '9'))
        break;
      else {
        ans *= 10;
        ans += s[i] - '0';
        if (ans * mul >= INT_MAX)
          return INT_MAX;
        else if (ans * mul <= INT_MIN)
          return INT_MIN;
      }
    }
    return ans * mul;
  }
};