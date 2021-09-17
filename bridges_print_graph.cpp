#include <bits/stdc++.h>
#define pb push_back
using namespace std;
// 1 based indexing of nodes
const int maxn=100000;
vector<int>adj[maxn+1];
int tin[maxn+1];
int low[maxn+1];
bool mark[maxn+1];
int timer;
vector<pair<int,int> > bridges;
void initialize(int n){
	timer=0;
	bridges.clear();
	for(int i=1;i<=n;i++){
		tin[i]=0;
		low[i]=0;
		mark[i]=0;
		adj[i].clear();
	}
}
void dfs(int s,int p){
	mark[s]=1;
	tin[s]=++timer;
	low[s]=timer;
	for(int i=0;i<(int)adj[s].size();i++){
		if(adj[s][i]==p)
		continue;
		if(mark[adj[s][i]])
		low[s]=min(low[s],tin[adj[s][i]]);
		else{
			dfs(adj[s][i],s);
			if(low[adj[s][i]]>tin[s])
			bridges.pb({s,adj[s][i]});
			low[s]=min(low[s],low[adj[s][i]]);
		}
	}
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n,m;
cin>>n>>m;
initialize(n);
for(int i=1;i<=m;i++){
	int x,y;
	cin>>x>>y;
	adj[x].pb(y);
	adj[y].pb(x);
}
dfs(1,0);
for(int i=0;i<(int)bridges.size();i++)
cout<<bridges[i].first<<" "<<bridges[i].second<<"\n";
return 0;
}
