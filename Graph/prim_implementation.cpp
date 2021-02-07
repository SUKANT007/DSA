
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

class Graph {
	vector<pair<int, int>> *adj; // ADjacency list
	int V;
public:
	Graph(int n) {
		V = n;
		adj = new vector<pair<int, int>>[V];
	}
	void addEdge(int x, int y, int w) {
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}

	long long int prim_mst() {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
		// another array
		//Visited array that denotes whether a node has been included in MST or not

		bool *vis = new bool[V] {0};
		long long int  ans = 0;
		Q.push({0, 0});

		while (!Q.empty()) {
			//pick out the edges with min weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if (vis[to]) {
				//discard the edge, and continue
				continue;
			}

			//otherwise take current edge
			ans += weight;
			vis[to] = 1;

			//add the new edges in the queue
			for (auto x : adj[to]) {
				if (vis[x.first] == 0) {
					Q.push({x.second, x.first});
				}
			}
		}

		return ans;
	}
};
int main()
{
	boost;
	int n, m;
	cin >> n >> m;
	Graph g(n);

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w);
	}

	cout << g.prim_mst();

	return 0;
}