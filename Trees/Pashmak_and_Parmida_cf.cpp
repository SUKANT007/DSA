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
ll BIT[10000001] = {0};
void update(int i, int inc, int n) {

	while (i <= n) {
		BIT[i] += inc;
		i += (i & (-i));
	}

}

ll query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += BIT[i];
		i -= (i & (-i));
	}

	return ans;
}
int main()
{
	boost;
	int n;
	cin >> n;
	ll a[n];
	for (int i = 1; i <= n; i++) cin >> a[i];

	map<ll, ll> freq;
	vector<ll> pre(n + 1, 0);
	vector<ll> suf(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		freq[a[i]]++;
		pre[i] = freq[a[i]];


	}

	freq.clear();

	for (int i = n  ; i >  0; i--) {
		freq[a[i]]++;
		suf[i] = freq[a[i]];


	}

	ll ans = 0;

	for (int i = n  ; i > 0; i--) {
		ans += query(pre[i] - 1);
		update(suf[i], 1, n );
	}

	cout << ans << endl;
	return 0;
}