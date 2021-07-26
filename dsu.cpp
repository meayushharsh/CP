#include <bits/stdc++.h>
#define pb push_back
using namespace std;
// 1 based indexing
const int maxn=100000;// max size of array possible
int arr[maxn+1];
int siz[maxn+1];// contains size of each connected component
void initialize(int n){
	for(int i=0;i<=n;i++){
		arr[i]=i;
		siz[i]=1;
	}
}
int root(int i){
	while(arr[i]!=i){
		arr[i]=arr[arr[i]];// path compression
	    i=arr[i];
    }
	return i;
}
// union of two components containing vertex a and b respectively
void we_uni(int a,int b){
	int ra=root(a);
	int rb=root(b);
	if(siz[ra]<siz[rb]){// connecting root of component with smaller size 
	    // with root of component with greater size
		arr[ra]=rb;
		siz[rb]+=siz[ra];
	}
	else{
		arr[rb]=ra;
		siz[ra]+=siz[rb];
	}
}
// checking if two vertex belongs to same component
bool fin(int a,int b){
	if(root(a)==root(b))
	return 1;
	else
	return 0;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t=1;
	// cin>>t;
	while(t--){
		int n,m;// n -> no. of vertex , m -> no. of edges
		cin>>n>>m;
		initialize(n);
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			if(!fin(x,y))
			we_uni(x,y);// connecting root of x and y if they are not already connected
		}
	}
return 0;
}
