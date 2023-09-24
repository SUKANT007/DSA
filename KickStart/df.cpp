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



// Before sub : check for out of bounds , long long , floating point exception(division by zero) ,indexes , 0 , 1

const int mod = 1e9 + 7;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size() , n = obstacleGrid[0].size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	dp[0][1] = 1;
	for (int i = 1 ; i <= m ; ++i)
		for (int j = 1 ; j <= n ; ++j)
			if (obstacleGrid[i - 1][j - 1] == 0)
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] );


	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[m][n] % mod;


}


int main()
{
	boost;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> obstacleGrid(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> obstacleGrid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << obstacleGrid[i][j] << " ";
		}
		cout << endl;
	}


	cout << uniquePathsWithObstacles(obstacleGrid);
	return 0;
}