
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

template<typename T>

class Graph {
	map<T, list<pair<T, int>>> mp;
public:
	void addEdge(T x, T y, int wt, bool bidir = true) {
		mp[x].push_back({y, wt});
		if (bidir)
			mp[y].push_back({x, wt});
	}

	void Dijkstra(T src) {
		unordered_map<T, int> dist;
		for (auto it : mp) {
			dist[it.first] = INT_MAX;
		}
		dist[src] = 0;
		set<pair<int, T>>s;
		s.insert({0, src});

		while (!s.empty()) {
			auto p = *(s.begin());
			T node = p.second;
			int nodeDist = p.first;

			s.erase(s.begin());

			for (auto p : mp[node]) {
				auto nbr = p.first;
				int wt = p.second;

				if (dist[nbr] > nodeDist + wt) {
					auto it = s.find({dist[nbr], nbr});
					if (it != s.end()) {
						s.erase(it);
					}
					dist[nbr] = nodeDist + wt;
					s.insert({dist[nbr], nbr});

				}

			}


		}

		for (auto p : dist) {
			cout << p.first << " is located at a distance of " << p.second << endl;
		}
	}
};
int main()
{
	boost;
	Graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.Dijkstra(1);

	return 0;
}