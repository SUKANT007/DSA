#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // remove for interactive

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

#define 	InF 1e18
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


int maximumCoins(int arr1[], int arr2[], int n, int m) {
	int firstSum = 0, secondSum = 0, ans = 0, i, j;
	for (i = 0, j = 0; i < n && j < m;) {
		if (arr1[i] < arr2[j]) {
			firstSum += arr1[i];
			i++;
		}
		else if (arr1[i] > arr2[j]) {
			secondSum += arr2[j];
			j++;
		}
		else {
			firstSum += arr1[i];
			while (i + 1 < n && arr1[i + 1] == arr2[j]) {
				i++;
				firstSum += arr1[i];
			}
			secondSum += arr2[j];
			while (j + 1 < m && arr2[j + 1] == arr1[i]) {
				j++;
				secondSum += arr2[j];
			}
			i++;
			j++;
			if (firstSum > secondSum)
				ans += firstSum;
			else
				ans += secondSum;
			firstSum = secondSum = 0;
		}
	}
	while (j < m) {
		secondSum += arr2[j];
		j++;
	}
	while (i < n) {
		firstSum += arr1[i];
		i++;
	}

	// for (j; j < m; j++)
	// 	secondSum += b[j];
	// for (i; i < n; i++)
	// 	firstSum += a[i];
	if (firstSum > secondSum)
		ans += firstSum;
	else
		ans += secondSum;
	return ans;
}

int main()
{
	boost;

	return 0;
}