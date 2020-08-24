class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector <vector <string>> ret;
      map <string,int> have;
      int id = 0;
      map <int, vector <string> > res;
      for (int i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if (have.count(temp) == 0) have[temp] = ++id;
        res[have[temp]].push_back(strs[i]);
      }
      for (auto x: res) ret.push_back(x.second);
      return ret;
    }
};
