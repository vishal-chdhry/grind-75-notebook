class Solution {
 public:
  static bool comparator(pair<string, int> p1, pair<string, int> p2) {
    return p1.first.compare(p2.first) < 0;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<pair<string, int>> sorted;
    for (int i = 0; i < strs.size(); i++) {
      string s = strs[i];
      sort(s.begin(), s.end());
      auto pr = make_pair(s, i);
      sorted.push_back(pr);
    }

    sort(sorted.begin(), sorted.end(), comparator);

    for (auto a : sorted) {
      cout << a.first << endl;
    }

    vector<vector<string>> ans;
    int i = 0;
    while (i < sorted.size()) {
      vector<string> tbp;
      tbp.push_back(strs[sorted[i].second]);
      i++;
      while (i < sorted.size() && sorted[i - 1].first == sorted[i].first) {
        string st = strs[sorted[i].second];
        tbp.push_back(st);
        i++;
      }
      ans.push_back(tbp);
    }
    return ans;
  }
};