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


int base = 31;

vector<long long> powers;


void preComputePowers(int n) {
	powers.resize(n);

	powers[0] = 1;

	for (int i = 1; i < n; i++) {
		powers[i] = (powers[i - 1] * base) % mod;
	}
}

vector<long long> findHash(string &s) {
	int n = (int)s.length();
	vector<long long> hash(n + 1, 0);

	for (int i = 0; i < n; i++) {
		hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * powers[i]) % mod;
	}

	return hash;
}

vector<int> rabin_karp_findOccurences(string &pattern, string &text) {
	vector<int> occurences;

	long long h_pattern = 0;
	int patternLen = (int)pattern.length();
	int textLen = (int)text.length();

	preComputePowers(max(patternLen, textLen));

	for (int i = 0; i < patternLen; i++) {
		h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * powers[i]) % mod;
	}

	vector<long long> h_text = findHash(text);

	for (int i = 0; i < (i + patternLen - 1) < textLen; i++) {
		long long substringHash = (h_text[i + patternLen] + mod - h_text[i]) % mod;

		if (substringHash == ((h_pattern * powers[i]) % mod) ) {
			occurences.push_back(i);
		}
	}

	return occurences;
}



int main()
{
	boost;
	string text, pattern;

	// getline(cin, text);
	// getline(cin, pattern);

	//cin >> text >> pattern;

	text = "i am there for you, i can go on and on";
	pattern = "o";

	cout << text << endl;
	cout << pattern << endl;

	mod = 1e9 + 7;

	vector<int> occurences = rabin_karp_findOccurences(pattern, text);

	for (auto &occurence : occurences) {
		cout << occurence << " ";
	}

	cout << endl;

	return 0;
}