
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

#define N 100005

int dis[N], low[N], tme;
vector<int> adj[N];
set<int> art_p;
vector<pair<int, int>> bridge;


void dfs(int node , int par) {
	dis[node] = low[node] = tme++;
	int no_child = 0;

	for (auto child : adj[node]) {

		//not visited
		if (dis[child] == 0) {

			dfs(child, node);
			no_child++;

			low[node] = min(low[node], low[child]);

			//art point
			if (par != 0 && low[child] >= dis[node]) {
				art_p.insert(node);
			}

			//bridge
			if (low[child] > dis[node]) {
				bridge.push_back({node, child});
			}
		}
		else if (child != par) {
			//found the back edge
			//cycle
			low[node] = min(low[node], dis[child]);

		}
	}

	// separate case for root to be articulation point

	if (par == 0 && no_child >= 2) {
		art_p.insert(node);
	}
	return;
}
int main()
{
	boost;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}

	tme = 1;
	dfs(1, 0);

	cout << "articulation points : ";
	for (auto x : art_p) cout << x << " ";

	cout << endl;

	cout << "bridge edges : " << endl;
	for (auto edge : bridge) {
		cout << edge.first << " " << edge.second << endl;
	}


	return 0;
}