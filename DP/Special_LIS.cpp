#include <bits/stdc++.h>
using namespace std;
int n;
map<int, map<int, map<int, map<int, int>>>> m;

int fun(int i, int le, int d, int i1, vector<int> a)
{
	if (m[i][le][d][i1]) return m[i][le][d][i1];
	if (i == n) return m[i][le][d][i1] = le;
	if (le == 0) return m[i][le][d][i1] = max(fun(i + 1, 1, 0, i, a), fun(i + 1, 0, 0, i + 1, a));
	if (a[i] - a[i1] >= d) return m[i][le][d][i1] = max(fun(i + 1, le + 1, a[i] - a[i1], i, a), fun(i + 1, le, d, i1, a));

	return m[i][le][d][i1] = fun(i + 1, le, d, i1, a);
}

int main()
{
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << fun(0, 0, 0, 0, a);
}