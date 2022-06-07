class Solution {
 public:
  int maxArea(vector<int>& hist) {
    int it_st = 0, it_lt = hist.size() - 1;
    int max_area = (min(hist[it_st], hist[it_lt]) * (it_lt - it_st)),
        curr_area = 0;
    while (it_st < it_lt) {
      curr_area = (min(hist[it_st], hist[it_lt]) * (it_lt - it_st));
      max_area = max(curr_area, max_area);
      if (hist[it_st] > hist[it_lt])
        it_lt--;
      else
        it_st++;
    }
    return max_area;
  }
};