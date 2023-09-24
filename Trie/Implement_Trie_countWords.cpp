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

class TrieNode {
public:
	TrieNode *childNode[26];
	int isEnd;
	int count;
	TrieNode() {
		for (int i = 0; i < 26; i++) childNode[i] = NULL;
		isEnd = 0;
		count = 0;
	}
};
class Trie {

public:

	Trie() {
		root = new TrieNode();
	}

	void insert(string &word) {
		TrieNode *cur = root;
		for (int i = 0; i < word.length(); i++) {
			if (cur->childNode[word[i] - 'a'] == NULL) {
				cur->childNode[word[i] - 'a'] = new TrieNode();
			}
			cur->count += 1;
			cur = cur->childNode[word[i] - 'a'];
		}
		cur->count += 1;
		cur->isEnd += 1;
	}

	int countWordsEqualTo(string &word) {
		TrieNode *cur = root;
		for (int i = 0; i < word.length(); i++) {
			if (cur->childNode[word[i] - 'a'] == NULL) return 0;
			cur = cur->childNode[word[i] - 'a'];
		}

		return (cur->isEnd) ? cur->count : 0;
	}

	int countWordsStartingWith(string &word) {
		TrieNode *cur = root;
		for (int i = 0; i < word.length(); i++) {
			if (cur->childNode[word[i] - 'a'] == NULL) return 0;
			cur = cur->childNode[word[i] - 'a'];
		}

		return cur->count;
	}

	void erase(string &word) {
		TrieNode *cur = root;
		for (int i = 0; i < word.length(); i++) {
			cur->count -= 1;
			cur = cur->childNode[word[i] - 'a'];
		}
		cur->count -= 1;
		cur->isEnd -= 1;
	}

	~Trie() {                        //destructor: to free memory
		clear(root);
	}

	void clear(TrieNode* root)
	{
		for (int i = 0; i < 26; i++)
		{
			if (root->childNode[i] != NULL)
			{
				clear(root->childNode[i]);
			}
		}

		delete root;
	}

private:
	TrieNode *root;


};


int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Trie *newTrie = new Trie();

		for (int i = 0; i < n; i++) {
			int type;
			string word;
			cin >> type >> word;

			if (type == 1) {
				newTrie->insert(word);
			}
			else if (type == 2) {
				cout << newTrie->countWordsEqualTo(word) << endl;
			}
			else if (type == 3) {

				cout << newTrie->countWordsStartingWith(word) << endl;
			}
			else if (type == 4) {
				newTrie->erase(word);
			}
		}
	}
	return 0;
}