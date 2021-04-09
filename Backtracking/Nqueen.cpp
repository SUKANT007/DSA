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


// Approach 1 it is taking extra O(n) for checking isSafe

//   int count = 0;
//     bool isSafe(int row,int col,int n, vector<vector<int>> &box){

//         int i,j;
//         //checking for same row
//         for(i=0;i<col;i++){
//             if(box[row][i]) return false;
//         }

//         // checking for upper diagonal

//         for(i=row,j=col;i>=0 && j>=0;i--,j--){
//             if(box[i][j]) return false;
//         }

//         //checking for lower diagonal

//         for(i=row,j=col;i<n && j>=0;i++,j--){
//             if(box[i][j]) return false;
//         }

//         return true;
//     }

//     void solve (int col,int n, vector<vector<int>> &box){
//         if(col == n){
//             count++;
//             return;
//         }

//         for(int i=0;i<n;i++){

//             if(isSafe(i,col,n,box)){

//                 box[i][col] = 1;
//                 solve(col+1,n,box);
//                 box[i][col] = 0;

//             }
//         }
//     }

//     int totalNQueens(int n) {

//         vector<vector<int>> box( n , vector<int> (n, 0));
//         solve(0,n,box);
//         return count;
//     }
// };

//Approach 2 efficient way  isSafe if O(1)

bitset<32> row, d1, d2;

void solve(int c, int n, int &count) {
	if (c == n) {
		count++;
		return;
	}

	for (int r = 0; r < n; r++) {
		if (!row[r] && !d1[r - c + n - 1] && !d2[r + c]) {
			row[r] = d1[r - c + n - 1] = d2[r + c] = 1;
			solve(c + 1, n, count);
			row[r] = d1[r - c + n - 1] = d2[r + c] = 0;

		}
	}
}


int main()
{
	boost;
	int n;
	cin >> n;
	int ans = 0;
	solve(0, n, ans);
	cout << ans << endl;
	return 0;
}