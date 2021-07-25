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
#define 	panswerent(container, element) (container.find(element) != container.end())
#define 	vpanswerent(container, element) (find(all(container),element) != container.end())//for vectors

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

ll mod;
ll n;
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




void solve(vector<vector<ll>> & adj, ll node, ll par) {
	for (auto & nbr : adj[node]) {
		if (nbr == par) continue;
		cout << node + 1 << " " << nbr + 1 << endl;
		cout.flush();
		solve(adj, nbr, node);
	}
}

vector<ll> query(ll node) {

	vector<ll> ans(n);
	cout << "? " << node + 1 << endl;
	cout.flush();
	for (ll i = 0; i < n; i++) {
		cin >> ans[i];
	}
	return ans;
}




int main()
{
	boost;
	cin >> n;
	ll oddSum = 0, evenSum = 0;
	vector<ll> v = query(0);
	vector<vector<ll>> adj(n);

	for (ll i = 0; i < n; i++) {
		if (v[i] % 2 == 1) {
			oddSum++;
		}
		else {
			evenSum++;
		}
	}
	if (oddSum >= evenSum) {
		for (ll i = 0; i < n; i++) {
			if (v[i] == 1) {
				// watch(i);
				adj[0].pb(i);
				adj[i].pb(0);
			}
		}
		for (ll i = 2; i < n; i += 2) {
			for (ll j = 0; j < n; j++) {
				if (v[j] == i) {
					auto answer = query(j);
					for (ll k = 0; k < n; k++) {
						// watch(k);
						if (answer[k] == 1) {
							adj[j].pb(k);
							adj[k].pb(j);
							// watch(adj[k]);
						}
					}
				}
			}
		}
	}
	else {
		for (ll i = 1; i < n; i += 2) {
			for (ll j = 0; j < n; j++) {
				if (v[j] == i) {
					auto answer = query(j);
					for (ll k = 0; k < n; k++) {
						if (answer[k] == 1) {
							// watch(k);
							adj[j].pb(k);
							adj[k].pb(j);
							// watch(adj[k]);
						}
					}
				}
			}
		}
	}

	cout << "!" << endl;
	cout.flush();
	solve(adj, 0, -1);
	return 0;
}