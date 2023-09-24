#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>v[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	int idx = 0;
	int max_Zero = 0;
	for (int i = 0; i < m - 1; i++) {
		if (v[0][i + 1] == 1) {
			idx = i;
			max_Zero = m - i - 1;
			break;
		}
	}


	int i = 1;
	while (i < n) {
		if (v[i][idx] == 1) {
			while (idx >= 0) {
				if (v[i][idx] == 0) {
					break;
				}
				else {
					idx--;
				}
			}
		}
		i++;
	}

	if (idx == -1) {
		max_Zero = m;
	}
	else {
		max_Zero = m - idx - 1;
	}


	cout << max_Zero << endl;


	return 0;
}