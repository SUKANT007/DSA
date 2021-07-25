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


ll mod = 1e9 + 7;

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int>mp;
		int a[n];
		int b[n];
		rep(i, n) {
			cin >> a[i];
			a[i]--;
		}
		rep(i, n) {
			cin >> b[i];
			b[i]--;
		}

		for (int i = 0; i < n; i++) {
			mp[a[i]] = b[i];
		}

		ll ans = 1;

		vector<bool>vis(n);

		for (int num = 0; num < n; num++) {

			if (vis[num]) continue;

			vis[num] = true;
			//watch(num);
			int idx = num;
			while (mp[idx] != num) {
				idx = mp[idx];
				//watch(idx);
				vis[idx] = true;
				//vis[a[idx]] = true;

			}

			ans = (ans * 2) % mod;

		}

		cout << ans << endl;

	}
	return 0;
}