#include<bits/stdc++.h>
using namespace std;
class Sparse_table{
	public:
	int n,m;
	vector< vector <int> > mat;
	vector<int> pw;
	Sparse_table(int n,int m){
		this->n=n;
		this->m=m;
		mat.resize(n);
		pw.resize(n+1);
		for(int i=0;i<n;i++)
		mat[i].resize(m);
		pw[0]=-1;
		for(int i=1;i<=n;i++)
		pw[i]=pw[i/2]+1;
	}
	void build(int a[]){
		for(int i=0;i<n;i++)
		mat[i][0]=a[i];
		for(int i=1;i<m;i++){
			for(int j=0;j+(1<<(i-1))<n;j++){
				mat[j][i]=min(mat[j][i-1],mat[j+(1<<(i-1))][i-1]);
			}
		}
	}
	int query(int l,int r){
		if(l==r)
		return mat[l][0];
		int p=pw[r-l];
		return min(mat[l][p],mat[r-(1<<p)+1][p]);
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Sparse_table st(n,ceil(log2(n))+1);
		st.build(a);
		while(q--){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<st.query(l,r)<<"\n";
		}
	}
	return 0;
}