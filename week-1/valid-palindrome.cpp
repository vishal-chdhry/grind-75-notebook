class Solution {
 public:
  bool isPalindrome(string s) {
    vector<char> vt;
    for (char c : s) {
      if (c >= 'A' && c <= 'Z')
        vt.push_back(c + 32);
      else if (c >= 'a' && c <= 'z')
        vt.push_back(c);
      else if (c >= '0' && c <= '9')
        vt.push_back(c);
    }

    int i = 0, j = vt.size() - 1;
    while (i < j) {
      if (vt[i++] != vt[j--]) return false;
    }
    return true;
  }
};