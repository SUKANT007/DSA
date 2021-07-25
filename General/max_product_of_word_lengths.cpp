#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // remove for interactive

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

#define 	INF 1e18
#define 	endl "\n" // remove for interactive
#define 	PI 3.1415926535897932384626
#define 	all(x) x.begin(),x.end()
#define 	mem(a,b) memset(a,b,sizeof(a))
#define 	gcd(a,b) (__gcd((a),(b)))
#define 	lcm(a,b) (((a)*(b))/gcd((a),(b)))
#define 	pb push_back
#define 	rep(i,n) for (int i = 0; i < n; ++i)
#define 	REP(i,k,n) for (int i = k; i <= n; ++i)
#define 	REPR(i,k,n) for (int i = k; i >= n; --i)
#define 	watch(x) cout << (#x) << " is " << (x) << endl
#define 	binary(n) cout<<bitset<32>(n)<<"\n"
#define 	ps(x,y) fixed<<setprecision(y)<<x
#define 	tr(container,it) for(auto it=container.begin();it!=container.end();it++)
#define 	present(container, element) (container.find(element) != container.end())
#define 	vpresent(container, element) (find(all(container),element) != container.end())//for vectors

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

ll mod;
ll power(ll a, ll b) //a is base, b is exponent
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % mod;
	int q = power(a, b / 2);
	return (q * q) % mod;
}

// Before sub : check for out of bounds , long long , floating point exception(division by zero) ,indexes , 0 , 1


int maxProduct(vector<string>& words) {

	int n = words.size();
	bool matrix[n][n];

	memset(matrix, true, sizeof(matrix));
	vector<int> adj[26];

	for (auto ch = 'a'; ch <= 'z'; ch++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < words[i].length(); j++) {
				if (words[i][j] == ch) {
					adj[ch - 'a'].push_back(i);
					break;
				}
			}
		}
	}


	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			for (int k = 0; k < adj[i].size(); k++) {
				matrix[adj[i][j]][adj[i][k]] = false;
			}
		}
	}


	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][j]) {
				ans = max(ans, (int)words[i].length() * (int)words[j].length());
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	// for (auto ch = 'a'; ch <= 'z'; ch++) {
	// 	cout << ch << " ";
	// 	for (int i = 0; i < adj[ch - 'a'].size(); i++) {
	// 		cout << adj[ch - 'a'][i] << " ";
	// 	}
	// 	cout << endl;
	// }

	return ans;

}

int maxProductOptimized(vector<string> &words) {
	int n = words.size();
	vector<int> value(n);

	for (int i = 0; i < n; i++) {
		string word = words[i];

		for (auto ch : word) {
			value[i] |= (1 << (ch - 'a'));
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((value[i] & value[j]) == 0) {
				ans = max(ans, (int)words[i].length() * (int)words[j].length());
			}
		}
	}

	return ans;
}

int main()
{
	boost;
	int n;
	cin >> n;
	vector<string> words;
	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		words.push_back(word);
	}

	cout << maxProductOptimized(words);


	return 0;
}