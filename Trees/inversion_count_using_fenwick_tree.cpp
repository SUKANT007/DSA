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

void update(int i, ll inc, ll BIT[], int n) {

	while (i <= n) {
		BIT[i] += inc;
		i += (i & (-i));
	}
}

ll query(int i, ll BIT[]) {

	ll ans = 0;
	while (i > 0) {
		ans += BIT[i];
		i -= (i & (-i));
	}

	return ans;
}

void convert(ll arr[], int n) {
	int temp[n];
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}
	sort(temp, temp + n);
	for (int i = 0; i < n; i++) {
		arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
	}
}
int main()
{
	boost;
	int t;
	cin >> t;
	//watch(t);
	while (t--) {
		string s;
		getline(cin, s);
		int n;
		cin >> n;
		ll a[n + 1];
		//watch(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// rep(i, n) {
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		convert(a, n);
		ll BIT[n + 1];
		for (int i = 0; i <= n; i++) {
			BIT[i] = 0;
		}
		ll invcount = 0;

		for (int i = n - 1; i >= 0; i--) {
			invcount += query(a[i] - 1, BIT);
			update(a[i], 1, BIT, n);
		}

		cout << invcount << endl;

	}
	return 0;
}