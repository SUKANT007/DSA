#include<bits/stdc++.h>
using namespace std;
#define     boost        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define     int          long long int
#define     INF          1001001001
#define     PI           3.1415926535897932384626
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     rep(i,k,n)     for (int i = k; i <= n; ++i) 
#define     REPR(i,k,n)  for (int i = k; i >= n; --i)
#define     watch(x)     cout << (#x) << " is " << (x) << endl
#define     binary(n)    cout<<bitset<32>(n)<<"\n"    
#define     tr(container,it) for(auto it=container.begin();it!=container.end();it++)
#define     present(container, element) (container.find(element) != container.end())
#define     vpresent(container, element) (find(all(container),element) != container.end())//for vectors

int mod;
int power(int a, int b) //a is base, b is exponent
        {
            if(b==0)
                return 1;
            if(b%2 == 1)
                return (power(a,b-1)*a)%mod;
            int q = power(a,b/2);
            return (q*q)%mod;
        }


 stack<int> s;
 int vis[100];
 vector<int> adj[100];
 vector<int> revadj[100];
vector< pair<int,int > > edges;

 void dfs(int node)
 {
 	vis[node] = 1; 
 	
 		for(int i=0;i<adj[node].size();i++)
 		{
 			if(!vis[adj[node][i]])
 				dfs(adj[node][i]);
 		}
 	
 	s.push(node);

 }

 void dfs2(int node)
 {
 	vis[node] = 1;

 	for(int i=0;i<revadj[node].size();i++)
 		{
 			if(!vis[revadj[node][i]])
 			{	
 				dfs2(revadj[node][i]);	
 			}
 		}
 }


 
void reverse()
{
	for(auto i : edges)
	{
		revadj[i.second].pb(i.first);
	}
}


    int32_t main()
    {
    	
    	boost;
    	int n,m;
    	cin>>n>>m;
    	while(m--)
    	{
    		int u,v;
    		cin>>u>>v;
    		adj[u].pb(v);
    		edges.pb({u,v});

    	}

    	for(int i=1;i<=n;i++)
    	{
    		if(!vis[i])
    			dfs(i);
    	}

    	reverse();
    	mem(vis,0);
    	while(!s.empty())
    	{
    		int node = s.top();
    		s.pop();
    		
    		if(!vis[node])
    		{
    			dfs2(node);
    		}

    	}
  
    	return 0;
    }
