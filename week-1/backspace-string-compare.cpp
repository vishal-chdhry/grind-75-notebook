class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '#') {
        int k = i - 1;
        s[i] = ' ';
        while (k >= 0 && s[k] == 32) {
          k--;
        }
        if (k >= 0) s[k] = 32;
      }
    }

    for (int i = 0; i < t.size(); i++) {
      if (t[i] == '#') {
        int k = i - 1;
        t[i] = ' ';
        while (k >= 0 && t[k] == 32) {
          k--;
        }
        if (k >= 0) t[k] = 32;
      }
    }
    string a, b;
    for (char c : s) {
      if (c != 32) {
        a.push_back(c);
      }
    }

    for (char c : t) {
      if (c != 32) {
        b.push_back(c);
      }
    }

    return a == b;
  }
};