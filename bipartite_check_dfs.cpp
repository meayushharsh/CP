#include <bits/stdc++.h>
#define pb          push_back
#define yes         cout<<"YES"<<endl;
#define no          cout<<"NO"<<endl;
using namespace std;
// Bipartite Graph
// Can be divided into two disjoint sets such that every edge connects two vertices from different sets 
// i.e. there is no edge that connects vertices from the same set
// All cycles are of even length
// Two colorable
const int maxn=100000;
vector<int>adj[maxn+1];
int color[maxn+1];
bool is_bipartite;
void initialize(int n){
	is_bipartite=true;
	color[1]=0;
	for(int i=1;i<=n;i++){
		adj[i].clear();
		color[i]=-1;
	}
}
void dfs(int s,int p){
	int c=color[s];
	for(int i=0;i<(int)adj[s].size();i++){
		if(adj[s][i]==p)
		continue;
		if(color[adj[s][i]]==-1){
			color[adj[s][i]]=1-c;
			dfs(adj[s][i],s);
		}
		else{
			if(c==color[adj[s][i]]){
				is_bipartite=false;
				return;
			}
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
dfs(1,0);// 1 based indexing of nodes
if(is_bipartite)
yes
else
no
return 0;
}
