
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

class Solution {
public:

	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
	int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

	void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int n, int m) {

		vis[i][j] = true;

		for (int k = 0; k < 8; k++) {
			int x = i + dx[k];
			int y = j + dy[k];
			if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '1')
				dfs(x, y, vis, grid, n, m);
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<bool>>vis(n, vector<bool>(m, false));
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1' && !vis[i][j]) {
					count++;
					dfs(i, j, vis, grid, n, m);
				}
			}
		}

		return count;
	}
};

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n,	vector<char>(m, '#'));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}

		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans << endl;
	}
	return 0;
}