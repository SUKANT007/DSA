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


class Solution {
public:
	int openLock(vector<string>& deadends, string target) {


		unordered_map<string, bool> mp;
		unordered_map<string, int> dist;
		unordered_map<string, bool> vis;


		for (auto str : deadends) {
			mp[str] = true;
		}

		bool flag = false;

		queue<string> q;
		string init = "0000";
		dist[init] = 0;

		if (!mp[init]) {
			q.push(init);
		}

		while (!q.empty()) {

			string src = q.front();
			vis[src] = true;
			if (src == target) {
				flag = true;
				break;
			}

			q.pop();

			for (int i = 0; i < 4; i++) {
				string temp1 = src;
				string temp2 = src;
				if (src[i] == '0') {
					temp1[i] = '1';
					temp2[i] = '9';
				}
				else if (src[i] == '9') {
					temp1[i] = '0';
					temp2[i] = '8';
				}
				else {
					temp1[i] = src[i] + 1;
					temp2[i] = src[i] - 1;
				}

				if (!mp[temp1] && !vis[temp1]) {
					q.push(temp1);
					dist[temp1] = dist[src] + 1;
				}

				if (!mp[temp2] && !vis[temp1]) {
					q.push(temp2);
					dist[temp2] = dist[src] + 1;
				}
			}



		}

		if (flag) {
			return dist[target];
		}
		else {

			return -1;
		}

	}
};


int main()
{
	boost;
	return 0;
}