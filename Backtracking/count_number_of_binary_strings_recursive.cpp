#include<bits/stdc++.h>
using namespace std;

int ans ;

void count(int i, int n, int prev) {
	if (i == n + 1) {
		ans++;
		return;
	}
	count(i + 1, n, 0);
	if (prev == 0) {
		count(i + 1, n, 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ans = 0;
		count(1, n, 0);
		cout << ans << endl;

	}
	return 0;
}