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
long long invcnt = 0;

void merge(long long arr[], long start, long long mid, long long end, long long n) {

	long long temp[n];
	long long i = start, j = mid + 1;
	long long idx = start;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[idx] = arr[i];
			idx++;
			i++;
		}
		else {
			invcnt += (mid - i + 1);
			temp[idx] = arr[j];
			idx++;
			j++;
		}
	}

	while (i <= mid) {
		temp[idx] = arr[i];
		idx++;
		i++;
	}
	while (j <= end) {
		temp[idx] = arr[j];
		idx++;
		j++;
	}

	for (int k = start; k <= end; k++) {
		arr[k] = temp[k];
	}
}


void mergeSort(long long arr[], long long start, long long end, long long n) {

	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid, n);
		mergeSort(arr, mid + 1, end, n);
		merge(arr, start, mid, end, n);

	}

}


int main()
{
	boost;
	long long n;
	cin >> n;
	long long arr[n];
	rep(i, n) cin >> arr[i];
	mergeSort(arr, 0, n - 1, n);
	rep(i, n) cout << arr[i] << " ";
	cout << endl;
	cout << invcnt << endl;
	return 0;
}