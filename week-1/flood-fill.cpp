class Solution {
 public:
  void fill(vector<vector<int>>& image, int sr, int sc, int newColor,
            int currentColor) {
    int i = image.size() - 1;
    int j = image[0].size() - 1;
    if (sr < 0 || sc < 0 || sr > i || sc > j)
      return;
    else if (currentColor == image[sr][sc]) {
      image[sr][sc] = newColor;
      fill(image, sr + 1, sc, newColor, currentColor);
      fill(image, sr - 1, sc, newColor, currentColor);
      fill(image, sr, sc - 1, newColor, currentColor);
      fill(image, sr, sc + 1, newColor, currentColor);
    } else {
      return;
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    int curr_clr = image[sr][sc];
    if (newColor == curr_clr) return image;
    fill(image, sr, sc, newColor, curr_clr);
    return image;
  }
};