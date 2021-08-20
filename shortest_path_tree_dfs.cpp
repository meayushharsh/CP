#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=100000;
vector<int>adj[maxn+1];
bool mark[maxn+1];
vector<int>path;
void initialize(int n){
	path.clear();
	for(int i=0;i<=n;i++){
		mark[i]=0;
		adj[i].clear();
	}
}
// finding the shortest path between two vertices in tree
void dfs(int s,int en){
	mark[s]=1;
	path.pb(s);
	if(s==en)
	return;
	for(int i=0;i<(int)adj[s].size();i++){
		if(!mark[adj[s][i]]){
			dfs(adj[s][i],en);
			if(path.back()==en)
			return;
		}
	}
	path.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	initialize(n);// initialize in case of multiple test cases
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int x,y;
	cin>>x>>y;
	dfs(x,y);
	for(int i=0;i<(int)path.size();i++)
	cout<<path[i]<<" ";
return 0;
}
