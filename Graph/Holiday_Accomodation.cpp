
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

long long ans;
vector<bool> vis(100005);
vector<int> cnt(100005);

long long dfs(int src, vector<pair<int, int>>adj[], int n) {
	vis[src] = true;
	cnt[src] = 1;

	for (auto node : adj[src]) {
		int nbr = node.first;
		int wt = node.second;
		if (!vis[nbr]) {
			cnt[src] += dfs(nbr, adj, n);
			int nx = cnt[nbr];
			int ny = (n) - nx;
			ans += 2ll * min(nx, ny) * wt;
		}
	}
	return cnt[src];
}

int main()
{
	boost;
	int t;
	cin >> t;
	for (int j = 1; j <= t; j++) {
		int n;
		cin >> n;

		vector<pair<int, int>> adj[n + 1];

		for (int i = 0; i < n - 1; i++) {
			int x, y, wt;
			cin >> x >> y >> wt;
			adj[x].pb({y, wt});
			adj[y].pb({x, wt});
		}
		for (int i = 1; i <= n; i++) {
			cnt[i] = 0;
			vis[i] = false;
		}
		ans = 0;
		dfs(1, adj, n);

		cout << "Case #" << j << ": " << ans << endl;

	}
	return 0;
}