
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
#define		endl "\n"
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
#define N 100006
vector<int> adj[N]; // used for representing the tree
vector<int> startime(N);// starttime[i] notes the time at which DFS enters node
vector<int> endtime(N);	// endtime[i] notes the time at which DFS exits node i
int tme; //a global variable that stores the timer at that instant
vector<bool> vis(N, false);

void dfs(int node) {
	vis[node] = true;
	startime[node] = tme++;

	for (auto child : adj[node]) {
		if (!vis[child]) {
			dfs(child);
		}
	}

	endtime[node] = tme++;
}

bool check(int x, int y) {
	// checks weather node x lies in the subtree of node y or not
	if (startime[x] > startime[y] && endtime[x] < endtime[y]) {
		return true;
	}
	return false;
}

int main()
{
	boost;
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		//adj[y].push_back(x);
	}
	int t;
	cin >> t;
	tme = 1;
	dfs(1);

	while (t--) {
		int type, x, y;
		cin >> type >> x >> y;

		if (!check(x, y) &&  !check(y, x)) {
			cout << "NO" << endl;
			continue;
		}

		if (type) {
			if (check(x, y))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else {
			if (check(y, x))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}