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


void buildTree(int *a, int s, int e, vector<vector<int>> &tree, int index) {

	if (s == e) {
		for (int i = 0; i < 3; i++) {
			tree[index].push_back(a[s]);
		}
		return ;
	}

	//Recursive case
	//post - order traversal
	int mid = (s + e) / 2;

	buildTree(a, s, mid, tree, 2 * index);
	buildTree(a, mid + 1, e, tree, 2 * index + 1);

	tree[index].push_back(min(tree[2 * index][0], tree[2 * index + 1][0]));
	tree[index].push_back(max(tree[2 * index][1], tree[2 * index + 1][1]));
	tree[index].push_back(tree[2 * index][2] + tree[2 * index + 1][2]);

	return;

}


vector<int> query (vector<vector<int>> &tree , int ss , int se, int qs, int qe, int index) {

	//Complete Overlap is in terms of tree node in query node

	if (ss >= qs && se <= qe) {
		return tree[index];
	}

	// No overlap

	if (qe < ss ||  qs > se) {
		return {INT_MAX, INT_MIN, 0};
	}


	// Partial Overlap

	int mid = (ss + se ) / 2;
	vector<int> left = query(tree, ss, mid, qs, qe, 2 * index);
	vector<int> right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

	vector<int> ans(3);

	ans[0] = min(left[0], right[0]);
	ans[1] = max(left[1], right[1]);
	ans[2] = left[2] + right[2];

	return ans;
}

void updateNode(vector<vector<int>> &tree, int ss, int se , int i, int increment, int index) {
	// Case where the I is out of bounds
	if (i > se || i < ss)
		return;

	//leaf index
	if (ss == se) {
		for (int i = 0; i < 3; i++) {
			tree[index][i]  += increment;
		}
		return;
	}

	//otherwise

	int mid = (ss + se) / 2;
	updateNode(tree, ss, mid, i, increment, 2 * index);
	updateNode(tree, mid + 1, se, i, increment, 2 * index + 1);

	tree[index][0] = min(tree[2 * index][0], tree[2 * index + 1][0]);
	tree[index][1] = max(tree[2 * index][1], tree[2 * index + 1][1]);
	tree[index][2] = tree[2 * index][2] + tree[2 * index + 1][2];


}

void updateRange(vector<vector<int>> &tree, int ss, int se , int l, int r, int increment, int index) {

	// Out of bounds

	if (l > se || r < ss) return;

	//Leaf Node

	if (ss == se) {
		for (int i = 0; i < 3; i++) {
			tree[index][i]  += increment;
		}
		return;
	}

	//recursive case

	int mid = (ss + se) / 2;
	updateRange(tree,  ss,  mid , l, r, increment, 2 * index);
	updateRange(tree,  mid + 1,  se , l, r, increment, 2 * index + 1);

	tree[index][0] = min(tree[2 * index][0], tree[2 * index + 1][0]);
	tree[index][1] = max(tree[2 * index][1], tree[2 * index + 1][1]);
	tree[index][2] = tree[2 * index][2] + tree[2 * index + 1][2];


}

int main()
{
	boost;
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];

	vector<vector<int>>tree(4 * n + 1);

	buildTree(a, 0, n - 1, tree, 1);

	// updateNode(tree, 0, n - 1, 3, 10, 1);
	updateRange(tree, 0, n - 1, 3, 5, 10, 1);


	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		vector<int> ans =  query(tree, 0, n - 1, l, r, 1);
		rep(i, 3) cout << ans[i] << " ";
		cout << endl;
	}


	return 0;
}
















