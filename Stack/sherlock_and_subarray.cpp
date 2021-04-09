#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // remove for interactive

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

#define     INF 1e18
#define     endl "\n" // remove for interactive
#define     PI 3.1415926535897932384626
#define     all(x) x.begin(),x.end()
#define     mem(a,b) memset(a,b,sizeof(a))
#define     gcd(a,b) (__gcd((a),(b)))
#define     lcm(a,b) (((a)*(b))/gcd((a),(b)))
#define     pb push_back
#define     rep(i,n) for (int i = 0; i < n; ++i)
#define     REP(i,k,n) for (int i = k; i <= n; ++i)
#define     REPR(i,k,n) for (int i = k; i >= n; --i)
#define     watch(x) cout << (#x) << " is " << (x) << endl
#define     binary(n) cout<<bitset<32>(n)<<"\n"
#define     ps(x,y) fixed<<setprecision(y)<<x
#define     tr(container,it) for(auto it=container.begin();it!=container.end();it++)
#define     present(container, element) (container.find(element) != container.end())
#define     vpresent(container, element) (find(all(container),element) != container.end())//for vectors

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

//  Approach : Iterate over the maximum. Using a monotonic stack, you can find the position of the previous
// position that has an element ≥ this element and the next position that has an element ≥ this element,
//  and once you have this information, it's O(1) for each position, so the final complexity is O(n).

// eg : TestCase

// 2 2 3 4 3 1 4
// -------
//   -----
//     ---
//       -      (4*3) = 12  for index 3 element
//       -       (0,3) (0.4) (0.5) (1,3) (1,4) (1,5) (2,3) (2,4) (2,5) (3,3) (3,4) (3,5)
//       --
//       -----

// total : 23

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), prv(n, -1), nxt(n, n);
        for (auto &x : a)
            cin >> x;
        stack<int> s, t;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && a[s.top()] < a[i])
                s.pop();
            if (!s.empty())
                prv[i] = s.top();
            s.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!t.empty() && a[t.top()] < a[i])
                t.pop();
            if (!t.empty())
                nxt[i] = t.top();
            t.push(i);
        }
        int64_t ans = 0;

// rep(i, n) cout << prv[i] << " ";
// cout << endl;
// rep(i, n) cout << nxt[i] << " ";
// cout << endl;

        for (int i = 0; i < n; ++i) {
//  cout << (i - prv[i]) * 1LL * (nxt[i] - i) << " ";
            ans += (i - prv[i]) * 1LL * (nxt[i] - i);

        }

        cout << ans << '\n';
    }
    return 0;
}