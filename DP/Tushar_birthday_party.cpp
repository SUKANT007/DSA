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

int solve2(const vector<int> &cap, const vector<int> &dish, const vector<int> &cost) {

	int mx = *max_element(cap.begin(), cap.end());
	vector<int> dp(mx + 1, 100000001);
	dp[0] = 0;
	for (int capacity = 1; capacity <= mx; capacity++) {
		for (int i = 0; i < dish.size(); i++) {
			if (dish[i] <= capacity) {
				dp[capacity] = min(dp[capacity], dp[capacity - dish[i]]  + cost[i]);
			}

		}
	}

	int ans = 0;
	for (int i = 0; i < cap.size(); i++) {
		ans += dp[cap[i]];
	}

	return ans;
}

int solve(const vector<int> &cap, const vector<int> &dish, const vector<int> &cost) {


	int mx = *max_element(cap.begin(), cap.end());
	int n = dish.size();
	int dp[n + 1][mx + 1];
	//watch(mx);
	for (int i = 0; i <= mx; i++) {
		dp[0][i] = 100000001;
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= mx; j++) {
			if (dish[i - 1] <= j) {
				dp[i][j] = min(dp[i][j - dish[i - 1]] + cost[i - 1], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= mx; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	int ans = 0;

	for (int i = 0; i < cap.size(); i++) {
		//watch(dp[n][cap[i]]);
		ans += dp[n][cap[i]];
	}

	return ans;
}


int main()
{
	boost;
	int n;
	cin >> n;
	vector<int> cap(n);
	int m;
	cin >> m;
	vector<int> dish(m);
	vector<int> cost(m);

	rep(i, n) cin >> cap[i];
	rep(i, m) cin >> dish[i];
	rep(i, m) cin >> cost[i];


	//cout << solve(cap, dish, cost) << endl;
	cout << solve2(cap, dish, cost) << endl;


	return 0;
}