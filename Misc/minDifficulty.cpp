#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e9;
    int dp[300 + 1][300 * 100 + 1][10 + 1];

    int solve(int idx, int mx, int days, vector <int>& jobDifficulty) {
        if (idx == (int)jobDifficulty.size()) {
            return days == 0? mx: INF;
        }

        if (dp[idx][mx + 1][days] != -1) {
            return dp[idx][mx + 1][days];
        }

        int minDifficulty = INF;
        if (mx == -1) {
            minDifficulty = min(minDifficulty, solve(idx + 1, jobDifficulty[idx], days - 1, jobDifficulty));
        } else {
            minDifficulty = min(minDifficulty, mx + solve(idx + 1, jobDifficulty[idx], days - 1, jobDifficulty));
            minDifficulty = min(minDifficulty, solve(idx + 1, max(mx, jobDifficulty[idx]), days, jobDifficulty));
        }

        return dp[idx][mx + 1][days] = minDifficulty;
    }

    int minDifficulty(vector<int>& jobDifficulty, int days) {
        int totalJobs = jobDifficulty.size();
        if (totalJobs < days) {
            return -1;
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, -1, days, jobDifficulty);
    }
};

int main() {
	int days = 2;
	vector <int> jobDifficulty = {6,5,4,3,2,1};
	cout << s.minDifficulty(jobDifficulty, days) << "\n";
	return 0;
}
