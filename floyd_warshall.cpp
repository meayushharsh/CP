#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
void floyd_warshall(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	
	// if (dp[i][i]<0) for any i neg weight cycle is present in graph
	for(int i=1;i<=n;i++){
		if(dp[i][i]<0){
			//neg weight cycle
		}
	}
	
	// if(dp[i][j]==INT_MAX) then j is not reachable from i
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dp[i][j]=INT_MAX;
	for(int i=1;i<=n;i++)
	dp[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		dp[x][y]=w;
	}
	floyd_warshall(n);
	return 0;
}