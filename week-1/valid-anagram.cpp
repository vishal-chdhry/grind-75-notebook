class Solution {
 public:
  bool isAnagram(string s, string t) {
    int s_map[26] = {0}, t_map[26] = {0};

    for (char c : s) s_map[c - 'a']++;
    for (char c : t) t_map[c - 'a']++;

    for (int i = 0; i < 26; i++)
      if (t_map[i] != s_map[i]) return false;

    return true;
  }
};