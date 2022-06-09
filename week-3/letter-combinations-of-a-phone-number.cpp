class Solution {
 public:
  vector<string> chars{"",    "",    "abc",  "def", "ghi",
                       "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> ans;
  string genS = "";
  void gen(string& digits, int index) {
    if (index == digits.size()) {
      ans.push_back(genS);
    } else {
      string current = chars[digits[index] - '0'];
      for (char c : current) {
        genS.push_back(c);
        gen(digits, index + 1);
        genS.pop_back();
      }
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits.size()) gen(digits, 0);
    return ans;
  }
};