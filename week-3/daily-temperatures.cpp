class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temp) {
    vector<int> dates(temp.size(), 0);
    for (int i = temp.size() - 2; i >= 0; i--) {
      int j = 1;
      while (i + j < temp.size() && temp[i] >= temp[i + j]) {
        if (dates[i + j] == 0)
          j = temp.size() - i;
        else
          j += dates[i + j];
      }
      if (i + j >= temp.size()) j = 0;
      dates[i] = j;
    }
    return dates;
  }
};