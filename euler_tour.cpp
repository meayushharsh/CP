// Euler Tour:
// Applications:
// - finding whether a node is ancestor of some other node
// - point update of a particular node or range update of subtree of a particular node
//   which includes segment tree and lazy propagation
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=100000;
vector<int>adj[maxn+1];
int tin[maxn+1];
int tout[maxn+1];
int timer;
void initialize(int n){
	timer=0;
	for(int i=1;i<=n;i++){
		adj[i].clear();
		tin[i]=0;
		tout[i]=0;
	}
}
void euler_tour(int s,int p){
	tin[s]=++timer;
	//cout<<s<<" ";
	for(auto x:adj[s]){
		if(x!=p){
			euler_tour(x,s);
		}
	}
	tout[s]=timer;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		int n;
		cin>>n;
		initialize(n);
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		euler_tour(1,0);
	}
}

// Inuput:
// 9
// 1 2
// 2 4
// 2 5
// 2 6
// 1 3
// 3 7
// 7 8
// 7 9
// 
// Output:
// 1 2 4 5 6 3 7 8 9