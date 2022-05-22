class Solution {
 public:
  int longestPalindrome(string s) {
    int freq[128] = {0};
    for (char c : s) freq[c]++;
    int odd = 0;
    for (int i : freq) {
      if (i & 1) odd += 1;
    }

    return s.size() - odd + (odd > 0);
  }
};