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


int solve(int i, int n, map<int, vector<int>> &indexes, vector<int> &dp, vector<int> &arr) {

	if (i == n - 1) return 0;

	if (dp[i] != -1) return dp[i];



	int ans = INT_MAX;

	if (i + 1 < n - 1) {
		ans = min(ans, solve(i + 1, n, indexes, dp, arr) + 1);
	}

	if (i - 1 >= 0) {
		ans = min(ans, solve(i - 1, n, indexes, dp, arr) + 1);
	}

	for (auto idx : indexes[arr[i]]) {
		if (idx != i)
			ans = min(ans, solve(idx, n, indexes, dp, arr) + 1);

	}

	return dp[i] = ans;



}


int minJumps(vector<int>& arr) {



	map<int, vector<int>> indexes;
	int n = arr.size();

	if (n == 1) return 0;

	for (int i = 0; i < n; i++) {
		indexes[arr[i]].push_back(i);
	}

	vector<int> dp(n + 1, -1);

	dp[n - 1] = 0;
	// dp[n-2] = 1;

	return solve(0, n, indexes, dp, arr);

}

int main()
{
	boost;
	int n;
	cin >> n;
	vector<int> arr(n);
	rep(i, n) cin >> arr[i];
	cout << minJumps(arr) << endl;
	return 0;
}