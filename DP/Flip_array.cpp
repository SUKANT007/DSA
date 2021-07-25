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


#define ll long long






int solve(const vector<int> &A) {

	ll sum = 0 ;
	int  n = A.size();
	for (int i = 0; i < n; i++) {
		sum += A[i];
	}

	sum /= 2;

	int dp[n + 1][sum + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) {
				dp[i][j] = INT_MAX - 1;
			}

			if (j == 0) {
				dp[i][j] = 0;
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (A[i - 1] <= j) {
				dp[i][j] = min(1 + dp[i - 1][j - A[i - 1]] , dp[i - 1][j] );
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}


	for (int j = sum; j >= 0; j--) {
		if (dp[n][j] < INT_MAX - 1) return dp[n][j];
	}

	return dp[n][sum];
}


int main()
{
	boost;
	int n;
	cin >> n;
	vector<int> A(n);
	rep(i, n) cin >> A[i];

	cout << solve(A) << endl;
	return 0;
}