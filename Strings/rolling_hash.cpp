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

long long compute_hash(string const& s) {
	const int p = 31;
	const int m = 1e9 + 9;
	long long hash_value = 0;
	long long p_pow = 1;
	for (char c : s) {
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}


vector<vector<int>> group_identical_strings(vector<string> const& s) {
	int n = s.size();
	vector<pair<long long, int>> hashes(n);
	for (int i = 0; i < n; i++)
		hashes[i] = {compute_hash(s[i]), i};

	sort(hashes.begin(), hashes.end());

	vector<vector<int>> groups;
	for (int i = 0; i < n; i++) {
		if (i == 0 || hashes[i].first != hashes[i - 1].first)
			groups.emplace_back();
		groups.back().push_back(hashes[i].second);
	}
	return groups;
}

int main()
{
	boost;
	int n;
	cin >> n;
	vector<string> s;

	rep(i, n) {
		string a;
		cin >> a;
		s.push_back(a);
	}

	vector<vector<int>> groups = group_identical_strings(s);

	for (auto group : groups) {

		for (auto str : group) {
			cout << str << endl;
		}

		cout << "---------" << endl;

	}


	return 0;
}