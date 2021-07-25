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


struct Node {
	int data;
	struct Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

void printList(Node* head) {

	Node *ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}

	cout << endl;
}

Node* helper(Node* cur, Node *prev) {

	if (cur == NULL) return prev;

	Node *ahead = cur->next;
	cur->next = prev;

	return helper(ahead, cur);

}

Node* addOne(Node *head)
{
	if (head == NULL) return head;
	head = helper(head, NULL);

	//cout << head->data << endl;

	Node *ptr = head;
	int carry;

	if (ptr->data + 1 == 10) {
		carry = 1;
		ptr->data += 1;
		ptr->data %= 10;

	}
	else {
		carry = 0;
		ptr->data += 1;
	}
	//cout << ptr->data << endl;

	// Node *temp = ptr;
	// while (temp != NULL) {
	// 	cout << temp->data << " ";
	// 	temp = temp->next;
	// }

	// cout << endl;


	while (carry) {
		if (ptr->next == NULL) {
			Node *newNode = new Node(0);
			ptr->next = newNode;
		}
		ptr = ptr->next;
		(ptr->data == 9) ? carry = 1 : carry = 0;
		ptr->data += 1;
		ptr->data %= 10;
	}

	head = helper(head, NULL);

	return head;
}

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		Node *head = new Node(s[0] - '0');
		Node *tail = head;

		for (int i = 1; i < s.size(); i++) {
			tail->next = new Node(s[i] - '0');
			tail = tail->next;
		}

		head = addOne(head);
		printList(head);
	}
	return 0;
}