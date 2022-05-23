class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int a_map[26] = {0}, b_map[26] = {0};
    for (char c : ransomNote) {
      a_map[c - 'a']++;
    }
    for (char c : magazine) {
      b_map[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (a_map[i] > b_map[i]) return false;
    }
    return true;
  }
};