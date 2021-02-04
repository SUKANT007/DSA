
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

int Find(int i, int parent[]) {
	if (parent[i] == i) {
		return parent[i];
	}
	else {
		return parent[i] = Find(parent[i], parent); // Path compression optimisation
	}
}


void Union(int i, int j, int parent[], int rank[]) {
	int s1 = Find(i, parent);
	int s2 = Find(j, parent);

	if (s1 != s2) {

		if (rank[s1] < rank[s2]) {
			parent[s1] = s2;
			rank[s2] += rank[s1]; // Union by rank optimisation
		}
		else {
			parent[s2] = s1;
			rank[s1] += rank[s2];
		}
	}
}

bool contains_cycle(vector<pair<int, int>> edgelist , int V) {
	int *parent = new int[V];
	int *rank = new int[V];

	for (int i = 0; i < V; i++) {
		parent[i] = i;
		rank[i] = 1;
	}

	for (auto edge : edgelist) {
		int u = edge.first;
		int v = edge.second;

		int s1 = Find(u, parent);
		int s2 = Find(v, parent);

		if (s1 != s2 ) {
			Union(s1, s2, parent, rank);
		}
		else {
			return true;
		}
	}
	delete [] parent;
	delete [] rank;

	return false;
}

int main()
{
	boost;
	int V, E;
	cin >> V >> E;
	vector<pair<int, int>>edgelist;
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		edgelist.push_back({u, v});
	}

	bool flag = contains_cycle(edgelist, V);
	if (flag) {
		cout << "Cycle found";
	}
	else {
		cout << "Cycle Not found";
	}
	return 0;
}