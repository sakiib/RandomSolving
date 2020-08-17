class Solution {
public:
  int longestMountain(vector<int>& A) {
    int mx = 0;
    for (int i = 0; i + 1 < A.size(); ) {
      if (A[i] < A[i + 1]) {
        int j = i + 1;
        while (j < A.size() && A[j] > A[j - 1]) j++;
        if (j == A.size()) break;
        int prev = j;
        bool f = false;
        while (j < A.size() && A[j] < A[j - 1]) j++, f = true;
        if (f) mx = max(mx, j - i);
        i = prev;
      }
      else {
        i++;
      }
    }
    return mx;
  }
};
