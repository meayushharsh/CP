#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Sparse_table{
	public:
	int n,m;
	vector< vector <ll> > mat_sum;
	vector<int> pw;
	Sparse_table(int n,int m){
		this->n=n;
		this->m=m;
		mat_sum.resize(n);
		pw.resize(n+1);
		for(int i=0;i<n;i++)
		mat_sum[i].resize(m);
		pw[0]=-1;
		for(int i=1;i<=n;i++)
		pw[i]=pw[i/2]+1;
	}
	void build_sum(int a[]){
		for(int i=0;i<n;i++)
		mat_sum[i][0]=a[i];
		for(int i=1;i<m;i++){
			for(int j=0;j+(1<<(i-1))<n;j++){
				mat_sum[j][i]=mat_sum[j][i-1]+mat_sum[j+(1<<(i-1))][i-1];
			}
		}
	}
	ll query_sum(int l,int r){
		if(l==r)
		return mat_sum[l][0];
		int p=pw[r-l];
		return mat_sum[l][p]+query_sum(l+(1<<p),r);
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
		st.build_sum(a);
		while(q--){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<st.query_sum(l,r)<<"\n";
		}
	}
	return 0;
}