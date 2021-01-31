
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
	int V;
	unordered_map<string, list<pair<string, int>>> l;
public:
	void addEdge(string x, string y, int wt, bool bidir) {
		l[x].push_back({y, wt});
		if (bidir)
			l[y].push_back({x, wt});
	}

	void printList() {
		for (auto p : l) {
			string src = p.first;
			list<pair<string, int>> nbrs = p.second;
			cout << "Src: " << src << " -> ";
			for (auto nbr : nbrs) {
				cout << nbr.first << " " << nbr.second << ", ";
			}
			cout << endl;
		}
	}
};
int main()
{
	boost;
	Graph g;
	g.addEdge("A", "B", 20, 1);
	g.addEdge("A", "C", 10, 1);
	g.addEdge("A", "D", 50, 0);
	g.addEdge("C", "D", 30, 1);
	g.addEdge("B", "D", 40, 1);

	g.printList();
	return 0;
}