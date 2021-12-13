#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=100000;
vector<int>adj[maxn+1];
int depth[maxn+1];
int dp[maxn+1];
set<int> ap;
void initialize(int n){
	ap.clear();
	for(int i=1;i<=n;i++){
		adj[i].clear();
		depth[i]=0;
		dp[i]=0;
	}
}
// 1 is root of dfs tree created
void dfs_articulation_point(int s,int p,int dep){
	depth[s]=dep;
	dp[s]=dep;
	int child=0;
	for(auto x:adj[s]){
		if(!depth[x]){
			dfs_articulation_point(x,s,dep+1);
			child++;
		    if(dp[x]>=depth[s] && s!=1){// there is no node above root so not including root
		    	ap.insert(s);
		    }
			dp[s]=min(dp[s],dp[x]);
		}
		else if(x!=p){
			// backedge
			dp[s]=min(dp[s],depth[x]);
		}
	}
	if(s==1 && child>1)// if root has more than one child in dfs tree it is an articulation point
	ap.insert(1);
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
		dfs_articulation_point(1,0,1);
		for(auto x:ap)
		cout<<x<<" ";
	}
}