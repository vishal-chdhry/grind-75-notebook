class Solution {
 public:
  struct job {
    int start;
    int end;
    int profit;
  };

  static int comp(job m, job n) { return m.end < n.end; }

  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int sz = startTime.size();
    vector<job> jobVec(sz);
    for (int i = 0; i < sz; i++) {
      jobVec[i].start = startTime[i];
      jobVec[i].end = endTime[i];
      jobVec[i].profit = profit[i];
    }
    sort(jobVec.begin(), jobVec.end(), comp);

    vector<int> dp(sz, 0);
    for (int i = 0; i < sz; i++) {
      if (i == 0)
        dp[i] = jobVec[i].profit;
      else {
        int idx = sz - 1;
        int f = 0;
        for (int j = i - 1; j >= 0; j--)
          if (jobVec[j].end <= jobVec[i].start) {
            f = dp[j];
            break;
          }
        dp[i] = max(dp[i - 1], f + jobVec[i].profit);
      }
    }
    return dp[sz - 1];
  }
};