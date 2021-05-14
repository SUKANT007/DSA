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

#define N 9

class Solution {
public:


	bool FindUnassignedLocation(int grid[N][N],
	                            int row, int col)
	{
		for (row = 0; row < N; row++)
			for (col = 0; col < N; col++)
				if (grid[row][col] == 0)
					return true;
		return false;
	}

	bool canPlace(int grid[N][N], int i, int j, int number) {
		for (int x = 0; x < N; x++) {
			if (grid[x][j] == number || grid[i][x] == number)
				return false;
		}

		int rn = sqrt(N);
		int sx = (i / rn) * rn;
		int sy = (j / rn) * rn;


		for (int x = sx; x < sx + rn; x++) {
			for (int y = sy; y < sy + rn; y++) {
				if (grid[x][y] == number)
					return false;
			}
		}

		return true;
	}

	bool solve(int grid[N][N], int i, int j)
	{
		//Base Case

		if (i == N || !FindUnassignedLocation(grid, i, j))
			return true;

		// change row case
		if (j == N) {
			solve(grid, i + 1, 0);
		}

		// Skip the prefilled Cells
		if (grid[i][j] != 0) {
			return solve(grid, i, j + 1);
		}

		for (int number = 1; number <= N; number++) {
			if (canPlace(grid, i, j, number)) {

				grid[i][j] = number;

				bool canWeSolve = solve(grid, i, j + 1);

				if (canWeSolve) return true;

				grid[i][j] = 0;
			}
		}

		return false;
	}

	bool SolveSudoku(int grid[N][N])
	{
		return solve(grid, 0, 0);
	}

	void printGrid (int grid[N][N])
	{
		// for (int i = 0; i < 9; i++) {
		// 	for (int j = 0; j < 9; j++) {
		// 		cout << grid[i][j] << " ";
		// 	}
		// }
	}
};

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		int grid[N][N];

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> grid[i][j];
			}
		}



		Solution ob;

		if (ob.SolveSudoku(grid))
			ob.printGrid(grid);
		else
			cout << "No Solution exists";

		cout << endl;



		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}



	}
	return 0;
}













