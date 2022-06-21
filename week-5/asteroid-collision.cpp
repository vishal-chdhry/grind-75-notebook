class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    deque<int> bucket;
    for (int i : asteroids) {
      int current = i;
      while (!bucket.empty() && bucket.back() > 0 && current < 0) {
        int a = bucket.back();
        bucket.pop_back();
        if (abs(a) > abs(current)) current = a;
        if (a == -1 * current) {
          current = INT_MIN;
          break;
        };
      }
      if (current != INT_MIN) bucket.push_back(current);
    }
    vector<int> ans;
    while (!bucket.empty()) {
      ans.push_back(bucket.front());
      bucket.pop_front();
    }
    return ans;
  }
};