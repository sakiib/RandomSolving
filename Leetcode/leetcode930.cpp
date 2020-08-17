class Solution {
public:
  int solve(vector <int> &A) {
    int ans = 0;
    for (int i = 0; i < A.size(); ) {
      if (A[i] == 0) {
        int j = i;
        while (j < A.size() && A[j] == 0) j++;
        int len = j - i;
        ans += len * (len + 1) / 2;
        i = j;
      }
      else i++;
    }
    return ans;
  }

  int numSubarraysWithSum(vector<int>& A, int S) {
    if (S == 0) return solve(A);

    int sum = 0, ans = 0, temp = 0;

    int l = 0;
    for (int r = 0; r < A.size(); r++) {
      sum += A[r];
      if (sum == S){
        temp++;
        if (r == A.size() - 1 || A[r + 1] == 1) {
          while (sum == S) sum -= A[l++], ans += temp;
          temp = 0;
        }
      }
    }
    return ans;
  }
};
