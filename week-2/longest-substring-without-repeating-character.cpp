class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int freq[128] = {0}, ptr1 = 0, ptr2 = 0, currSize = 0, maxSize = 0;
    for (int i = 0; i < s.size(); i++) {
      ptr2 = i;
      while (freq[s[i]]) {
        freq[s[ptr1]] = 0;
        ptr1++;
      }
      currSize = ptr2 - ptr1 + 1;
      maxSize = max(maxSize, currSize);
      freq[s[i]] = 1;
    }
    return maxSize;
  }
};