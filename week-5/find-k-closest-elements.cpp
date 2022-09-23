class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto l = lower_bound(arr.begin(), arr.end(), x);
    if (l >= arr.end() || *l >= x) l--;
    if (l < arr.begin()) l++;
    auto r = l + 1;
    vector<int> ans;
    while (ans.size() < k) {
      if (r >= arr.end() ||
          (l >= arr.begin() && r < arr.end() && x - *l <= *r - x)) {
        ans.push_back(*l);
        l--;
      } else if (l < arr.begin() ||
                 (l >= arr.begin() && r < arr.end() && x - *l > *r - x)) {
        ans.push_back(*r);
        r++;
      }
    }
    sort(ans.begin(), ans.end());

    return ans;
  }
};