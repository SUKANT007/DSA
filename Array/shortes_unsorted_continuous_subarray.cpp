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


vector<int> subUnsort(vector<int> &A) {
	int n = A.size();
	if (n == 0) return { -1};
	int start = 0;
	int end = n - 1;
	while (start < n - 1 && A[start] <= A[start + 1]) {
		start++;
	}

	if (start == n - 1) return { -1};

	while (end > 0 && A[end - 1] <= A[end]) {
		end--;
	}

	int mini = INT_MAX;
	int maxi = INT_MIN;

	for (int i = start; i <= end; i++) {
		mini = min(mini, A[i]);
		maxi = max(maxi, A[i]);
	}

	// watch(start);
	// watch(end);
	// watch(mini);
	// watch(maxi);

	while (start > 0 && A[start - 1] > mini) {
		start--;
	}

	while (end < n - 1 && A[end + 1] < maxi) {
		end++;
	}

	return {start, end};
}


int main()
{
	boost;
	int n;
	cin >> n;
	vector<int> arr(n);
	rep(i, n) cin >> arr[i];
	vector<int> ans = subUnsort(arr);
	for (auto it  : ans) cout << it << " ";
	return 0;
}