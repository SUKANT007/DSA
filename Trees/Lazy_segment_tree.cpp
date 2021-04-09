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

int lazy[10000] = {0};


void buildTree(int s, int e, int *a , int *tree, int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}

	int mid = (s + e) / 2;

	buildTree(s, mid, a, tree, 2 * index);
	buildTree(mid + 1, e, a, tree, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}


int query(int ss, int se, int qs, int qe, int *tree , int index) {

	//No Overlap
	if (qe < ss || qs > se) {
		return INT_MAX;
	}


	// Complete Overlap

	if (ss >= qs && se <= qe) {
		return tree[index];
	}

	//Partial Overlap

	int mid = (ss + se) / 2;

	int left = query(ss, mid, qs, qe, tree, 2 * index);
	int right = query(mid + 1, se, qs, qe, tree, 2 * index + 1);

	return min(left, right);

}


void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {


	//before going down resolve the lazy value if exists
	if (lazy[index] != 0 ) {

		tree[index] += lazy[index];

		//non leaf node
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}

		lazy[index] = 0; // clear the lazy value at current node
	}

	//Base Case

	//no overlap
	if (ss > r || l > se) return;


	//another case - Complete Overlap

	if (ss >= l && se <= r) {
		tree[index] += inc;

		//create a new lazy for children nodes

		if (ss != se) {
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}

		return;
	}

	// recursive case - Partial Overlap

	int mid = (ss + se) / 2;
	updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
	updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	//update the tree[idx]
	tree[index] = min(tree[2 * index] , tree[2 * index + 1]);
	return ;

}


int queryLazy(int *tree, int ss, int se, int qs, int qe, int index) {

	//before going down resolve the lazy value if exists
	if (lazy[index] != 0 ) {

		tree[index] += lazy[index];

		//non leaf node
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}

		lazy[index] = 0; // clear the lazy value at current node
	}


	//No Overlap

	if (ss > qe || se < qs) {
		return INT_MAX;
	}

	//Complete Overlap

	if (ss >= qs && se <= qe) {
		return tree[index];
	}

	//Partial Overlap

	int mid = (ss + se) / 2;
	int left = queryLazy(tree, ss, mid, qs, qe, 2 * index);
	int right = queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);

}
void updateNode(int s, int e, int i, int increment, int *tree, int index) {

}

int main()
{
	boost;
	int a[] = {1, 3, 2, -5, 6, 4};
	int  n = sizeof(a) / sizeof(a[0]);

	int *tree = new int[4 * n + 1];
	buildTree(0, n - 1, a, tree, 1);

	updateRangeLazy(tree, 0, n - 1, 0, 2, 10, 1);
	updateRangeLazy(tree, 0, n - 1, 0, 4, 10, 1);
	cout << "Q1 1-1 :  " << queryLazy(tree, 0, n - 1, 1, 1, 1) << endl;
	updateRangeLazy(tree, 0, n - 1, 3, 4, 10, 1);
	cout << "Q2 3-5 :  " << queryLazy(tree, 0, n - 1, 3, 5, 1) << endl;





	return 0;
}