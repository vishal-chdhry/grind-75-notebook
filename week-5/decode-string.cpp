class Solution {
 public:
  string decodeString(string s) {
    stack<char> st;
    for (char c : s) {
      if (c == ']') {
        string str;
        while (st.top() != '[') {
          str.push_back(st.top());
          st.pop();
        }
        st.pop();
        string num;
        while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
          num.push_back(st.top());
          st.pop();
        }
        reverse(num.begin(), num.end());
        int n = stoi(num);
        reverse(str.begin(), str.end());
        while (n--) {
          for (char ch : str) {
            st.push(ch);
          }
        }
      } else
        st.push(c);
    }
    string ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};