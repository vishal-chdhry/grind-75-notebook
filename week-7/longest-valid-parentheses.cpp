class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0, curr = 0;
    for (int i = 0; i < s.size(); i++) {
      curr++;
      if (s[i] == '(')
        st.push(i);
      else {
        if (st.top() == -1) {
          ans = max(ans, curr - 1);
          curr = 0;
        } else {
          st.pop();
          ans = max(ans, min(curr, (int)(i - st.top())));
        }
      }
    }
    return ans;
  }
};