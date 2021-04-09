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


struct MinHeapNode {
	char data;
	unsigned freq;
	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare {

	bool operator() (MinHeapNode* l , MinHeapNode* r) {
		return l->freq > r->freq;
	}
};

class Solution {

public:

	void getCodes(struct MinHeapNode* root, string str, vector<string> &res) {
		if (!root) return;

		//this is a leaf node
		if (root->data != '$') {
			res.push_back(str);
		}

		getCodes(root->left, str + "0", res);
		getCodes(root->right, str + "1", res);
	}

	vector<string> huffmanCodes(string S, vector<int> f, int N) {
		struct MinHeapNode *left, *right, *top;

		priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

		for (int i = 0; i < N; i++) {
			minHeap.push(new MinHeapNode(S[i], f[i]));
		}

		// until the size of heap is reduced to 1
		while (minHeap.size() != 1) {
			left = minHeap.top();
			minHeap.pop();
			right = minHeap.top();
			minHeap.pop();
			top = new MinHeapNode('$', left->freq + right->freq);
			top->left = left;
			top->right = right;

			minHeap.push(top);
		}

		vector<string> res;
		getCodes(minHeap.top(), "", res);

		return res;
	}

};

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		string S;
		cin >> S;
		int N = S.length();
		vector<int> f(N);
		rep(i, N) cin >> f[i];

		Solution ob;
		vector<string> ans = ob.huffmanCodes(S, f, N);

		for (auto i : ans)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}