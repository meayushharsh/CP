#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=100000;
vector<int>adj[maxn+1];
int depth[maxn+1];
int dp[maxn+1];
vector<pair<int,int> > bridges;
void initialize(int n){
	bridges.clear();
	for(int i=1;i<=n;i++){
		adj[i].clear();
		depth[i]=0;
		dp[i]=0;
	}
}
void dfs_bridge(int s,int p,int dep){
	depth[s]=dep;
	dp[s]=dep;
	for(auto x:adj[s]){
		if(!depth[x]){
			dfs_bridge(x,s,dep+1);
			if(depth[s]<dp[x])
			bridges.pb({s,x});
			dp[s]=min(dp[s],dp[x]);
		}
		else if(x!=p){
			// backedge
			dp[s]=min(dp[s],depth[x]);
		}
	}
}
int main(){
	int t=1;
	// cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		initialize(n);
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		dfs_bridge(1,0,1);
		for(int i=0;i<(int)bridges.size();i++)
		cout<<bridges[i].first<<" "<<bridges[i].second<<endl;
	}
}