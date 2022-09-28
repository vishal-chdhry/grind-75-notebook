class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    vector<int> v(s.size(), 0);
    v[0] = 1;
    for (int i = 1; i < s.size(); i++) {
      string a = s.substr(i - 1, 2);
      v[i] += (stoi(a) <= 26 && stoi(a) >= 10 && s[i - 1] != '0')
                  ? (i - 2 >= 0 ? v[i - 2] : 1)
                  : 0;
      v[i] += (s[i] >= '1' && s[i] <= '9') ? v[i - 1] : 0;
    }
    return v.back();
  }
};