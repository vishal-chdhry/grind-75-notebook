class Solution {
 public:
  static bool comp(pair<int, string> i1, pair<int, string> i2) {
    if (i1.first < i2.first)
      return true;
    else if (i1.first > i2.first)
      return false;
    else
      return i1.second.compare(i2.second) > 0;
  }
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    vector<pair<int, string>> vp;
    for (string s : words) {
      if (mp.find(s) == mp.end()) {
        mp[s] = 1;
      } else {
        mp[s]++;
      }
    }

    for (auto val : mp) {
      vp.push_back({val.second, val.first});
    }
    sort(vp.begin(), vp.end(), comp);
    vector<string> ans;
    for (int i = vp.size() - 1; i >= 0; i--) {
      if (k-- > 0) ans.push_back(vp[i].second);
    }
    return ans;
  }
};