class Solution {
 public:
  string addBinary(string a, string b) {
    a.insert(a.begin(), 1e4 - a.size(), '0');
    b.insert(b.begin(), 1e4 - b.size(), '0');
    int size = max(a.size(), b.size());
    vector<int> ans(size);
    int count = 0, ptr1 = a.size() - 1, ptr2 = b.size() - 1;
    for (int i = size - 1; i >= 0; i--) {
      int sum = a[i] - '0' + b[i] - '0' + count;
      if (sum == 0) {
        ans[i] = 0;
        count = 0;
      } else if (sum == 1) {
        count = 0;
        ans[i] = 1;
      } else if (sum == 2) {
        count = 1;
        ans[i] = 0;
      } else if (sum == 3) {
        count = 1;
        ans[i] = 1;
      }
    }
    cout << count;
    string resp;
    bool add = false;
    for (int i : ans) {
      if (i) add = true;
      if (add) resp.push_back('0' + i);
    }
    if (resp.size() == 0) resp.push_back('0');
    return resp;
  }
};