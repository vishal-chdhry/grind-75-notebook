class Solution {
 public:
  unordered_set<string> visited;
  unordered_map<string, vector<string>> adjecent;
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    for (auto account : accounts) {
      string firstAccountEmail = account[1];

      for (int i = 2; i < account.size(); i++) {
        adjecent[firstAccountEmail].push_back(account[i]);
        adjecent[account[i]].push_back(firstAccountEmail);
      }
    }

    vector<vector<string>> ans;
    for (auto account : accounts) {
      vector<string> acc;
      acc.push_back(account[0]);

      if (visited.find(account[1]) == visited.end()) {
        dfs(acc, account[1]);
        sort(acc.begin() + 1, acc.end());
        ans.push_back(acc);
      }
    }
    return ans;
  }

  void dfs(vector<string>& account, string email) {
    visited.insert(email);

    account.push_back(email);
    for (string neighbour : adjecent[email]) {
      if (visited.find(neighbour) == visited.end()) {
        dfs(account, neighbour);
      }
    }
  }
};