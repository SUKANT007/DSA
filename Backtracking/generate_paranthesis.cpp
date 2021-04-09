#include<bits/stdc++.h>
using namespace std;
vector<string> ans;

void generate(int n, int left, int right, string cur) {
	if (n == 0) {
		ans.push_back(cur);
		return;
	}

	if (left > 0) generate(n - 1, left - 1, right, cur + '(');
	if (right > left) generate(n - 1, left, right - 1, cur + ')');

}

int main() {
	int n;
	cin >> n;
	generate(2 * n, n, n, "");
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}