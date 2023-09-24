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


int countSmallerThanEqualToMid(vector<int> &row, int mid) {

	int l = 0, h = row.size() - 1;

	while (l <= h) {
		int md = (l + h) >> 1;
		if (row[md] <= mid) {
			l = md + 1;
		}
		else {
			h = md - 1;
		}
	}

	return l;

}


int findMedian(vector<vector<int> > &A) {

	int low = 1,  high = 1e9;
	int n = A.size();
	int m = A[0].size();

	while (low <= high) {
		int mid = (low + high) >> 1;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += countSmallerThanEqualToMid(A[i], mid);
		}

		if (cnt <= (n * m) / 2) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return low;
}


// int countSmallerThanMid(vector<int> &row, int mid) {
// 	int l = 0, h = row.size() - 1;
// 	while (l <= h) {
// 		int md = (l + h) >> 1;
// 		if (row[md] <= mid) {
// 			l = md + 1;
// 		}
// 		else {
// 			h = md - 1;
// 		}
// 	}
// 	return l;
// }
// int findMedian(vector<vector<int> > &A) {
// 	int low = 1;
// 	int high = 1e9;
// 	int n = A.size();
// 	int m = A[0].size();
// 	while (low <= high) {
// 		int mid = (low + high) >> 1;
// 		int cnt = 0;
// 		for (int i = 0; i < n; i++) {
// 			cnt += countSmallerThanMid(A[i], mid);
// 		}

// 		if (cnt <= (n * m) / 2) low = mid + 1;
// 		else high = mid - 1;
// 	}
// 	return low;
// }

int main()
{
	boost;
	int n, m;
	cin >> n >> m;
	vector<vector<int>>matrix(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}


	cout << findMedian(matrix);


	return 0;
}