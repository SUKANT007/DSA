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

int merge(vector<int> &nums, int low, int mid, int high) {
	int temp[nums.size()];
	int i = low, j = mid + 1;
	int idx = low;
	int invcnt = 0;



	while (i <= mid && j <= high) {
		if (nums[i] <= nums[j]) {
			temp[idx++] = nums[i++];
		}
		else {

			if (nums[i] > 2 * nums[j]) {

				invcnt += mid - i + 1;
			}
			watch(i);
			watch(j);

			cout << nums[i] << " " << nums[j] << endl;
			temp[idx++] = nums[j++];

		}
	}

	while (i <= mid) {
		temp[idx++] = nums[i++];
	}
	while (j <= high) {
		temp[idx++] = nums[j++];
	}

	for (int k = low; k <= high; k++) {
		nums[k] = temp[k];
	}

	return invcnt;
}

int mergeSort(vector<int> &nums, int low, int high) {
	if (low >= high) return 0;
	int mid = low + (high - low) / 2;
	int left = mergeSort(nums, low, mid);
	int right = mergeSort(nums, mid + 1, high);
	int cross =  merge(nums, low, mid, high);
	return left + right + cross;
}

int reversePairs(vector<int>& nums) {

	return mergeSort(nums, 0, nums.size() - 1);
}


int main()
{
	boost;

	int n;
	cin >> n;
	vector<int> nums(n);

	rep(i, n) cin >> nums[i];

	//cout << "reverse Pairs: " << reversePairs(nums) << endl;

	// rep(i, n) {
	// 	cout << nums[i] << " ";
	// }

	return 0;
}