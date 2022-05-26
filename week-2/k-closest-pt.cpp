class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>> &ps, int K) {
    nth_element(begin(ps), begin(ps) + K, end(ps),
                [](vector<int> &a, vector<int> &b) {
                  return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
                });
    ps.resize(K);
    return ps;
  }
};