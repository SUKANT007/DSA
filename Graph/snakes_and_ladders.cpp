
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
	map<T, list<T> > l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	int bfs(T src , T dest) {
		map<T, int> dist;
		queue<T>q;
		map<T, T> parent;

		for (auto it : l) {
			T node = it.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;
		parent[src] = src;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (auto nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					dist[nbr] = dist[node] + 1;
					q.push(nbr);
					parent[nbr] = node;
				}
			}
		}

		T temp = dest;
		while (temp != src) {
			cout << temp << " ";
			temp = parent[temp];
		}
		cout << src << endl;
		return dist[dest];
	}
};

int main()
{

	boost;
	Graph<int> g;

	int board[50] = {0};
	board[2]  = 13;
	board[5]  = 2;
	board[9]  = 18;
	board[18]  = 1;
	board[17]  = -13;
	board[20]  = -14;
	board[25]  = 10;
	board[32] = -2;
	board[34] = -22;

	for (int i = 0; i <= 36; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int j = i + dice;
			j += board[j];
			g.addEdge(i, j);
		}
	}
	g.addEdge(36, 36);
	cout << g.bfs(0, 36);
	return 0;
}