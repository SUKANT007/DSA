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

long long wonderfulSubstrings(string word) {

	int n = word.length();

	if (n == 1) return 1;

	long long dp[n + 1][2];
	long long oddChar[n + 1][10];

	memset(dp, 0, sizeof(dp));
	memset(oddChar, 0, sizeof(oddChar));


	dp[0][1] = 1;
	oddChar[0][word[0] - 'a'] = 1;
	dp[0][0] = 0;

	long long sum = 1;

	for (int i = 1; i < n; i++) {

		dp[i][0] = oddChar[i - 1][word[i] - 'a'];
		dp[i][1] = dp[i - 1][0] + 1;
		//oddChar[i][word[i] - 'a'] =  dp[i - 1][0] + 1;
		sum += (dp[i][0] + dp[i][1]);

		for (int j = 0; j < 10; j++) {
			oddChar[i][j] = oddChar[i - 1][j];
		}

		oddChar[i][word[i] - 'a'] +=  1;

	}


	for (int i = 0; i < n; i++) {
		watch(i);
		for (char ch = 'a' ; ch <= 'j' ; ch++) {
			cout << ch << " " << oddChar[i][ch - 'a'] << endl;
		}
	}


	for (int i = 0; i < n; i++) {
		watch(i);
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}


	return sum;



}

int main()
{
	boost;
	string word;
	cin >> word;
	cout << wonderfulSubstrings(word);
	return 0;
}