#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>tree[200001];
int up[200001][20];
// up[u][k] represents node (1<<k) distance upwards from u
void binary_lifting(int s,int p){
	up[s][0]=p;
	for(int i=1;i<20;i++){
		if(up[s][i-1]!=-1)
		up[s][i]=up[up[s][i-1]][i-1];
		else
		up[s][i]=-1;
	}
	for(int child:tree[s])
	if(child!=p)
	binary_lifting(child,s);
}
int query(int s,int k){
	if(s==-1 || k==0)
	return s;
	for(int i=19;i>=0;i--)
	if(k>=(1<<i))
	return query(up[s][i],k-(1<<i));
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
	tree[u].pb(v);
	tree[v].pb(u);
}
binary_lifting(1,-1);
// query(u,k) -> returns node k distance upwards from u
return 0;
}
