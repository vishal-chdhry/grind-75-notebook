class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> vs;
    for (int i : nums) vs.push_back(to_string(i));
    sort(vs.begin(), vs.end(),
         [](string s1, string s2) { return s1 + s2 > s2 + s1; });
    string str = "";
    for (string s : vs) str += s;
    while (str[0] == '0' && str.length() > 1) str.erase(0, 1);
    return str;
  }
};