class Solution {
 public:
  int characterReplacement(string s, int k) {
    int result = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
      int start = -1, curr = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
          curr++;
        }
        while (k < i - start - curr) {
          if (s[start + 1] == c) {
            curr--;
          }
          start++;
        }
        result = max(result, i - start);
      }
    }
    return result;
  }
};