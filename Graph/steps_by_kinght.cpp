
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

	int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1};
	int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
	int ans = INT_MAX;
	int vis[1005][1005];

	// int bfs(int srcx, int srcy, int destx, int desty, int N) {


	// 	for (int i = 0; i <= N; i++) {
	// 		for (int j = 0; j <= N; j++) {
	// 			vis[i][j] = INT_MAX;
	// 		}
	// 	}

	// 	queue<pair<int, int>>q;
	// 	q.push({srcx, srcy});
	// 	vis[srcx][srcy] = 0;

	// 	while (!q.empty()) {
	// 		int i = q.front().first;
	// 		int j = q.front().second;
	// 		q.pop();
	// 		for (int k = 0; k < 8; k++) {
	// 			int x = i + dx[k];
	// 			int y = j + dy[k];

	// 			if (x >= 1 && j >= 1 && x <= N && y <= N && vis[x][y] == INT_MAX) {
	// 				vis[x][y] = vis[i][j] + 1;
	// 				q.push({x, y});
	// 			}
	// 		}
	// 	}

	// 	// for (int i = 1; i <= N; i++) {
	// 	// 	for (int j = 1; j <= N; j++) {
	// 	// 		cout << vis[i][j] << " ";
	// 	// 	}
	// 	// 	cout << endl;
	// 	// }
	// 	return vis[destx][desty];
	// }
	void solve(int i, int j, int destx, int desty, int N, int count) {
		if (i < 1 || j < 1 || i > N || j > N || vis[i][j] == 1) {
			return;
		}
		cout << i << " " << j << endl;


		if (i == destx && j == desty) {
			ans = min(ans, count);
			return;
		}
		vis[i][j] = 1;
		for (int k = 0; k < 8; k++) {
			solve(i + dx[k], j + dy[k], destx, desty, N, count + 1);
		}
		vis[i][j] = 0;
		//return;
	}

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N) {
		//vector<vector<int>>vis(N, vector<int> (N + 1, 0));
		memset(vis, 0, sizeof(vis));
		if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1] ) return 0;
		//	solve(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], N, 0);

		return ans;
		//return bfs(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], N);
	}
};

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans << endl;
	}
	return 0;
}