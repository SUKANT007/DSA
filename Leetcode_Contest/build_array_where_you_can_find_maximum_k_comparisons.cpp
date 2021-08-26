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

const ll mod = 1e9 + 7;
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



ll solveSuffix(int n, int maxM, int idx, vector<vector<ll>> &suffix) {

	if (idx == n - 1) return 1;


	if (suffix[maxM][idx] != -1) return suffix[maxM][idx];


	ll ans = 0;

	for (int i = 1; i <= maxM; i++) {

		ans =  ( ans +  solveSuffix(n, i, idx + 1, suffix) % mod ) % mod;

	}


	return suffix[maxM][idx] = ans;


}


ll solvePrefix(int idx, int swaps, int maxM, vector<vector<vector<ll>>> &prefix) {

	if (swaps < 0 || maxM <= 0 || idx < 0) return 0;


	if (idx == 0) {

		if (swaps == 0 && maxM >= 1) return 1;
		else return 0;
	}


	if (prefix[idx][maxM][swaps] != -1) return prefix[idx][maxM][swaps];

	ll ans = 0;

	return prefix[idx][maxM][swaps] = (solvePrefix(idx - 1, swaps - 1, maxM - 1, prefix) % mod  + solvePrefix(idx - 1, swaps, maxM, prefix) % mod ) % mod;


}


int numOfArrays(int n, int m, int k) {

	int maxN = max({n, m, k});


	vector<vector<ll>> suffix(maxN + 1, vector<ll>(maxN + 1, -1));

	vector<vector<vector<ll>>> prefix(maxN + 1 , vector<vector<ll>>(maxN + 1, vector<ll>(maxN + 1, -1)));

	ll ans = 0;
	k--;

	if (k == 0) {

		for (int maxM = 1 ; maxM <= m ; maxM++) {

			cout << 0 << " " << maxM << endl;
			ans =  ( ans + (solvePrefix(0, k, maxM, prefix)  *  solveSuffix(n, maxM, 0, suffix) ) % mod ) % mod;

			watch(ans);
		}

		return ans;

	}


	for (int i = 0; i < n; i++) {

		for (int maxM = 1 ; maxM <= m ; maxM++) {

			//cout << i << " " << maxM << endl;
			ans =  ( ans + (solvePrefix(i, k, maxM, prefix) )) % mod;

			//watch(ans);
		}

	}

	return ans;


}


int main()
{
	boost;
	int n, m, k;
	cin >> n >> m >> k;

	cout << numOfArrays(n, m, k) << endl;
	return 0;
}