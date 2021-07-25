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


int dp[205][205];


bool solve(int i, int j, int idx, string s1, string s2, string s3) {


	if (i == s1.length() && j == s2.length() && idx == s3.length()) return true;


	if (dp[i][j] != -1) return dp[i][j];


	bool op1 = false, op2 = false;

	if (i < s1.length() && s1[i] == s3[idx]) {
		op1 = solve(i + 1, j, idx + 1, s1, s2, s3);
	}

	if (j < s2.length()  && s2[j] == s3[idx]) {
		op2 = solve(i, j + 1, idx + 1, s1, s2, s3);
	}

	return dp[i][j] = (op1 || op2);

}


bool isInterleave(string s1, string s2, string s3) {

	memset(dp, -1, sizeof(dp));

	return solve(0, 0, 0, s1, s2, s3);
}



bool isInterleave2(string s1, string s2, string s3) {

	if (s3.length() != s1.length() + s2.length())
		return false;

	bool table[s1.length() + 1][s2.length() + 1];

	for (int i = 0; i < s1.length() + 1; i++)
		for (int j = 0; j < s2.length() + 1; j++) {
			if (i == 0 && j == 0)
				table[i][j] = true;
			else if (i == 0)
				table[i][j] = ( table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			else if (j == 0)
				table[i][j] = ( table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			else
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1] ) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1] );
		}

	return table[s1.length()][s2.length()];
}



int main()
{
	boost;

	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;


	cout << isInterleave(s1, s2, s3);

	return 0;
}