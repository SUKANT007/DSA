#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<long long int> dp(100001);
int solve(int n, int m) {

	if (n < 0) return 0;

	if (n == 0) {
		return 1;
	}

	if (dp[n] != 0) return dp[n];

	return dp[n] = (solve(n - m, m) % mod + solve(n - 1, m) % mod) % mod;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n; i++) dp[i] = 0;
		cout << solve(n, m) << endl;
	}
	return 0;
}