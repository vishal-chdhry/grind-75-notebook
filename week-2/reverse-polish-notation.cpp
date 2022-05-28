class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> num;
    for (string s : tokens) {
      if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9') {
        num.push(stoi(s));
      } else {
        int a = num.top();
        num.pop();
        int b = num.top();
        num.pop();
        if (s[0] == '+') {
          num.push(a + b);
        } else if (s[0] == '-') {
          num.push(b - a);
        } else if (s[0] == '*') {
          num.push(a * b);
        } else if (s[0] == '/') {
          num.push(b / a);
        }
      }
    }
    return num.top();
  }
};