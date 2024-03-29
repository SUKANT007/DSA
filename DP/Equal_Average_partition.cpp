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


bool subset_sum(int idx, int target, int cur_size, vector<int> &set1, vector<vector<vector<bool>>> &dp, vector<int> &nums) {
	if (cur_size == 0) return (target == 0);

	if (idx == nums.size()) {
		return false;
	}

	if (dp[idx][target][cur_size]  == false ) return false;

	if (nums[idx] <= target) {
		set1.push_back(nums[idx]);
		if (subset_sum(idx + 1, target - nums[idx], cur_size - 1, set1, dp, nums)) {
			return true;
		}
		set1.pop_back();
	}

	if (subset_sum(idx + 1, target, cur_size, set1, dp, nums)) {
		return true;
	}
	return dp[idx][target][cur_size] = false;
}


vector<vector<int> > avgset(vector<int> &nums) {

	int n = nums.size();
	int sum = 0;
	for (auto num : nums) sum += num;

	vector<vector<vector<bool>>> dp (n, vector<vector<bool>>(sum + 1, vector<bool>(n, true)));

	sort(nums.begin(), nums.end());

	vector<vector<int>> res;

	for (int n1 = 1; n1 <= n / 2; n1++) {

		if ((sum * n1) % n == 0) {
			int  sum1 = (sum * n1) / n;
			vector<int> set1;
			if (subset_sum(0, sum1, n1, set1, dp, nums)) {

				vector<int> set2;
				int p1 = 0, p2 = 0;

				while (p1 < n1 || p2 < n) {
					if (p1 < n1 && set1[p1] == nums[p2]) {
						p1++;
						p2++;
					}
					else {
						set2.push_back(nums[p2]);
						p2++;
					}
				}
				res.push_back(set1);
				res.push_back(set2);

				return res;
			}
		}
	}
	return res;
}

int main()
{
	boost;
	int n;
	cin >> n;
	vector<int> A(n);
	rep(i, n) cin >> A[i];
	vector<vector<int>> sol = avgset(A);

	for (auto Set : sol) {
		for (auto it : Set) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}