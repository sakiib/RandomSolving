#include <bits/stdc++.h>
using namespace std;

vector <int> cost = {1, 2, 3, 2, 2};
vector <int> value = {8, 4, 0, 5, 3};
int capacity = 4;
int dp[5][15];
int mx_profit;

int solve(int idx, int rem) {
    if (idx >= cost.size()) return 0;
    if (dp[idx][rem] != -1) return dp[idx][rem];
    int mx = 0;
    mx = max(mx, solve(idx + 1, rem));
    if (rem - cost[idx] >= 0) {
        mx = max(mx, solve(idx + 1, rem - cost[idx]) + value[idx]);
    }
    return dp[idx][rem] = mx;
}

void print_solution(int idx, int rem, int added) {
    if (idx >= cost.size()) return;
    if (rem - cost[idx] >= 0 && solve(idx + 1, rem - cost[idx]) + value[idx] + added == mx_profit) {
        cout << "items: " << idx << " " << value[idx] << endl;
        print_solution(idx + 1, rem - cost[idx], added + value[idx]);
        return;
    } else {
        print_solution(idx + 1, rem, added);
        return;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    mx_profit = solve(0, capacity);
    cout << "mx: " << mx_profit << endl;
    print_solution(0, capacity, 0);
    return 0;
}

// easy way to print knapsack(DP) solution
