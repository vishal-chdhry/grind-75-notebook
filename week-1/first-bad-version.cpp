// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  int bs(int n, int start, int end) {
    if (end - start <= 1)
      return end;
    else {
      bool bad = isBadVersion(start + (end - start) / 2);
      if (bad) {
        return bs(n, start, start + (end - start) / 2);
      } else {
        return bs(n, start + (end - start) / 2, end);
      }
    }
  }
  int firstBadVersion(int n) { return bs(n, 0, n); }
};