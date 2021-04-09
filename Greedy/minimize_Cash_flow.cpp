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

bool cmp( const pair<string, int> &p1 , const pair<string, int> &p2) {
	return p1.second < p2.second;
}

class customcmp {
public:
	bool operator() (const pair<string, int> &p1 , const pair<string, int> &p2 ) {
		return p1.second < p2.second;
	}
};

int main()
{
	boost;
	int no_of_transactions, friends;
	cin >> no_of_transactions >> friends;

	map<string, int> net;

	string x, y;
	int amount;

	for (int i = 0; i < no_of_transactions; i++) {
		cin >> x >> y >> amount;

		if (net.count(x) == 0) net[x] = 0;
		if (net.count(y) == 0) net[y] = 0;

		net[x] -= amount;
		net[y] += amount;
	}

	// multiset<pair<string, int>, customcmp> mp;
	multiset < pair<string, int> , decltype(cmp)* > mp{cmp};

	for (auto p : net) {
		if (p.second != 0) {
			mp.insert({p.first, p.second});
		}
	}

	int cnt = 0;

	while (mp.size() > 0) {
		auto low = mp.begin();
		auto high = prev(mp.end());

		string debit_person = low->first;
		int debit = low->second;

		string credit_person  = high->first;
		int credit = high->second;

		mp.erase(low);
		mp.erase(high);

		int settlement = min(-debit, credit);

		debit += settlement;
		credit -= settlement;

		cout << debit_person << " will pay " << settlement << " to " << credit_person << endl;

		if (debit != 0 ) {
			mp.insert({debit_person, debit});
		}

		if (credit != 0) {
			mp.insert({credit_person, credit});
		}

		cnt++;
	}

	cout << cnt << endl;
	return 0;
}