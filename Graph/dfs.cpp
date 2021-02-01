
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
template <typename T>
class Graph {
	map<T, list<T>> l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfs_helper(T node, map<T, bool> &visited) {
		cout << node << " ";
		visited[node] = true;
		for (auto nbr : l[node]) {
			if (!visited[nbr])
				dfs_helper(nbr, visited);
		}
	}
	void dfs(T src) {
		map<T, bool> visited;
		for (auto nodes : l) {
			T node = nodes.first;
			visited[node] = false;
		}

		//for connected components part
		int count = 0 ;
		for (auto nodes : l) {
			T node = nodes.first;
			if (!visited[node]) {
				visited[node] = true;
				cout << "component " << count << " --->";
				dfs_helper(node, visited);
				count++;
			}
		}

		//dfs_helper(src, visited);
	}
};

int main()
{
	boost;
	Graph<int> g;
	// g.addEdge(1, 2);
	// g.addEdge(0, 1);
	// g.addEdge(2, 3);
	// g.addEdge(0, 3);
	// g.addEdge(3, 4);
	// g.addEdge(4, 5);


	// for connected components
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(8, 8);
	g.dfs(0);
	return 0;
}