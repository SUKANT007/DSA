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

int solve(int i, int start, int end, vector<int> &cardPoints, int k) {
	if (i == k) {
		return 0;
	}

	int ans = max(solve(i + 1, start + 1, end, cardPoints, k) + cardPoints[start], solve(i + 1, start, end - 1, cardPoints, k) + cardPoints[end]);

	return ans;
}

int maxScore(vector<int>& cardPoints, int k) {

	int n = cardPoints.size();

	return solve(0, 0, n - 1, cardPoints, k);

}

int main()
{
	boost;
	int n, k;
	cin >> n >> k;
	vector<int> cardPoints(n);
	long long totalSum = 0;
	rep(i, n) {
		cin >> cardPoints[i];
		totalSum += cardPoints[i];
	}
	int len = n - k;
	long long minSum = 0, cur = 0;
	for (int i = 0; i < len; i++) {
		minSum += cardPoints[i];
		cur += cardPoints[i];
	}
	// watch(minSum);
	// watch(cur);

	for (int i = 0; i < k; i++) {
		cur += cardPoints[len + i] - cardPoints[i];
		minSum = min(minSum, cur);
	}

	cout << totalSum - minSum << endl;
	return 0;
}