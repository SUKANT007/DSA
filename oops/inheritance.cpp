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

class grandparent//level 1 parent
{
public:
	void gp_property()
	{
		cout << "\nproperty earned by grand father-Kandhi Buchayya";
	}
};

class parent: protected grandparent //inheriting grandparent to parent:level 2
{
public:
	void p_property()
	{
		gp_property();
		cout << "\nproperty earned by parent-Kandhi Vijay";
	}
//now it conatins 2 methods
};

class child: public parent //level 3 child(powerful fellow)
{
public:
	void c_property()
	{
		cout << "\n property earned by child itself-Kandhi Trishaank";
	}
//It contains 3 methods now
//enjoys properties of parent+grandparent+its own
};

int main()
{

	child c;//containss the properties of 2 classes
	//c.gp_property();//derived from grand parent
	c.p_property();//derived from parent
	c.c_property();//its own method

	parent p;
	//p.gp_property();//derived from grand the parent
	p.p_property();//its own method

	return 0;

}

