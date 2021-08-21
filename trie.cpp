#include <bits/stdc++.h>
#define pb push_back
using namespace std;
class Trie{
	public:
	Trie** children;
	bool isTerminate;
	Trie(){
		isTerminate=false;
		children=new Trie*[26];
		for(int i=0;i<26;i++)
		children[i]=NULL;
	}
};
// insert string in trie
void insert(Trie* root,string s){
	if(s==""){
		root->isTerminate=true;
		return;
	}
	int index=s[0]-'a';
	Trie* cur;
	if(root->children[index]==NULL){
		cur=new Trie();
		root->children[index]=cur;
	}
	else{
		cur=root->children[index];
	}
	insert(cur,s.substr(1));
}
// search pattern in trie
bool search(Trie* root,string s){
	if(s=="" && root->isTerminate)
	return true;
	if(s=="")
	return false;
	int index=s[0]-'a';
	if(root->children[index]==NULL)
	return false;
	return search(root->children[index],s.substr(1));
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
Trie* root=new Trie();
int n;
cin>>n;
vector<string>vec;
for(int i=0;i<n;i++){
	string s;
	cin>>s;
	vec.pb(s);
	insert(root,s);
}
string pattern;
cin>>pattern;
cout<<(search(root,pattern)?"true":"false");
return 0;
}
