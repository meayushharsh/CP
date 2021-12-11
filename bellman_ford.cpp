#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=200000;
vector<pair<int,pair<int,int> > > edges;
int dp[maxn+1];// stores shortest distance from source to rest other vertices
void bellman_ford(int s,int n,int m){
	for(int i=1;i<=n;i++)
	dp[i]=INT_MAX;
	dp[s]=0;
	
	// relaxing each edge n-1 times
	for(int i=1;i<n;i++){
		for(int i=0;i<m;i++){
			int w=edges[i].first;
			int x=edges[i].second.first;
			int y=edges[i].second.second;
			if(dp[x]==INT_MAX)
			continue;
			if(dp[x]+w<dp[y])
			dp[y]=dp[x]+w;
		}
	}
	
	// check for neg weight cycle
	for(int i=0;i<m;i++){
		int w=edges[i].first;
		int x=edges[i].second.first;
		int y=edges[i].second.second;
		if(dp[x]==INT_MAX)
		continue;
		if(dp[x]+w<dp[y]){
			//neg weight cycle present
		}
	}
	// if dp[i]==INT_MAX , not reachable from source
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	edges.resize(m);
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		edges[i]={w,{x,y}};
	}
	int s;
	cin>>s;
	bellman_ford(s,n,m);
}