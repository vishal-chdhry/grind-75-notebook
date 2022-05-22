class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string current_common_string = strs[0];
    for (string s : strs) {
      int i = 0;
      int size = min(s.size(), current_common_string.size());
      for (i = 0; i < size; i++) {
        if (current_common_string[i] != s[i]) break;
      }
      current_common_string = s.substr(0, i);
    }
    return current_common_string;
  }
};