class Solution {
 public:
  int calculate(string s) {
    stack<int> numbers;
    stack<char> operations;
    string st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
          st.push_back(s[i]);
          i++;
        }
        stringstream num(st);
        int i;
        num >> i;
        numbers.push(i);
        st.clear();
        if (!operations.empty() &&
            (operations.top() == '*' || operations.top() == '/')) {
          int a = numbers.top();
          numbers.pop();
          int b = numbers.top();
          numbers.pop();
          if (operations.top() == '*') {
            numbers.push(a * b);
          } else {
            numbers.push(a / b);
          }
          operations.pop();
        }
      }

      while (!numbers.empty() || !operations.empty()) {
        cout << numbers.top() << operations.top();
        numbers.pop();
        operations.pop();
      }
    }
    return 0;
  }
};