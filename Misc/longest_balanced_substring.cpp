#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;

	stack <pair <char, int> > st;
	vector <int> dp ((int)s.size(), 0);
	// dp[i] = longest balanced substring ending at i'th position
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(make_pair('(', i));
		} else {
			if (st.empty() || st.top().first != '(') {
				st.push(make_pair(')', i));
			} else {
				pair <char,int> x = st.top(); st.pop();
				dp[i] = (i - x.second + 1) + (x.second - 1 >= 0? dp[x.second - 1]: 0);
			}
		}
	}

	int longest = 0;
	for (int i = 0; i < s.size(); i++) {
		longest = max(longest, dp[i]);
	}

	int occurrence = 0;
	for (int i = 0; i < s.size(); i++) {
		if (dp[i] == longest) {
			occurrence++;
		}
	}

	if (longest == 0) {
		cout << 0 << " " << 1 << "\n";
	} else {
		cout << longest << " " << occurrence << "\n";
	}
    return 0;
}
