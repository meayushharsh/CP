#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
int add(int a,int b,int m){
	int ans=(a+b)%m;
	if(ans<0)
	ans+=m;
	return ans;
}
int multiply(int a,int b,int m){
	int ans=(a*1ll*b)%m;
	if(ans<0)
	ans+=m;
	return ans;
}
int power(int a ,int b,int m)
{
    a%=m;
    int res = 1 ;
    while(b){
        if(b%2) 
        res = multiply(res,a,m);
        b/=2 ;
        a = multiply(a,a,m)%m;
    }
    return res ;
}
int maxl=1500;// set this as max length of string possible
int h1[maxl+1];
int h2[maxl+1];
int pw1[maxl+1];
int pw2[maxl+1];
int inv1[maxl+1];
int inv2[maxl+1];
int p1=31,p2=37,mod1=1000000009,mod2=1000000007;
void preprocess(string s,int l){
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=l;i++){
		pw1[i]=multiply(pw1[i-1],p1,mod1);
		pw2[i]=multiply(pw2[i-1],p2,mod2);
	}
	int pinv1=power(p1,mod1-2,mod1);
	int pinv2=power(p2,mod2-2,mod2);
	inv1[0]=inv2[0]=1;
	for(int i=1;i<=l;i++){
		inv1[i]=multiply(inv1[i-1],pinv1,mod1);
		inv2[i]=multiply(inv2[i-1],pinv2,mod2);
	}
	for(int i=0;i<l;i++){
		h1[i+1]=add(h1[i],multiply(s[i]-'a'+1,pw1[i],mod1),mod1);
		h2[i+1]=add(h2[i],multiply(s[i]-'a'+1,pw2[i],mod2),mod2);
	}
}
int hash1(int l,int r){
	int ans=add(h1[r],-h1[l-1],mod1);
	ans=multiply(ans,inv1[l],mod1);
	return ans;
}
int hash2(int l,int r){
	int ans=add(h2[r],-h2[l-1],mod2);
	ans=multiply(ans,inv2[l],mod2);
	return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t=1;
	// cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int len=s.length();
	    preprocess(s,len);
	    int ha1=hash1(l,r);//calculating hash1 of the substring(l,r) of string s , 1 based indexing 
	    int ha2=hash2(l,r);//calculating hash2 of the substring(l,r) of string s , 1 based indexing
	}
return 0;
}
