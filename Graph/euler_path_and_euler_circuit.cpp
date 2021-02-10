
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

#define N 100005
vector<int> adj[N];
vector<int> in(N);
vector<int> out(N);
vector<int> path ; // stores the Eulerian path
int edgecount;

bool graphHasEulerPath(int V) {
	int start_node = 0 , end_node = 0;
	for (int i = 0; i < V; i++) {
		if (out[i] - in[i] > 1 || in[i] - out[i] > 1) {
			return false;
		}
		else if (out[i] - in[i] == 1) start_node++;
		else if (in[i] - out[i] == 1) end_node++;
	}

	return (start_node == 0 && end_node == 0) || (start_node == 1 || end_node == 1);
}

int findStartNode(int V) {
	int start = 0;
	for (int i = 0; i < V; i++) {
		//Unique starting node
		if (out[i] - in[i] == 1) return i;
		//start at a node with an outgoing edge
		if (out[i] > 0) start = i; // ensures that we donot perform dfs on a singleton
	}

	return start;
}

// performs dfs to find Eulerian path
void dfs(int cur) {

	while (out[cur] != 0) {
		auto nbr = adj[cur].back();
		adj[cur].pop_back();
		out[cur]--;
		dfs(nbr);
	}

	path.push_back(cur);
}

// Returns a list of edgeCount + 1 node ids that give the Eulerian path or
// null if no path exists or the graph is disconnected.

vector<int> getEulerPath(int V) {
	if (!graphHasEulerPath(V)) return {};
	dfs(findStartNode(V));

	// Make sure all edges of the graph were traversed. It could be the
	// case that the graph is disconnected in which case return null.
	if (path.size() != edgecount + 1) return {};

	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	boost;
	int V, E;
	cin >> V >> E;
	edgecount = 0;
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		in[y]++;
		out[x]++;
		edgecount++;
	}

	// for (int i = 0; i < V; i++) {
	// 	cout << i << " " << in[i] << " " << out[i] << endl;
	// }

	vector<int> ans = getEulerPath(V);
	for (auto node : ans) cout << node << " ";
	return 0;
}