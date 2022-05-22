class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
      if (st.empty())
        st.push(c);
      else if (st.top() == '[' && c == ']')
        st.pop();
      else if (st.top() == '(' && c == ')')
        st.pop();
      else if (st.top() == '{' && c == '}')
        st.pop();
      else
        st.push(c);
    }
    return st.empty();
  }
};