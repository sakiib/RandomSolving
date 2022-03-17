class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int len = fruits.size();
    vector <pair <int, int> > f;
    for (int i = 0; i < len; i+=0) {
      int j = i + 1;
      while (j < len && fruits[j] == fruits[i]) {
        j++;
      }
      f.push_back({fruits[i], j - i});
      i = j;
    }

    // for (auto [key, val]: f) {
    //   cout << key << " " << val << endl;
    // }

    if ((int)f.size() == 1) {
      return f[0].second;
    }
    if ((int)f.size() == 2) {
      return f[0].second + f[1].second;
    }

    int first = f[0].first, second = f[1].first, cnt = f[0].second + f[1].second;
    int mx = cnt;
    for (int i = 2; i < f.size(); i++) {
      int cur = f[i].first;
      if (cur == first || cur == second) {
        cnt += f[i].second;
      } else {
        first = f[i - 1].first;
        second = cur;
        cnt = f[i - 1].second + f[i].second;
      }
      mx = max(mx, cnt);
    }

    return mx;
  }
};
