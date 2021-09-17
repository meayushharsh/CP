// Problem: C. Fools and Roads
// Contest: Codeforces - Codeforces Round #121 (Div. 1)
// URL: https://codeforces.com/contest/191/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=100000;
vector<int>adj[maxn+1];
int dp[maxn+1][17];
int tin[maxn+1];
int tout[maxn+1];
int timer;
void dfs(int s,int p){
	tin[s]=++timer;
	dp[s][0]=p;
	for(int i=1;i<17;i++)
	dp[s][i]=dp[dp[s][i-1]][i-1];
	for(int i=0;i<(int)adj[s].size();i++)
	if(adj[s][i]!=p)
	dfs(adj[s][i],s);
	tout[s]=++timer;
}
bool is_ancestor(int u,int v){
	if(!u || (tin[u]<=tin[v] && tout[u]>=tout[v]))
	return true;
	return false;
}
int lca(int u,int v){
	if(is_ancestor(u,v))
	return u;
	if(is_ancestor(v,u))
	return v;
	for(int i=16;i>=0;i--)
	if(!is_ancestor(dp[u][i],v))
	u=dp[u][i];
	return dp[u][0];
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n;
cin>>n;
for(int i=1;i<n;i++){
	int u,v;
	cin>>u>>v;
	adj[u].pb(v);
	adj[v].pb(u);
}
dfs(1,0);// 1 as root of tree
int queries;
cin>>queries;
for(int i=1;i<=queries;i++){
	int u,v;
	cin>>u>>v;
	cout<<lca(u,v)<<endl;
}
return 0;
}
