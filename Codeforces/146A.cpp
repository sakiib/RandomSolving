#include <bits/stdc++.h>
using namespace std;

// lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7.
bool lucky(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '4' && s[i] != '7') {
			return false;
		}
	}
	return true;
}

// calculates sum of digits of string s, in a range (positions) [l, r]
int sumOfDigits(string s, int l, int r) {
	int sum = 0;
	for (int i = l; i <= r; i++) {
		sum += s[i] - '0';
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int len;
	cin >> len;
	string s;
	cin >> s;
	
	// YES: s is lucky and sum(first half) is equal to sum(second half)
	if (lucky(s) && sumOfDigits(s, 0, len/2 - 1) == sumOfDigits(s, len/2, len - 1)) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
	}
	return 0;
}
