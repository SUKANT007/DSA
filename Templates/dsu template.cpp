	#include<bits/stdc++.h>
	using namespace std;
	#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //to synchronize the input of cin and scanf
	#define ll long long 
	#define INF 1001001001
	#define PI 3.1415926535897932384626
	#define rep(i,n) for (int i = 0; i < n; ++i) 
	#define REP(i,k,n) for (int i = k; i <= n; ++i) 
	#define REPR(i,k,n) for (int i = k; i >= n; --i)
	#define tr(container,it) for(auto it=container.begin();it!=container.end();it++)
	#define present(container, element) (container.find(element) != container.end())
#define vpresent(container, element) (find(all(container),element) != container.end())//for vectors

void initialize(int arr[],long long size[],int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
		size[i]=1;
	}
}
int root(int arr[],int i)
{
	while(arr[i]!=i)
	{
		
		arr[i]= arr[ arr[i] ];
		i=arr[i];
	}
	return i;
}
bool find(int arr[],int a,int b)
{
	if( root(arr,a) != root(arr,b) )
		return false;
	else
		return true;
}
void Union(int arr[],long long size[],int a,int b)
{
	int root_a=root(arr,a);
	int root_b=root(arr,b);
	if( size[a] < size[b] )
	{
		arr[root_a] = arr[root_b];
		size[root_b]+=size[root_a];
	}
	else
	{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	boost;

    
	return 0;
}
