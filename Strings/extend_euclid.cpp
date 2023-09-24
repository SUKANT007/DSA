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





struct triplet
{
	int x, y, gcd;

};



triplet extendEuclid(int a, int b) {
	if (b == 0) {
		return triplet{
x: 1, y: 0, gcd: a,
		};
	}


	triplet subAns = extendEuclid(b, a % b);

	triplet ans;

	ans.gcd = subAns.gcd;
	ans.x = subAns.y;
	ans.y = subAns.x - (a / b) * subAns.y;

	return ans;
}





int main()
{
	boost;

	int a, b;
	cin >> a >> b;

	triplet ans = extendEuclid(a, b);

	cout << "x: " << ans.x << " y: " << ans.y << " gcd: " << ans.gcd << endl;


// ax + by = gcd(a,b)

// property of gcd: gcd(a,b) = gcd(b,a%b)

// base case b = 0
// ax = a
// x = 1


// Note: gcd(x,0) = x


// x = y1
// y = x1 - (a/b)*y1



	return 0;
}