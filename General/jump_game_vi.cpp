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


int maxResult(vector<int>& nums, int k)
{
    auto NumberOfElements = nums.size();
    /*
    *   MaxSumStartingAt[i] represents the maximum sum that we can obtain if we started from the element at index i.
    */
    vector<int> MaxSumStartingAt(NumberOfElements);
    /*
    *   At each step, to compute MaxSumStartingAt[i], we need to know the maximum value among
    *   MaxSumStartingAt[i+1],...,MaxSumStartingAt[i+k]. Using a priority queue will speed up the search.
    *   The element stored in the queue is a pair<int,int> where the first element represent the value of MaxSumStartingAt[i]
    *   and the second one is the index where i.
    *   Example: {10, 3} means MaxSumStartinAt[3]=10;
    */
    priority_queue<pair<int, int>> q;

    /*
    *   The last element of MaxSumStartingAt is nothing short of the last element of nums itself.
    */
    MaxSumStartingAt.back() = nums.back();

    q.emplace(
        make_pair(nums.back(), NumberOfElements - 1)
    );

    /*
    *   Moving backward, we fill MaxSumStartingAt up.
    */
    for (int i = NumberOfElements - 2; i >= 0; --i)
    {

        /*
        *   We pick the max sum currently in MaxSumStartingAt.
        *   However, if the MaxSumStartingAt value is not reachable from index i, we drop it and pick another one.
        *
        *   Example:
        *       MaxSumStartingAt:   [   ,   ,  7 , 0 , 10 ]
        *       q = [{10, 4}, {7, 2}, {0, 3}]
        *      i=1 with  k=2
        *       MaxSumStartingAt[1] = nums[1]+MAX(MaxSumStartingAt[2],MaxSumStartingAt[3])
        *           -> maxSum={10, 5} => MaxSumStartingAt[4]=10 (NO NEEDED, GO TO THE NEXT ONE, q.pop())
        *           -> maxSum={7, 2} => MaxSumStartingAt[2]=7 (WE HAVE FOUND THE MAX VALUE)
        *       Consequently:
        *           MaxSumStartingAt[1] = nums[1]+MaxSumStartingAt[2]
        *           MaxSumStartingAt[1] = nums[1]+maxSum.first;
        */
        auto maxSum = q.top();
        /*
        *   As explained above, we pop the values of MaxSumStartingAt stored in the priority queue when
        *   they are too far from the index i.
        */
        auto maxSumIndex = maxSum.second;
        while (maxSumIndex > i + k)
        {
            q.pop();
            maxSum = q.top();
            maxSumIndex = maxSum.second;
        }

        /*
        *   maxSumValue = MAX(MaxSumStartingAt[i+1], ... , MaxSumStartingAt[i+k]);
        */
        auto maxSumValue = maxSum.first;

        /*
        *   Once we have found MAX(MaxSumStartingAt[i+1], ... , MaxSumStartingAt[i+k]), we use it to compute MaxSumStartingAt[i]
        *   MaxSumStartingAt[i] = nums[i]+MAX(MaxSumStartingAt[i+1], ... , MaxSumStartingAt[i+k])
        */
        MaxSumStartingAt[i] = nums[i] + maxSumValue;

        /*
        *   Add to the queue {MaxSumStartingAt[i], i}, which might be used later on to compute other MaxSumStartingAt[j]
        */
        q.emplace(
            make_pair(MaxSumStartingAt[i], i)
        );
    }
    return MaxSumStartingAt[0];
}

int main()
{
    boost;
    return 0;
}